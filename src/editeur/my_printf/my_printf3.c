/*
** my_printf3.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:52:38 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:47:16 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			va_my_octal(int fd, va_list ap)
{
  my_putnbr_base_in(fd, va_arg(ap, int), "01234567", -1);
}

void			va_my_examin(int fd, va_list ap)
{
  my_putnbr_base_in(fd, va_arg(ap, int), "0123456789abcdef", -1);
}

void			va_my_examaj(int fd, va_list ap)
{
  my_putnbr_base_in(fd, va_arg(ap, int), "0123456789ABCDEF", -1);
}

void			va_my_adress(int fd, va_list ap)
{
  if (ap != NULL)
    {
      my_putstr_in(fd, "0x");
      my_putnbr_base_add_in(fd, va_arg(ap, size_t), "0123456789abcdef", -1);
    }
  else
    my_putstr_in(fd, "(null)");
}

void			va_my_bin(int fd, va_list ap)
{
  my_putnbr_base_u_in(fd, va_arg(ap, unsigned int), "01");
}
