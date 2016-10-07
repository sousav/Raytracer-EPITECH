/*
** main.c for reseau in /Users/leandr_g/Documents/Shared folder/testServer/client_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu May  5 00:03:54 2016 Gaëtan Léandre
** Last update Sun May 22 20:10:02 2016 Philippe Lefevre
*/

#include		"server.h"

SOCKET			init_connection()
{
  SOCKET		sock;
  SOCKADDR_IN		sock_addr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      my_printf(2, "Erreur de socket\n");
      return (-1);
    }
  sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  sock_addr.sin_port = htons(PORT);
  sock_addr.sin_family = AF_INET;
  if (bind(sock, (SOCKADDR*)&sock_addr, sizeof(sock_addr)) == -1)
    {
      my_printf(2, "Erreur dans le linkage de la socket\n");
      return (-1);
    }
  else if (listen(sock, MAX_CLIENTS) == -1)
    {
      my_printf(2, "Erreur dans l'attente\n");
      return (-1);
    }
  return (sock);
}

void			end_co(t_connected *co)
{
  t_client		*tmp;

  if (co->master != NULL)
    {
      if (co->master->name)
	free(co->master->name);
      close(co->master->sock);
      free(co->master);
    }
  tmp = co->clients;
  while (co->clients != NULL)
    {
      tmp = co->clients;
      if (tmp->name)
	free(tmp->name);
      co->clients = co->clients->next;
      close(tmp->sock);
      free(tmp);
    }
}

int			main()
{
  SOCKET		sock;
  t_connected		connected;

  if ((sock = init_connection()) == -1)
    return (-1);
  init_connected(&connected, sock);
  while (connected.status != -1)
    {
      get_connections(sock, &connected);
      if (connected.status == 1)
	{
	  recive_and_launch(&connected);
	  if (connected.status != 0)
	    {
	      charge_server(&connected);
	      reciv_img(&connected);
	    }
	  connected.status = 0;
	}
    }
  if (connected.end != NULL)
    free(connected.end);
  end_co(&connected);
  close(sock);
  return (0);
}
