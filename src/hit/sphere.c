/*
** sphere.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 22:31:26 2016 victor sousa
** Last update Thu May  5 07:39:01 2016 Victor Sousa
*/

#include		"main.h"

t_mat_list		*get_color(int mat_id, t_mat_list *mat)
{
  t_mat_list		*tmp;

  tmp = mat;
  while (tmp != NULL)
    {
      if (tmp->id == mat_id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

int			hit_sphere(t_ray *r, t_sphere *s, float *t)
{
  t_coord		dist;
  float			B;
  float			delta;
  float			t0;
  float			t1;

  dist = minus_vector(s->center, r->start);
  B = mult_vector(r->dir, dist);
  delta = B * B - mult_vector(dist, dist) + s->radius * s->radius;
  if (delta < 0)
    return (0);
  t0 = B - sqrt(delta);
  t1 = B + sqrt(delta);
  if (t0 < t1 && (t0 > 0.1) && (t0 < *t))
    {
      *t = t0;
      return (1);
    }
  else if ((t1 > 0.1) && (t1 < *t))
    {
      *t = t1;
      return (1);
    }
  return (0);
}
