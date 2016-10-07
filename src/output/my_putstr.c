/*
** my_putstr.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 22:19:05 2016 victor sousa
** Last update Sun May 22 16:51:23 2016 Philippe Lefevre
*/

#include	"main.h"

int		my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
  return (0);
}
