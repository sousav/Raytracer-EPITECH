/*
** my_putnbr_base.c for my_putnbr_base in /home/leandr_g/rendu/Piscine_C_J06/ex_16
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Oct  5 13:31:52 2015 Gaëtan Léandre
** Last update Tue May 10 18:15:00 2016 Gaëtan Léandre
*/

#include 		"server.h"

static int		power_s(int nbr, int pow)
{
  int			i;
  int			copy_nbr;

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

static int		big_pow_s(int nbr, int base_size)
{
  int			i;

  i = 0;
  while (power_s(base_size, i) <= nbr)
    i++;
  i--;
  return (i);
}

char			*my_putnbr_base_s(int nbr, char *base, int taille)
{
  int			base_size;
  int			i;
  int			puissance;
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  if (nbr < 0)
    {
      str = my_strcatchar(str, '-');
      nbr = nbr * (-1);
    }
  base_size = my_strlen(base);
  i = taille >= 0 ? taille : big_pow_s(nbr, base_size);
  while (i >= 0)
    {
      puissance = nbr / power_s(base_size, i);
      str = my_strcatchar(str, base[puissance]);
      nbr = nbr - puissance * power_s(base_size, i);
      i--;
    }
  return (str);
}
