/*
** my_printf3.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:52:38 2015 Gaëtan Léandre
** Last update Sat May 21 23:47:32 2016 Philippe Lefevre
*/

#include 		"server.h"

char			*va_my_putchar_s(va_list ap)
{
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  str = my_strcatchar(str, va_arg(ap, int));
  return (str);
}
