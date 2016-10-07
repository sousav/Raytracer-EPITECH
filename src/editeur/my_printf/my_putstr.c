/*
** my_putstr.c for my_putstr in /home/leandr_g/rendu/Piscine_C_J04
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Oct  1 08:59:15 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:50:57 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			my_putstr_in(int fd, char *str)
{
  int			i;

  i = 0;
  if (str == NULL)
    my_putstr_in(fd, "(null)");
  else
    {
      while (str[i] != '\0')
	{
	  my_putchar_in(fd, str[i]);
	  i++;
	}
    }
}
