/*
** obj_calculs.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Mar 13 20:30:25 2016 victor sousa
** Last update Sat May 21 00:36:05 2016 Philippe Lefevre
*/

#include		"main.h"

void			calc_triangle_normale(t_prog *prog, t_raycast *rcast)
{
  t_coord 		e1;
  t_coord 		e2;
  t_coord 		h;

  rcast->triangle = rcast->obj_touch->obj;
  rcast->mat_touch = get_color(rcast->triangle->material,
				      prog->mat_list);
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));
  e1 = minus_vector(rcast->triangle->angle[1], rcast->triangle->angle[0]);
  e2 = minus_vector(rcast->triangle->angle[2], rcast->triangle->angle[0]);
  h = crossProduct(e2, e1);
  if (h.x >= 0 || h.y >= 0 || h.z >= 0)
    h = crossProduct(e1, e2);
  rcast->normale = h;
}

void			calc_plan_normale(t_prog *prog, t_raycast *rcast)
{
  t_coord		dist_to_center;

  rcast->plan = rcast->obj_touch->obj;
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));
  rcast->normale.x = -rcast->plan->dir.x;
  rcast->normale.y = -rcast->plan->dir.y;
  rcast->normale.z = -rcast->plan->dir.z;
  dist_to_center = minus_vector(rcast->new_point, rcast->plan->center);
  if (damier(&dist_to_center) == 0)
    rcast->mat_touch = get_color(rcast->plan->material, prog->mat_list);
  else
    rcast->mat_touch = get_color(rcast->plan->material2, prog->mat_list);
}

void			calc_cone_normale(t_prog *prog, t_raycast *rcast)
{
  t_coord		top;
  t_coord		perp;

  rcast->cone = rcast->obj_touch->obj;
  rcast->mat_touch = get_color(rcast->cone->material, prog->mat_list);
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));

  top = add_vector(rcast->cone->center, float_time_vector(rcast->cone->height,
							  rcast->cone->dir));
  perp = crossProduct(rcast->cone->dir, minus_vector(rcast->new_point, top));
  rcast->normale = normalize(crossProduct(minus_vector(rcast->new_point, top),
					  perp));
}

void			calc_cyl_normale(t_prog *prog, t_raycast *rcast)
{
  t_coord		co;

  rcast->cyl = rcast->obj_touch->obj;
  rcast->mat_touch = get_color(rcast->cyl->material, prog->mat_list);
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));
  co = minus_vector(rcast->new_point, rcast->cyl->center);
  rcast->normale =
  minus_vector(co, (float_time_vector((mult_vector(co, rcast->cyl->dir) /
				       mult_vector(rcast->cyl->dir,
						   rcast->cyl->dir)),
				      rcast->cyl->dir)));
}

void			calc_circle_normale(t_prog *prog, t_raycast *rcast)
{
  rcast->circle = rcast->obj_touch->obj;
  rcast->mat_touch = get_color(rcast->circle->material, prog->mat_list);
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));
  rcast->normale = rcast->circle->plan.dir;
}
