/*
** my_put_nbr.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Tue Mar  8 22:18:46 2016 victor sousa
** Last update Tue Mar  8 22:18:55 2016 victor sousa
*/

#include	"main.h"

int		my_put_nbr(int nbr)
{
  if (nbr < -2147483647)
    {
      write(1, "-2147483648", 11);
      return (1);
    }
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar(45);
    }
  if (nbr >= 10)
      my_put_nbr(nbr / 10);
  my_putchar(nbr % 10 + 48);
  return (0);
}
