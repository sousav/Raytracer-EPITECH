/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Wed May  4 02:44:11 2016 Gaëtan Léandre
*/

#include 		"main.h"

char			*my_put_unbr_s(unsigned int nbr)
{
  int			i;
  int			number;
  int			first;
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  first = 0;
  i = 1000000000;
  if (nbr == 0)
    str = my_strcatchar(str, '0');
  while (i > 0)
    {
      number = nbr / i;
      if (number != 0 || first != 0)
	{
	  str = my_strcatchar(str, number + 48);
	  nbr = nbr % i;
	  first = 1;
	}
      i = i / 10;
    }
  return (str);
}
