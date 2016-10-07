/*
** hit.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 23:01:14 2016 victor sousa
** Last update Sat May 21 00:03:15 2016 Philippe Lefevre
*/

#include		"main.h"

t_obj_list		*hit_normal_forme(t_obj_list *out, t_obj_list *tmp,
					  t_ray *ray, float *dist)
{
  if ((tmp->type == 's' && hit_sphere(ray, (t_sphere *)tmp->obj, dist))
      || (tmp->type == 't' && hit_triangle(ray, (t_triangle *)tmp->obj, dist))
      || (tmp->type == 'p' && hit_plan(ray, (t_plan *)tmp->obj, dist))
      || (tmp->type == 'p' && hit_circle(ray, (t_circle *)tmp->obj, dist)))
    {
      out->type = tmp->type;
      out->obj = tmp->obj;
    }
 return (out);
}

t_obj_list		*hit_cylin_closed(t_obj_list *out, t_obj_list *tmp,
					  t_ray *ray, float *dist)
{
  t_cylin		*cy;

  if (tmp->type == 'y')
    {
      cy = tmp->obj;
      if (hit_cylin(ray, cy, dist, 0))
	{
	  out->type = tmp->type;
	  out->obj = cy;
	}
      if (hit_circle(ray, cy->cap[0], dist))
	{
	  out->type = 'i';
	  out->obj = cy->cap[0];
	}
      if (hit_circle(ray, cy->cap[1], dist))
	{
	  out->type = 'i';
	  out->obj = cy->cap[1];
	}
    }
  return (out);
}

t_obj_list		*hit_pill_closed(t_obj_list *out, t_obj_list *tmp,
					  t_ray *ray, float *dist)
{
  t_pill		*pi;

  if (tmp->type == 'l')
    {
      pi = tmp->obj;
      if (hit_cylin(ray, pi->cylin, dist, 0))
	{
	  out->type = 'y';
	  out->obj = pi->cylin;
	}
      if (hit_sphere(ray, pi->cap[0], dist))
	{
	  out->type = 's';
	  out->obj = pi->cap[0];
	}
  	  if (hit_sphere(ray, pi->cap[1], dist))
	{
	  out->type = 's';
	  out->obj = pi->cap[1];
	}
    }
  return (out);
}

t_obj_list		*hit_cone_closed(t_obj_list *out, t_obj_list *tmp,
					  t_ray *ray, float *dist)
{
  t_cone		*co;

  if (tmp->type == 'c')
    {
      co = tmp->obj;
      if (hit_cone(ray, co, dist))
	{
	  out->type = tmp->type;
	  out->obj = tmp->obj;
	}
      if (hit_circle(ray, co->cap, dist))
	{
	  out->type = 'i';
	  out->obj = co->cap;
	}
    }
  return (out);
}

t_obj_list		*hit(t_obj_list *obj_list, t_ray *ray, float *dist)
{
  t_obj_list		*out;
  t_obj_list		*tmp;

  if ((out = malloc(sizeof(t_obj_list))) == NULL)
    return (NULL);
  out->obj = NULL;
  tmp = obj_list;
  while (tmp != NULL)
    {
      hit_normal_forme(out, tmp, ray, dist);
      hit_cylin_closed(out, tmp, ray, dist);
      hit_pill_closed(out, tmp, ray, dist);
      hit_cone_closed(out, tmp, ray, dist);
      tmp = tmp->next;
    }
  out->next = NULL;
  return (out);
}
