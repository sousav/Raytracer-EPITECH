/*
** plan.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/hit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 27 16:59:30 2016 Victor Sousa
** Last update Mon May 16 19:01:17 2016 Victor Sousa
*/

#include		"main.h"

int			hit_plan(t_ray *r, t_plan *p, float *t)
{
  float			dist;
  float			denom;

  denom = mult_vector(p->dir, r->dir);
  if (denom > 0)
    {
      t_coord p0l0 = minus_vector(p->center, r->start);
      dist = mult_vector(p0l0, p->dir) / denom;
      if (dist > 0.00001 && *t > dist)
	{
          *t = dist;
          return (1);
        }
    }
  return (0);
}
