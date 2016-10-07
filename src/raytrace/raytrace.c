/*
** raytrace.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Fri Mar 11 01:01:17 2016 victor sousa
** Last update Sat May 21 17:42:09 2016 Philippe Lefevre
*/

#include		"main.h"

void			init_ray(t_bunny_position *win_size, t_ray *ray,
				 t_coord *pos, t_prog *prog)
{
  t_coord		point;
  t_coord 		ang;

  ray->start.x = prog->cam_pos.x;
  ray->start.y = prog->cam_pos.y;
  ray->start.z = prog->cam_pos.z;
  ang.x = prog->cam_rot.x - (float)((float)prog->cam_fov.x /
			     (float)win_size->x) * (float)(pos->x -
			     (float)win_size->x / 2.0);
  ang.y = prog->cam_rot.y - (float)((float)prog->cam_fov.y /
			     (float)win_size->y) * (float)(pos->y -
			     (float)win_size->y / 2.0);
  point.x = ray->start.x + cos(DTR(ang.x));
  point.y = ray->start.y + sin(DTR(ang.y));
  point.z = ray->start.z + sin(DTR(ang.x));
  ray->dir = normalize(minus_vector(point, ray->start));
}

t_color			raytrace_loop(t_prog *prog,
				      t_raycast *rcast,
				      t_bunny_position pos)
{
  rcast->depth = 0;
  rcast->coef = 1.0f;
  rcast->out_col = prog->background->color[pos.y][pos.x];
  rcast->mat_touch = NULL;
  while ((rcast->coef > 0.0f) && (rcast->depth < MAX_DEPTH))
      if (reflect_loop(prog, rcast) == -1)
	{
	  rcast->depth = MAX_DEPTH;
	}
  return (rcast->out_col);
}

unsigned int		calcul_pixel(t_prog *prog,
				     t_raycast raycast,
				     t_bunny_position pos)
{
  t_color		col;
  t_coord		alias_pos;
  int			i_cmp;

  col.full = 0xFF000000;
  alias_pos.y = pos.y - 1;
  while (++alias_pos.y < pos.y + prog->anti_alias)
    {
      alias_pos.x = pos.x - 1;
      while (++alias_pos.x < pos.x + prog->anti_alias)
	{
	  init_ray(&prog->win_size, &raycast.ray, &alias_pos, prog);
	  raytrace_loop(prog, &raycast, pos);
	  if (alias_pos.x == pos.x && alias_pos.y == pos.y)
	    col = raycast.out_col;
	  else
	    {
	      i_cmp = -1;
	      while (++i_cmp < 3)
		col.argb[i_cmp] =
		  col.argb[i_cmp] / 2 + raycast.out_col.argb[i_cmp] / 2;
	    }
	}
    }
  return (col.full);
}

int			raytrace(t_prog *prog)
{
  t_bunny_position      pos;
  t_raycast		raycast;
  t_color		pixel_color;

  my_putstr("\nRaytracing started\n");
  raycast.touch_circle = 0;
  pos.y = -1;
  while (++pos.y < prog->win_size.y)
    {
      pos.x = -1;
      while (++pos.x < prog->win_size.x)
	{
	  pixel_color.full = calcul_pixel(prog, raycast, pos);
	  tekpixel(prog->pix, &pos, &pixel_color);
	}
    }
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &pos);
  bunny_display(prog->win);
  my_putstr("Raytracing successfull\n");
  return (0);
}
