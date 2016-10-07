/*
** my_put_nbr.c for my_put_nbr in /home/leandr_g/rendu/j03codes/ex7
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Wed Sep 30 12:45:43 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:20:52 2016 Gaëtan Léandre
*/

#include		"main.h"

void			my_put_nbr_in(int fd, int nbr)
{
  int			mod;

  if (nbr < 0)
    {
      my_putchar_in(fd, '-');
      nbr = nbr * (-1);
    }
  if (nbr >= 0)
    {
      if (nbr >= 10)
	{
	  mod = (nbr % 10);
          nbr = (nbr - mod) / 10;
	  my_put_nbr_in(fd, nbr);
	  my_putchar_in(fd, 48 + mod);
        }
      else
        my_putchar_in(fd, 48 + nbr % 10);
    }
}
