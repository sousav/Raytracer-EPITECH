/*
** my_tablen.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Tue Feb  9 05:39:10 2016 victor sousa
** Last update Fri Mar 11 00:09:59 2016 victor sousa
*/

#include	"main.h"

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
