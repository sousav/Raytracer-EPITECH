/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Wed May  4 04:25:14 2016 Gaëtan Léandre
*/

#include		"main.h"

char			*my_put_nbr_s(int nbr)
{
  int			mod;
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  if (nbr < 0)
    {
      str = my_strcatchar(str, '-');
      nbr = nbr * (-1);
    }
  if (nbr >= 0)
    {
      if (nbr >= 10)
	{
	  mod = (nbr % 10);
          nbr = (nbr - mod) / 10;
	  str = my_strcatprint(str, my_put_nbr_s(nbr));
	  str = my_strcatchar(str, 48 + mod);
        }
      else
        str = my_strcatchar(str, 48 + nbr % 10);
    }
  return (str);
}
