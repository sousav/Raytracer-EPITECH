/*
** load_cone_params.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 29 05:54:30 2016 Victor Sousa
** Last update Sat May 21 18:37:35 2016 Philippe Lefevre
*/

#include		"main.h"

t_obj_list              *add_cone(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_cone             	*c;

  if (((new = malloc(sizeof(t_obj_list))) == NULL)
    || ((c = malloc(sizeof(t_cone))) == NULL))
    return (NULL);
  if ((get_center_cone(c, file, id) != 0)
      || (get_dir_cone(c, file, id) != 0)
      || (get_radius_cone(c, file, id) != 0)
      || (get_mat_id_cone(c, file, id) != 0)
      || (get_cone_height_cone(c, file, id) != 0)
      || ((c->cap = malloc(sizeof(t_circle))) == NULL))
    return (NULL);
  c->center =
    minus_vector(c->center, float_time_vector((float)c->height / 2.0, c->dir));
  c->cap->plan.center = c->center;
  c->cap->plan.dir.x = c->dir.x;
  c->cap->plan.dir.y = c->dir.y;
  c->cap->plan.dir.z = c->dir.z;
  c->cap->material = c->material;
  c->cap->radius = c->radius;
  new->obj = c;
  new->type = 'c';
  new->next = prev;
  return (new);
}
