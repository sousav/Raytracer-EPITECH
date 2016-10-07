/*
** vect_operator.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 22:59:09 2016 victor sousa
** Last update Sat May 21 05:08:41 2016 Philippe Lefevre
*/

#include		"main.h"

float                   mult_vector(const t_coord v1, const t_coord v2)
{
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_coord                 minus_vector(const t_coord v1, const t_coord v2)
{
  t_coord               out;

  out.x = v1.x - v2.x;
  out.y = v1.y - v2.y;
  out.z = v1.z - v2.z;
  return (out);
}

t_coord                 minus_point(const t_point v1, const t_point v2)
{
  t_coord               out;

  out.x = v1.x - v2.x;
  out.y = v1.y - v2.y;
  out.z = v1.z - v2.z;
  return (out);
}

t_coord                 add_vector(const t_coord v1, const t_coord v2)
{
  t_coord               out;

  out.x = v1.x + v2.x;
  out.y = v1.y + v2.y;
  out.z = v1.z + v2.z;
  return (out);
}
