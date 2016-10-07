/*
** obj_calculs.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Mar 13 20:30:25 2016 victor sousa
** Last update Sat May 21 02:14:26 2016 Philippe Lefevre
*/

#include		"main.h"

void			calc_sphere_normale_bis(t_raycast *rcast,
						t_normal_sphere sphere)
{
  sphere.phi = acos(-mult_vector(sphere.vn, sphere.vp));
  sphere.v = sphere.phi / M_PI;
  sphere.theta = (acos(mult_vector(sphere.vp, sphere.ve)
		       / sin(sphere.phi))) / (2.0 * M_PI);
  if (sphere.vp.z < 0.0005 && sphere.vp.z > -0.0005)
    sphere.theta = 0;
  if (mult_vector(crossProduct(sphere.vn, sphere.ve), sphere.vp) > 0)
    sphere.u = sphere.theta;
  else
    sphere.u = 1 - sphere.theta;
  sphere.v = sphere.v * (float)rcast->mat_touch->texture->height;
  sphere.u = sphere.u * (float)rcast->mat_touch->texture->width;
  if (sphere.v >= rcast->mat_touch->texture->height)
    sphere.v = 1;
  if (sphere.u >= rcast->mat_touch->texture->width)
    sphere.u = 1;
  rcast->mat_touch->color =
  rcast->mat_touch->texture->color[(int)sphere.v][(int)sphere.u];
}

void			calc_sphere_normale(t_prog *prog, t_raycast *rcast)
{
  t_normal_sphere	sphere;

  rcast->sphere = rcast->obj_touch->obj;
  rcast->mat_touch = get_color(rcast->sphere->material, prog->mat_list);
  rcast->new_point = add_vector(rcast->ray.start,
				float_time_vector(rcast->dist,
						  rcast->ray.dir));
  rcast->normale = minus_vector(rcast->new_point, rcast->sphere->center);
  sphere.vn.x = 0;
  sphere.vn.y = - 1;
  sphere.vn.z = 0;
  sphere.vn = normalize(sphere.vn);
  sphere.ve.x = -1;
  sphere.ve.y = 0;
  sphere.ve.z = 0;
  sphere.ve = normalize(sphere.ve);
  sphere.vp = minus_vector(rcast->new_point, rcast->sphere->center);
  sphere.vp = normalize(sphere.vp);
  if (!my_strstr(rcast->mat_touch->texture_path, "NULL"))
    calc_sphere_normale_bis(rcast, sphere);
}
