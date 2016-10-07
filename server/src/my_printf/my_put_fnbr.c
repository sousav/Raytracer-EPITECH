/*
** my_put_fnbr.c for printf in /Users/leandr_g/Documents/Shared folder/Raytracer/src/editeur/my_printf/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 26 02:29:07 2016 Gaëtan Léandre
** Last update Tue May 10 23:34:09 2016 Gaëtan Léandre
*/

#include		"server.h"

void			my_put_fnbr_in(int fd, float nbr)
{
  int			i;

  i = 0;
  my_put_nbr_in(fd, (int)nbr);
  nbr -= (int)nbr;
  my_putchar_in(fd, '.');
  while (i < 5)
    {
      nbr *= 10.0;
      my_putchar_in(fd, 48 + (int)nbr);
      nbr -= (int)nbr;
      i++;
    }
}
