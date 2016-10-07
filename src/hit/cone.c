/*
** cone.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/hit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 29 05:28:00 2016 Victor Sousa
** Last update Sat May 21 00:29:04 2016 Philippe Lefevre
*/

#include		"main.h"

int			hit_circle(t_ray *r, t_circle *c, float *t)
{
  float			dist;

  dist = *t;
  if (hit_plan(r, &c->plan, &dist))
    {
      t_coord p = add_vector(r->start, float_time_vector(dist, r->dir));
      t_coord v = minus_vector(p, c->plan.center);
      float d2 = mult_vector(v, v);
      if (d2 < c->radius * c->radius)
	{
	  if (dist < *t)
	    {
      	      *t = dist;
	      return (1);
	    }
	}
    }
  return (0);
}

int			hit_cone_dist(double dist[2], t_ray *r,
				      t_cone *c, float *t)
{
  t_coord		temp;

  if (dist[1] < dist[0] && dist[1] > 0.1)
    {
      temp = add_vector(r->start, float_time_vector(dist[1], r->dir));
      if (temp.y <= c->height && temp.y >= 0.0 && dist[1] < *t)
	{
	  *t = dist[1];
	  return (1);
	}
    }
  else if (dist[1] > dist[0] && dist[0] > 0.1)
    {
      temp = add_vector(r->start, float_time_vector(dist[0], r->dir));
      if (temp.y <= c->height && temp.y >= 0.0 && dist[0] < *t)
	{
	  *t = dist[0];
	  return (1);
	}
    }
  return (0);
}

int			hit_cone(t_ray *r, t_cone *c, float *t)
{
  double 		dist[2];
  double		fac;
  t_coord		x;
  t_coord		y;
  double		d;

  fac = (c->radius * c->radius) / (double) (c->height * c->height);
  y.x = (fac) * r->dir.y * r->dir.y;
  y.y = (2.0 * fac * r->start.y * r->dir.y) - (2.0 * (c->radius * c->radius)
					       / c->height) * r->dir.y;
  y.z = (fac * r->start.y * r->start.y) - ((2.0 * (c->radius * c->radius)
					    / c->height) * r->start.y)
    +  (c->radius * c->radius);
  x.x = (r->dir.x * r->dir.x) + (r->dir.z * r->dir.z) - y.x;
  x.y = (2.0 * r->start.x * r->dir.x) + (2.0 * r->start.z * r->dir.z) - y.y;
  x.z = (r->start.x * r->start.x) + (r->start.z * r->start.z) - y.z;
  d = (x.y * x.y) - (4.0 * x.x * x.z);
  if (d >= 0)
    {
      dist[0] = (-x.y - sqrt(d)) / (2.0 * x.x);
      dist[1] = (-x.y + sqrt(d)) / (2.0 * x.x);
      return (hit_cone_dist(dist, r, c, t));
    }
  return (0);
}
