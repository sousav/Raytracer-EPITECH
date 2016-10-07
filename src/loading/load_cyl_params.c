/*
** load_cone_params.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 29 05:54:30 2016 Victor Sousa
** Last update Sat May 21 03:09:10 2016 Philippe Lefevre
*/

#include		"main.h"

t_cylin			*add_cyl_bis(t_cylin *c)
{
  c->cap[0]->plan.center = minus_vector(c->center,
					float_time_vector((float)c->height
							  / 2.0, c->dir));
  c->cap[0]->plan.dir.x = c->dir.x;
  c->cap[0]->plan.dir.y = c->dir.y;
  c->cap[0]->plan.dir.z = c->dir.z;
  c->cap[0]->material = c->material;
  c->cap[0]->radius = c->radius;
  if ((c->cap[1] = malloc(sizeof(t_circle))) == NULL)
    return (NULL);
  c->cap[1]->plan.center = add_vector(c->center,
				      float_time_vector((float)c->height
							/ 2.0, c->dir));
  c->cap[1]->plan.dir.x = -c->dir.x;
  c->cap[1]->plan.dir.y = -c->dir.y;
  c->cap[1]->plan.dir.z = -c->dir.z;
  c->cap[1]->material = c->material;
  c->cap[1]->radius = c->radius;
  c->center = minus_vector(c->center,
			   float_time_vector((float)c->height
					     / 2.0 , c->dir));
  return (c);
}

t_obj_list              *add_cyl(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_cylin             	*c;

  if (((new = malloc(sizeof(t_obj_list))) == NULL)
  || ((c = malloc(sizeof(t_cylin))) == NULL)
  || (get_center_cyl(c, file, id) != 0)
  || (get_dir_cyl(c, file, id) != 0)
  || (get_radius_cyl(c, file, id) != 0)
  || (get_mat_id_cyl(c, file, id) != 0)
  || (get_cone_height_cyl(c, file, id) != 0)
  || ((c->cap[0] = malloc(sizeof(t_circle))) == NULL))
    return (NULL);
  c = add_cyl_bis(c);
  new->obj = c;
  new->type = 'y';
  new->next = prev;
  return (new);
}
