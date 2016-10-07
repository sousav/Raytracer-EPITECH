/*
** my_printf2.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:51:48 2015 Gaëtan Léandre
** Last update Mon May 16 07:58:04 2016 Philippe Lefevre
*/

#include 		"main.h"

void			va_my_putchar(int fd, va_list ap)
{
  my_putchar_in(fd, va_arg(ap, int));
}

void			va_my_putstr(int fd, va_list ap)
{
  my_putstr_in(fd, va_arg(ap, char*));
}

void			va_my_putnbr(int fd, va_list ap)
{
  my_put_nbr_in(fd, va_arg(ap, int));
}

void			va_my_putunbr(int fd, va_list ap)
{
  my_put_unbr_in(fd, va_arg(ap, unsigned int));
}

void			va_my_disp_unp(int fd, va_list ap)
{
  disp_unprintable_in(fd, va_arg(ap, char*));
}
