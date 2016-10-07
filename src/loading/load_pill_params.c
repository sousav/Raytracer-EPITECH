/*
** load_cone_params.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 29 05:54:30 2016 Victor Sousa
** Last update Sat May 21 02:55:53 2016 Philippe Lefevre
*/

#include		"main.h"

static int		get_cone_height_pill(t_cylin *p, char **file, int id)
{
  char			*lf;
  char			*get;

 if ((lf = malloc(sizeof(char) *
		  my_strlen("scene:object_list:objX:height") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:height");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  p->height = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

t_pill              *add_pill_bis(t_pill *p)
{
  p->cap[0]->center = minus_vector(p->cylin->center,
				   float_time_vector((float)p->cylin->height
						     / 2.0, p->cylin->dir));
  p->cap[0]->material = p->cylin->material;
  p->cap[0]->material2 = p->cylin->material;
  p->cap[0]->radius = p->cylin->radius;
  if ((p->cap[1] = malloc(sizeof(t_sphere))) == NULL)
    return (NULL);
  p->cap[1]->center = add_vector(p->cylin->center,
				 float_time_vector((float)p->cylin->height
						   / 2.0, p->cylin->dir));
  p->cap[1]->material = p->cylin->material;
  p->cap[1]->material2 = p->cylin->material;
  p->cap[1]->radius = p->cylin->radius;
  p->cylin->center = minus_vector(p->cylin->center,
				  float_time_vector((float)p->cylin->height
						    / 2.0 , p->cylin->dir));
  return (p);
}

t_obj_list              *add_pill(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_pill             	*p;

  if (((new = malloc(sizeof(t_obj_list))) == NULL)
      || ((p = malloc(sizeof(t_pill))) == NULL)
      || ((p->cylin = malloc(sizeof(t_cylin))) == NULL)
      || (get_center_pill(p->cylin, file, id) != 0)
      || (get_dir_pill(p->cylin, file, id) != 0)
      || (get_radius_pill(p->cylin, file, id) != 0)
      || (get_mat_id_pill(p->cylin, file, id) != 0)
      || (get_cone_height_pill(p->cylin, file, id) != 0)
      || ((p->cap[0] = malloc(sizeof(t_sphere))) == NULL))
    return (NULL);
  p = add_pill_bis(p);
  new->obj = p;
  new->type = 'l';
  new->next = prev;
  return (new);
}
