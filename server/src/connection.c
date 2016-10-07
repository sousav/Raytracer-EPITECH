/*
** connection.c for server in /Users/leandr_g/Documents/Shared folder/testServer/server_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat May  7 05:55:56 2016 Gaëtan Léandre
** Last update Sun May 22 01:18:05 2016 Philippe Lefevre
*/

#include		"server.h"

void			add_client(SOCKET sock, t_connected *co, fd_set fdset)
{
  SOCKADDR_IN		csock_addr;
  t_client		*client;
  t_client		*tmp;
  SOCKET		csock;
  socklen_t		size;

  size = sizeof(csock_addr);
  if (((csock = accept(sock, (SOCKADDR *)&csock_addr, &size)) == -1)
      || ((client = malloc(sizeof(t_client))) == NULL || co->size++ < 0))
    return;
  client->sock = csock;
  client->next = NULL;
  tmp = co->clients;
  while (tmp != NULL && tmp->next != NULL)
    tmp = tmp->next;
  client->prev = tmp;
  if (tmp == NULL)
    co->clients = client;
  else
    tmp->next = client;
  client->sock_addr = csock_addr;
  client->name = NULL;
  FD_SET(csock, &fdset);
  co->max = csock > co->max ? csock : co->max;
  my_printf(1, "Nouveau client : %s\n", inet_ntoa(csock_addr.sin_addr));
}

void			deco_client_beg(t_connected *co, t_client *client)
{
  if (client->prev == NULL)
    co->clients = client->next;
  co->size--;
  if (client->next != NULL)
    client->next->prev = client->prev;
  if (client->prev != NULL)
    client->prev->next = client->next;
}

void			deco_client(t_connected *co, t_client *client)
{
  t_client		*tmp;

  deco_client_beg(co, client);
  if (co->max == client->sock)
    {
      tmp = co->clients;
      co->max = 0;
      while (tmp)
	{
	  if (tmp->sock > co->max)
	    co->max = tmp->sock;
	  tmp = tmp->next;
	}
      co->max = (co->master && co->master->sock > co->max) ? co->master->sock
	  : co->max;
    }
  my_printf(1, "Déconnection de %s\n", client->name == NULL
	    ? inet_ntoa(client->sock_addr.sin_addr) : client->name);
  if (client->name != NULL)
    free(client->name);
  close(client->sock);
  free(client);
}

void			deco_master(t_connected *co)
{
  t_client		*tmp;

  if (co->max == co->master->sock)
    {
      tmp = co->clients;
      co->max = 0;
      while (tmp)
	{
	  if (tmp->sock > co->max)
	    co->max = tmp->sock;
	  tmp = tmp->next;
	}
    }
  my_printf(1, "Déconnection du chef de serveur : %s\n",
	 co->master->name == NULL ? inet_ntoa(co->master->sock_addr.sin_addr)
	    : co->master->name);
  close(co->master->sock);
  free(co->master);
  co->master = NULL;
}
