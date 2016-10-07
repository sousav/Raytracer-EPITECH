/*
** end.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 03:36:42 2016 victor sousa
** Last update Mon May 16 18:47:11 2016 Philippe Lefevre
*/

#include	"main.h"

void		free_stuff(t_prog *prog)
{
  free(prog->opt);
  bunny_delete_clipable(&prog->pix->clipable);
  bunny_stop(prog->win);
}
