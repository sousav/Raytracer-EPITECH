/*
** push_func.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May  4 19:28:40 2016 Ethan Kerdelhue
** Last update Mon May 16 08:02:18 2016 Philippe Lefevre
*/

#include		"main.h"

int			push_cone(t_prog *prog, t_cone con)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_cone		*new;

  if ((new = malloc(sizeof(t_cone))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->center = con.center;
  new->dir = con.dir;
  new->radius = con.radius;
  new->height = con.height;
  new->material = con.material;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 'c';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}

int			push_plan(t_prog *prog, t_plan pla)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_plan		*new;

  if ((new = malloc(sizeof(t_plan))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->center = pla.center;
  new->dir = pla.dir;
  new->material = pla.material;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 'p';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}

int			push_sphere(t_prog *prog, t_sphere sph)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_sphere		*new;

  if ((new = malloc(sizeof(t_sphere))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->center.x = sph.center.x;
  new->center.y = sph.center.y;
  new->center.z = sph.center.z;
  new->radius = sph.radius;
  new->material = sph.material;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 's';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}
