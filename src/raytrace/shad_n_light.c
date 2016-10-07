/*
** shad_n_light.c for raytracing in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Fri Mar 11 04:01:20 2016 victor sousa
** Last update Sat May 21 02:20:20 2016 Philippe Lefevre
*/

#include		"main.h"

int                     process_light(t_prog *prog, t_raycast *rcast)
{
  rcast->dist_vector = minus_vector(rcast->light_list->center,
                                    rcast->new_point);
  if (mult_vector(rcast->dist_vector, rcast->normale) <= 0.0)
    {
      rcast->light_list = rcast->light_list->next;
      return (-1);
    }
  rcast->dist = sqrt(mult_vector(rcast->dist_vector, rcast->dist_vector));
  if (rcast->dist <= 0.0)
    {
      rcast->light_list = rcast->light_list->next;
      return (-1);
    }
  rcast->light_ray.start = rcast->new_point;
  rcast->light_ray.dir = float_time_vector((1.0 / rcast->dist),
                                           rcast->dist_vector);
  process_shadow(prog, rcast);
  rcast->light_list = rcast->light_list->next;
  return (0);
}
