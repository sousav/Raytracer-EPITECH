/*
** vect_operator.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 22:59:09 2016 victor sousa
** Last update Sat May 21 05:08:35 2016 Philippe Lefevre
*/

#include		"main.h"

t_coord			float_time_vector(float c, const t_coord v)
{
  t_coord		out;

  out.x = v.x * c;
  out.y = v.y * c;
  out.z = v.z * c;
  return (out);
}

t_coord			crossProduct(t_coord c1, t_coord c2)
{
  t_coord		out;

  out.x = c1.y * c2.z - c2.y * c1.z;
  out.y = c1.z * c2.x - c2.z * c1.x;
  out.z = c1.x * c2.y - c2.x * c1.y;
  return (out);
}
