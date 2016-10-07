/*
** my_strlen.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Tue Mar  8 22:19:31 2016 victor sousa
** Last update Tue Mar  8 22:19:42 2016 victor sousa
*/

#include	"main.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
