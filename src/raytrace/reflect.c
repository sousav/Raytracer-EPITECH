/*
** reflect.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Fri Mar 11 04:04:48 2016 victor sousa
** Last update Mon May 16 08:15:43 2016 Philippe Lefevre
*/

#include		"main.h"

void                    process_reflect(t_raycast *rcast)
{
  rcast->coef = rcast->coef * (rcast->mat_touch->reflect / 100.0);
  rcast->reflect = 2.0 * mult_vector(rcast->ray.dir, rcast->normale);
  rcast->ray.start = rcast->new_point;
  rcast->ray.dir = minus_vector(rcast->ray.dir,
				float_time_vector(rcast->reflect,
						  rcast->normale));
  rcast->depth++;
}

int			reflect_touch_sky(t_raycast *rcast, int i_cmp)
{
  if (rcast->mat_touch->sky == 1)
    {
      i_cmp = -1;
      while (++i_cmp < 3)
	rcast->out_col.argb[i_cmp] = rcast->out_col.argb[i_cmp]
	  * (1 - rcast->coef) + rcast->mat_touch->color.argb[i_cmp]
      * rcast->coef;
      rcast->out_col.argb[ALPHA_CMP] = 255;
      process_reflect(rcast);
      return (1);
    }
  return (0);
}

int                     reflect_loop(t_prog *prog, t_raycast *rcast)
{
  float			tmp;

  rcast->dist = 2000000;
  if ((rcast->obj_touch = hit(prog->obj_list,
			      &rcast->ray, &rcast->dist)) == NULL
      || rcast->obj_touch->obj == NULL)
    return (-1);
  if (rcast->depth == 0 && rcast->coef == 1.0)
    rcast->out_col.full = 0xFF000000;
  if (calc_normale(prog, rcast) == -1)
    return (-1);
  tmp = mult_vector(rcast->normale, rcast->normale);
  if (tmp == 0.0)
    return (-1);
  free(rcast->obj_touch);
  tmp = 1.0 / sqrt(tmp);
  rcast->normale = float_time_vector(tmp, rcast->normale);
  if (reflect_touch_sky(rcast, 0))
    return (0);
  rcast->light_list = prog->light_list;
  while (rcast->light_list != NULL)
    process_light(prog, rcast);
  process_reflect(rcast);
  return (0);
}
