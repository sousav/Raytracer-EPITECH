/*
** wtf.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Wed Mar  9 06:36:19 2016 victor sousa
** Last update Wed Mar  9 06:38:19 2016 victor sousa
*/

#include	"main.h"

float		invsqrt(float number)
{
  long		i;
  float		x2;
  float		y;
  const float	threehalfs = 1.5f;

  x2 = number * 0.5F;
  y  = number;
  i  = *(long *) &y;
  i  = 0x5f3759df - (i >> 1);
  y  = *(float *) &i;
  y  = y * (threehalfs - (x2 * y * y));
  return (y);
}
