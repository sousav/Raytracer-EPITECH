/*
** my_printf2.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:51:48 2015 Gaëtan Léandre
** Last update Sat May 21 23:46:52 2016 Philippe Lefevre
*/

#include 		"server.h"

char			*va_my_putstr_s(va_list ap)
{
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  str = my_strcatnofree(str, va_arg(ap, char*));
  return (str);
}

char			*va_my_putnbr_s(va_list ap)
{
  return (my_put_nbr_s(va_arg(ap, int)));
}

char			*va_my_putunbr_s(va_list ap)
{
  return (my_put_unbr_s(va_arg(ap, unsigned int)));
}

char			*va_my_disp_unp_s(va_list ap)
{
  return (disp_unprintable_s(va_arg(ap, char*)));
}

char			*va_my_putfnbr_s(va_list ap)
{
  return (my_put_fnbr_s(va_arg(ap, double)));
}
