/*
** my_put_fnbr.c for printf in /Users/leandr_g/Documents/Shared folder/Raytracer/src/editeur/my_printf/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 26 02:29:07 2016 Gaëtan Léandre
** Last update Wed May  4 03:37:49 2016 Gaëtan Léandre
*/

#include		"main.h"

char			*my_put_fnbr_s(float nbr)
{
  int			i;
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  i = 0;
  str = my_strcatprint(str, my_put_nbr_s((int)nbr));
  nbr -= (int)nbr;
  str = my_strcatchar(str, '.');
  while (i < 5)
    {
      nbr *= 10.0;
      str = my_strcatchar(str, 48 + (int)nbr);
      nbr -= (int)nbr;
      i++;
    }
  return (str);
}
