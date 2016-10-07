/*
** my_putnbr_base.c for my_putnbr_base in /home/leandr_g/rendu/Piscine_C_J06/ex_16
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Oct  5 13:31:52 2015 Gaëtan Léandre
** Last update Wed May  4 04:21:20 2016 Gaëtan Léandre
*/

#include 		"main.h"

static unsigned int	power_u_s(unsigned int nbr, int pow)
{
  int			i;
  unsigned int		copy_nbr;

  copy_nbr = nbr;
  i = 1;
  if (pow == 0)
    return (1);
  while (i < pow)
    {
      nbr = nbr * copy_nbr;
      i++;
    }
  return (nbr);
}

static int		big_pow_u_s(unsigned int nbr, int base_size)
{
  int			i;

  i = 0;
  while (power_u_s(base_size, i) <= nbr)
    i++;
  i--;
  return (i);
}

char			*my_putnbr_base_u_s(unsigned int nbr, char *base)
{
  int			base_size;
  int			i;
  int			puissance;
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  base_size = my_strlen(base);
  i = big_pow_u_s(nbr, base_size);
  while (i >= 0)
    {
      puissance = nbr / power_u_s(base_size, i);
      str = my_strcatchar(str, base[puissance]);
      nbr = nbr - puissance * power_u_s(base_size, i);
      i--;
    }
  return (str);
}
