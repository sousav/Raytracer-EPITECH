/*
** obj_calculs.c for raytrace in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Sun Mar 13 20:30:25 2016 victor sousa
** Last update Sat May 21 00:57:49 2016 Philippe Lefevre
*/

#include		"main.h"

double			fade(double t)
{
  return (t * t * t * (t * (t * 6.0 - 15.0) + 10.0));
}
double			lerp(double t, double a, double b)
{
  return (a + t * (b - a));
}
double			grad(int hash, double x, double y, double z)
{
  int			h;
  double		u;
  double		v;

  h  = hash & 15;
  u = h < 8 || h == 12 || h == 13 ? x : y;
  v = h < 4 || h == 12 || h == 13 ? y : z;
  return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

void			noise_init(int p[512])
{
  noise_init_1(p);
  noise_init_2(p);
  noise_init_3(p);
  noise_init_4(p);
  noise_init_5(p);
  noise_init_6(p);
  noise_init_7(p);
  noise_init_8(p);
  noise_init_9(p);
  noise_init_10(p);
  noise_init_11(p);
  noise_init_12(p);
  noise_init_13(p);
  noise_init_14(p);
  noise_init_15(p);
  noise_init_16(p);
  noise_init_17(p);
  noise_init_18(p);
  noise_init_19(p);
  noise_init_20(p);
  noise_init_21(p);
  noise_init_22(p);
}

double			noise_end(t_noise noise, double x, double y, double z)
{
  int			*p;

  p  = noise.p;
  return (lerp(noise.w, lerp(noise.v, lerp(noise.u, grad(p[noise.AA], x, y, z),
      					   grad(p[noise.BA], x - 1, y, z)),
			     lerp(noise.u, grad(p[noise.AB], x, y - 1, z),
				  grad(p[noise.BB], x - 1, y - 1, z))),
	       lerp(noise.v, lerp(noise.u, grad(p[noise.AA + 1], x, y, z - 1),
				  grad(p[noise.BA + 1], x - 1, y, z - 1)),
		    lerp(noise.u, grad(p[noise.AB + 1], x, y - 1, z - 1),
			 grad(p[noise.BB + 1], x - 1, y - 1, z - 1)))));
}
