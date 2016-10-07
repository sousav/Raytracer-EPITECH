/*
** send_file.c for commun in /Users/leandr_g/Documents/Shared folder/testServer/commun/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun May  8 03:45:09 2016 Gaëtan Léandre
** Last update Sat May 21 23:45:44 2016 Philippe Lefevre
*/

#include		"server.h"

char			*reciv_file(SOCKET sock)
{
  char			*file;
  t_size		size;
  int			tmp;
  int			pos;

  if ((pos = recv(sock, size.csize, 4, 0)) < 0)
  {
     my_printf(2, "Erreur de réception\n");
     size.i = 0;
  }
  if (size.i == 0 || (file = malloc(size.i + 1)) == NULL)
    return (NULL);
  pos = 0 * (tmp = 1);
  while (pos < size.i && tmp > 0)
    {
      tmp = recv(sock, &file[pos], size.i, 0);
      pos += tmp;
    }
  if (tmp < 0)
    {
      my_printf(2, "Erreur de réception\n");
      return (NULL);
    }
  file[pos] = '\0';
  return (file);
}

int		send_file(SOCKET sock, char *file, int siz)
{
  t_size	size;

  size.i = siz;
  if (send(sock, size.csize, 4, 0) < 0)
    return (0);
  if (send(sock, file, size.i, 0) < 0)
    return (0);
  return (1);
}
