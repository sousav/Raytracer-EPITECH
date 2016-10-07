/*
** load_sphere.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:13:22 2016 victor sousa
** Last update Thu May  5 11:55:08 2016 Victor Sousa
*/

#include	"main.h"

static int		get_center(t_cube *c, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:center:x") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:center:x");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->center.x = my_getnbr(get);
  free(get);
  lf[30] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->center.y = my_getnbr(get);
  free(get);
  lf[30] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->center.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_size(t_cube *c, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:size:x") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:size:x");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->size.x = my_getnbr(get);
  free(get);
  lf[28] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->size.y = my_getnbr(get);
  free(get);
  lf[28] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->size.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_mat_id(t_cube *c, char **file, int id)
{
  char			*lf;
  char			*get;

 if ((lf = malloc(sizeof(char) *
		  my_strlen("scene:object_list:objX:material_id") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:material_id");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->material = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

t_obj_list              *add_cube(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_cube              *c;

  if ((new = malloc(sizeof(t_obj_list))) == NULL)
    return (NULL);
  if ((c = malloc(sizeof(t_cube))) == NULL)
    return (NULL);
  if (get_center(c, file, id) != 0)
    return (NULL);
  if (get_size(c, file, id) != 0)
    return (NULL);
  if (get_mat_id(c, file, id) != 0)
    return (NULL);
  new->obj = c;
  new->type = 'u';
  new->next = prev;
  return (new);
}
