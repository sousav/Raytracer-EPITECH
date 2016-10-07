/*
** load_screen.c for Raytrace in /home/lefevr_h/Workspace/Github/Raytracer/src/loading/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Thu May 12 12:11:50 2016 Philippe Lefevre
** Last update Sun May 22 16:30:43 2016 Philippe Lefevre
*/

#include		"main.h"

int			waiting_screen(t_prog *prog)
{
  t_bunny_position      pos;
  t_color		pixel_color;

  pixel_color.full = WAITING_COLOR;
  pos.y = -1;
  while (++pos.y < prog->win_size.y)
    {
      pos.x = -1;
      while (++pos.x < prog->win_size.x)
	tekpixel(prog->pix, &pos, &pixel_color);
    }
  return (0);
}
