/*
** push_func.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May  4 19:28:40 2016 Ethan Kerdelhue
** Last update Mon May 16 08:01:52 2016 Philippe Lefevre
*/

#include		"main.h"

int			push_triangle(t_prog *prog, t_triangle tri)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_triangle		*new;

  if ((new = malloc(sizeof(t_triangle))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new->angle[0] = tri.angle[0];
  new->angle[1] = tri.angle[1];
  new->angle[2] = tri.angle[2];
  new->material = tri.material;
  new_obj->type = 't';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}

int			push_circle(t_prog *prog, t_circle cir)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_circle		*new;

  if ((new = malloc(sizeof(t_circle))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->plan.center = cir.plan.center;
  new->plan.dir = cir.plan.dir;
  new->material = cir.material;
  new->radius = cir.radius;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 'i';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}

int			push_pillule(t_prog *prog, t_cylin cyl)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_pill		*new;

  if ((new = malloc(sizeof(t_pill))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->cylin = &cyl;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 'l';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}

int			push_cylindre(t_prog *prog, t_cylin cyl)
{
  t_obj_list		*tmp;
  t_obj_list		*new_obj;
  t_cylin		*new;

  if ((new = malloc(sizeof(t_cylin))) == NULL)
    return (-1);
  if ((new_obj = malloc(sizeof(t_obj_list))) == NULL)
    return (-1);
  new->center = cyl.center;
  new->dir = cyl.dir;
  new->radius = cyl.radius;
  new->height = cyl.height;
  new->material = cyl.material;
  tmp = prog->obj_list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  new_obj->type = 'y';
  new_obj->obj = (void *) new;
  new_obj->next = NULL;
  tmp->next = new_obj;
  return (0);
}
