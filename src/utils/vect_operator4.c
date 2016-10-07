/*
** vect_operator.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 22:59:09 2016 victor sousa
** Last update Sat May 21 05:09:12 2016 Philippe Lefevre
*/

#include		"main.h"

t_coord                 float_plus_vector(float c, const t_coord v)
{
  t_coord               out;

  out.x = v.x + c;
  out.y = v.y + c;
  out.z = v.z + c;
  return (out);
}

t_coord                 vecnorm(t_coord coord)
{
  t_coord               out;

  out.x = sqrt(pow((coord.x), 2));
  out.y = sqrt(pow((coord.y), 2));
  out.z = sqrt(pow((coord.z), 2));
  return (out);
}

float                   min(float a, float b)
{
  if (a < b)
    return (a);
  return (b);
}

float                   max(float a, float b)
{
  if (a < b)
    return (b);
  return (a);
}
