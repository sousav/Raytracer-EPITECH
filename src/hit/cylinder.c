/*
** cylinder.c for  in /home/sousa_v/rendu/lapin/rtv2/src/hit/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Tue May  3 02:58:39 2016 Victor Sousa
** Last update Mon May 16 06:09:38 2016 Philippe Lefevre
*/

#include		"main.h"

int			hit_cylin_init(t_ray *r, t_cylin *cy,
				       double *t1, double *t2)
{
  double		a;
  double		b;
  double		c;
  double		discriminant;
  t_coord		alpha;
  t_coord		deltaP;
  t_coord		beta;

  alpha = float_time_vector(mult_vector(r->dir, cy->dir), cy->dir);
  deltaP = minus_vector(r->start, cy->center);
  beta = float_time_vector(mult_vector(deltaP, cy->dir), cy->dir);
  a = mult_vector(minus_vector(r->dir, alpha), minus_vector(r->dir, alpha));
  b = 2 * mult_vector(minus_vector(r->dir, alpha), minus_vector(deltaP, beta));
  c = mult_vector(minus_vector(deltaP, beta),
		  minus_vector(deltaP, beta)) - cy->radius * cy->radius;
  discriminant = b * b - 4 * a * c;
  if (discriminant < 0)
    return (-1);
  discriminant = sqrt(discriminant);
  *t1 = ((-1 * b) + discriminant) / (2 * a);
  *t2 = ((-1 * b) - discriminant) / (2 * a);
  return (discriminant);
}

int			hit_cylin_tx(double tx, float *t)
{
  if (tx < *t)
    {
      *t = tx;
      return (1);
    }
  return (0);
}

int 			hit_cylin(t_ray *r, t_cylin *cy, float *t,
				  double discriminant)
{
  double		t1;
  double		t2;
  t_coord		center2;

  center2 = add_vector(cy->center, float_time_vector(cy->height, cy->dir));
  if ((discriminant = hit_cylin_init(r, cy, &t1, &t2)) < 0)
    return (0);
  if (t1 < t2 && t1 >= 0.1)
    {
      if (mult_vector(cy->dir, add_vector(minus_vector(r->start, cy->center),
					  float_time_vector(t1, r->dir))) > 0 &&
	  mult_vector(cy->dir, add_vector(minus_vector(r->start, center2),
					  float_time_vector(t1, r->dir))) < 0)
	return (hit_cylin_tx(t1, t));
    }
  else if (t2 >= 0.1)
    {
      if (mult_vector(cy->dir, add_vector(minus_vector(r->start, cy->center),
					  float_time_vector(t2, r->dir))) > 0 &&
	  mult_vector(cy->dir, add_vector(minus_vector(r->start, center2),
					  float_time_vector(t2, r->dir))) < 0)
	return (hit_cylin_tx(t2, t));
    }
  return (0);
}
