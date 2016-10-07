/*
** reciv_img.c for server in /Users/leandr_g/Documents/Shared folder/testServer/server_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun May  8 02:00:53 2016 Gaëtan Léandre
** Last update Sun May 22 20:07:37 2016 Philippe Lefevre
*/

#include		"server.h"

void			fill_end(t_client *client, unsigned int *tmp,
				 t_connected *co)
{
  int			x;
  int			y;
  int			pos;

  y = 0;
  while (y < co->height)
    {
      x = 0;
      pos = client->start_x;
      while (pos < client->end_x)
	{
	  if (tmp == NULL)
	    co->end[pos + co->width * y] = COLOR_DEF;
	  else
	    co->end[pos + co->width * y] = tmp[x + y
	      * (client->end_x - client->start_x)];
	  pos++;
	  x++;
	}
      y++;
    }
  if (tmp != NULL)
    free(tmp);
}

void			recive_img_sock(t_connected *co, t_client *client,
					fd_set *fdset)
{
  int			tmp;

  if (FD_ISSET(client->sock, fdset))
    {
      if (client->grille != NULL)
	{
	  tmp = recv(client->sock, &(client->grille)[client->pos],
		     client->wait - client->pos, 0);
	  client->pos += tmp >= 0 ? tmp : 0;
	}
      if (client->wait <= client->pos && client->done != 1)
	{
	  fill_end(client, (unsigned int *)client->grille, co);
	  client->done = 1;
	}
      else if (tmp <= 0 && client->done != 1)
	{
	  fill_end(client, NULL, co);
	  client->done = -1;
	}
    }
}

int			test_done(t_connected *co)
{
  t_client		*tmp;

  if (co->master->done == 0)
    return (0);
  tmp = co->clients;
  while (tmp)
    {
      if (tmp->done == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}
