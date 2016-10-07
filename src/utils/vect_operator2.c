/*
** vect_operator2.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:08:40 2016 victor sousa
** Last update Sat May 21 05:09:04 2016 Philippe Lefevre
*/

#include	"main.h"

t_coord                 normalize(t_coord vec)
{
  t_coord               out;

  out.x = vec.x / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  out.y = vec.y / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  out.z = vec.z / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  return (out);
}

t_coord                 normalize_p(t_point vec)
{
  t_coord               out;

  out.x = (float)vec.x / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  out.y = (float)vec.y / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  out.z = (float)vec.z / sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
  return (out);
}

t_coord                 float_minus_vector(float c, const t_coord v)
{
  t_coord               out;

  out.x = v.x - c;
  out.y = v.y - c;
  out.z = v.z - c;
  return (out);
}
