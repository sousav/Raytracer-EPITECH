/*
** my_printf3.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:52:38 2015 Gaëtan Léandre
** Last update Sun May 22 20:12:49 2016 Philippe Lefevre
*/

#include 		"server.h"

void			va_my_putchar(int fd, va_list ap)
{
  my_putchar_in(fd, va_arg(ap, int));
}
