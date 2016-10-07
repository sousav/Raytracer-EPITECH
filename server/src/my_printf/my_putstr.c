/*
** my_putstr.c for my_putstr in /home/leandr_g/rendu/Piscine_C_J04
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Oct  1 08:59:15 2015 Gaëtan Léandre
** Last update Tue May 10 23:34:42 2016 Gaëtan Léandre
*/

#include 		"server.h"

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
