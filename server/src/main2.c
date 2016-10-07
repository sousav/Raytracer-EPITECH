/*
** main.c for reseau in /Users/leandr_g/Documents/Shared folder/testServer/client_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu May  5 00:03:54 2016 Gaëtan Léandre
** Last update Sun May 22 20:09:36 2016 Philippe Lefevre
*/

#include		"server.h"

int			action_master(t_connected *co, fd_set fdset)
{
  char			buffer[BUF_SIZE + 1];
  int			size;
  char			**tab;
  char			*str;

  if (co->master && FD_ISSET(co->master->sock, &fdset))
    {
      if ((size = read_client(co->master->sock, buffer)) == 0)
	deco_master(co);
      else if ((tab = is_command(buffer)))
	launch_command_client(co->master->sock, tab, co);
      else if (co->master->name != NULL)
	if ((str = my_sprintf("\033[34m<%s> : %s\033[0m",
			      co->master->name, buffer)) != NULL)
	  {
	    my_printf(1, "%s\n", str);
	    write_all_client(co, str, co->master->sock);
	    free(str);
	  }
    }
  else
    return (0);
  return (1);
}

void			action_client_bis(t_client *tmp, char buffer[],
					  t_connected *co)
{
  char			*str;

  str = my_sprintf("<%s> : %s", tmp->name, buffer);
  if (str != NULL)
    {
      my_printf(1, "%s\n", str);
      write_all_client(co, str, tmp->sock);
      free(str);
    }
}

void			action_client(t_connected *co, fd_set fdset)
{
  t_client		*tmp;
  char			buffer[BUF_SIZE + 1];
  int			size;
  char			**tab;

  tmp = co->clients;
  if (action_master(co, fdset) == 1)
    return;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->sock, &fdset))
	{
	  if ((size = read_client(tmp->sock, buffer)) == 0)
	    deco_client(co, tmp);
	  else if ((tab = is_command(buffer)))
	    launch_command_client(tmp->sock, tab, co);
	  else if (tmp->name != NULL)
	    action_client_bis(tmp, buffer, co);
	  return;
	}
      tmp = tmp->next;
    }
}

void			get_connections(SOCKET sock, t_connected *co)
{
  t_client		*tmp;
  fd_set		fdset;

  while (co->status == 0)
    {
      FD_ZERO(&fdset);
      FD_SET(STDIN_FILENO, &fdset);
      FD_SET(sock, &fdset);
      tmp = co->clients;
      while (tmp != NULL)
	{
	  FD_SET(tmp->sock, &fdset);
	  tmp = tmp->next;
	}
      if (co->master != NULL)
	FD_SET(co->master->sock, &fdset);
      if (select(co->max + 1, &fdset, NULL, NULL, NULL) == -1)
	return;
      if (FD_ISSET(STDIN_FILENO, &fdset))
	exec_command(co);
      else if (FD_ISSET(sock, &fdset))
	add_client(sock, co, fdset);
      else
	action_client(co, fdset);
    }
}

void			init_connected(t_connected *co, SOCKET sock)
{
  co->size = 0;
  co->max = sock;
  co->clients = NULL;
  co->master = NULL;
  co->end = NULL;
  co->status = 0;
}
