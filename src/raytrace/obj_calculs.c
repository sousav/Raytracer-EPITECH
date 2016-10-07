/*
** obj_calculs.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Mar 13 20:30:25 2016 victor sousa
** Last update Sat May 21 01:38:14 2016 Philippe Lefevre
*/

#include		"main.h"
pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

double			noise(double x, double y, double z)
{
  t_noise		noise;
  int			p[512];

  noise_init(p);
  noise.X = (int)floor(x) & 255;
  noise.Y = (int)floor(y) & 255;
  noise.Z = (int)floor(z) & 255;
  x -= floor(x);
  y -= floor(y);
  z -= floor(z);
  noise.u = fade(x);
  noise.v = fade(y);
  noise.w = fade(z);
  noise.A = p[noise.X] + noise.Y;
  noise.AA = p[noise.A] + noise.Z;
  noise.AB = p[noise.A + 1] + noise.Z;
  noise.B = p[noise.X + 1] + noise.Y;
  noise.BA = p[noise.B] + noise.Z;
  noise.BB = p[noise.B + 1] + noise.Z;
  noise.p = p;
  return (noise_end(noise, x, y, z));
}

int 			calc_normale_beg(t_prog *prog, t_raycast *rcast,
					 t_coord *noiseCoef)
{
  if (rcast->obj_touch->type == 's')
    calc_sphere_normale(prog, rcast);
  else if (rcast->obj_touch->type == 't')
    calc_triangle_normale(prog, rcast);
  else if (rcast->obj_touch->type == 'p')
    calc_plan_normale(prog, rcast);
  else if (rcast->obj_touch->type == 'c')
    calc_cone_normale(prog, rcast);
  else if (rcast->obj_touch->type == 'y')
    calc_cyl_normale(prog, rcast);
  else if (rcast->obj_touch->type == 'i')
    calc_circle_normale(prog, rcast);
  else
    return (-1);
  noiseCoef->x = noise(0.1 * rcast->new_point.x, 0.1
		      * rcast->new_point.y, 0.1 * rcast->new_point.z);
  noiseCoef->y = noise(0.1 * rcast->new_point.y, 0.1
		      * rcast->new_point.z, 0.1 * rcast->new_point.x);
  noiseCoef->z = noise(0.1 * rcast->new_point.z, 0.1
      		      * rcast->new_point.x, 0.1 * rcast->new_point.y);
  return (0);
}

int			calc_normale(t_prog *prog, t_raycast *rcast)
{
  t_coord		noiseCoef;
  float			temp;

  pthread_mutex_lock(&mutex);
  if (calc_normale_beg(prog, rcast, &noiseCoef))
    return (-1);
  rcast->normale.x = (1.0f - rcast->mat_touch->bump)
    * rcast->normale.x + rcast->mat_touch->bump * noiseCoef.x;
  rcast->normale.y = (1.0f - rcast->mat_touch->bump)
    * rcast->normale.y + rcast->mat_touch->bump * noiseCoef.y;
  rcast->normale.z = (1.0f - rcast->mat_touch->bump)
    * rcast->normale.z + rcast->mat_touch->bump * noiseCoef.z;
  pthread_mutex_unlock(&mutex);
  temp = mult_vector(rcast->normale, rcast->normale);
  if (temp == 0.0)
    return (-1);
  temp = invsqrtf(temp);
  rcast->normale = float_time_vector(temp, rcast->normale);
  return (0);
}

int			damier(t_coord *pos)
{
  t_point		tmp;

  tmp.x = (int)((pos->x + 13000) / SIZE_TILE);
  tmp.y = (int)(pos->y / SIZE_TILE);
  tmp.z = (int)((pos->z + 13000) / SIZE_TILE);
  if (tmp.x % 2 == 0)
    {
      if (((tmp.y % 2 == 0) && (tmp.z % 2 == 0)) ||
	  (((tmp.y % 2 != 0) && (tmp.z % 2 != 0))))
	return (0);
      else
	return (1);
    }
  else
    {
      if ((((tmp.y % 2 == 0) && (tmp.z % 2 == 0))) ||
	  (((tmp.y % 2 != 0) && (tmp.z % 2 != 0))))
	return (1);
      else
	return (0);
  }
}
