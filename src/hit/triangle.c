/*
** triangle.c for  in /home/sousa_v/rendu/lapin/raytracer_temp/src/hit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 25 04:34:58 2016 Victor Sousa
** Last update Fri May 20 23:39:17 2016 Philippe Lefevre
*/

#include		"main.h"

int			hit_triangle(t_ray *r, t_triangle *tr, float *old_dist)
{
  t_hit_triangle	t_tri;

  t_tri.e1 = minus_vector(tr->angle[1], tr->angle[0]);
  t_tri.e2 = minus_vector(tr->angle[2], tr->angle[0]);
  t_tri.h = crossProduct(r->dir, t_tri.e2);
  t_tri.a = mult_vector(t_tri.e1, t_tri.h);
  if (t_tri.a > -0.01 && t_tri.a < 0.01)
    return (0);
  t_tri.f = 1 / t_tri.a;
  t_tri.s = minus_vector(r->start, tr->angle[0]);
  t_tri.u = t_tri.f * (mult_vector(t_tri.s, t_tri.h));
  if (t_tri.u < 0.0 || t_tri.u > 1.0)
    return (0);
  t_tri.q = crossProduct(t_tri.s, t_tri.e1);
  t_tri.v = t_tri.f * mult_vector(r->dir, t_tri.q);
  if (t_tri.v < 0.0 || t_tri.u + t_tri.v > 1.0)
    return (0);
  t_tri.t = t_tri.f * mult_vector(t_tri.e2, t_tri.q);
  if (t_tri.t > 0.1 && *old_dist > t_tri.t)
    {
      *old_dist = t_tri.t;
      return (1);
    }
  return (0);
}
