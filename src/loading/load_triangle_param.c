/*
** load_sphere.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:13:22 2016 victor sousa
** Last update Mon May 16 17:45:40 2016 Philippe Lefevre
*/

#include		"main.h"

static int		get_mat_id(t_triangle *t, char **file, int id)
{
  char			*lf;
  char			*get;

 if ((lf = malloc(sizeof(char) *
		  my_strlen("scene:object_list:objX:material_id")
		  + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:material_id");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  t->material = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_point_bis(char *lf, t_point *tmp, char **file)
{
  char			*get;

  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp->x = my_getnbr(get);
  free(get);
  lf[26] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp->y = my_getnbr(get);
  free(get);
  lf[26] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp->z = my_getnbr(get);
  free(get);
  return (0);
}

static int		get_point(t_triangle *t, char **file, int id, int p_id)
{
  char			*lf;
  t_point		tmp;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:pX:x") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:pX:x");
  lf[21] = id + 49;
  lf[24] = p_id + 49;
  get_point_bis(lf, &tmp, file);
  free(lf);
  t->angle[p_id].x = tmp.x;
  t->angle[p_id].y = tmp.y;
  t->angle[p_id].z = tmp.z;
  return (0);
}

t_obj_list              *add_triangle(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_triangle            *t;
  int			pointi;

  if ((new = malloc(sizeof(t_obj_list))) == NULL)
    return (NULL);
  if ((t = malloc(sizeof(t_triangle))) == NULL)
    return (NULL);
  pointi = 0;
  while (pointi < 3)
    {
      if (get_point(t, file, id, pointi) != 0)
	return (NULL);
      pointi++;
    }
  if (get_mat_id(t, file, id) != 0)
    return (NULL);
  new->obj = t;
  new->type = 't';
  new->next = prev;
  return (new);
}
