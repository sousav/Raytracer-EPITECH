/*
** my_putchar.c for my_putchar in /home/leandr_g/rendu/Piscine_C_J07/lib/my
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Tue Oct  6 10:35:20 2015 Gaëtan Léandre
** Last update Sat Apr 16 06:51:27 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			my_putchar_in(int fd, char c)
{
  write(fd, &c, 1);
}
