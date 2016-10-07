/*
** my_printf3.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:52:38 2015 Gaëtan Léandre
** Last update Wed May  4 04:20:21 2016 Gaëtan Léandre
*/

#include 		"main.h"

char			*va_my_octal_s(va_list ap)
{
  return (my_putnbr_base_s(va_arg(ap, int), "01234567", -1));
}

char			*va_my_examin_s(va_list ap)
{
  return (my_putnbr_base_s(va_arg(ap, int), "0123456789abcdef", -1));
}

char			*va_my_examaj_s(va_list ap)
{
  return (my_putnbr_base_s(va_arg(ap, int), "0123456789ABCDEF", -1));
}

char			*va_my_adress_s(va_list ap)
{
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  if (ap != NULL)
    {
      str = my_strcatnofree(str, "0x");
      str = my_strcatprint(str,
			   my_putnbr_base_add_s(va_arg(ap, size_t),
						 "0123456789abcdef", -1));
    }
  else
    str = my_strcatnofree(str, "(null)");
  return (str);
}

char			*va_my_bin_s(va_list ap)
{
  return (my_putnbr_base_u_s(va_arg(ap, unsigned int), "01"));
}
