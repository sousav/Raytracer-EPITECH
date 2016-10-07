/*
** load_sphere.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:13:22 2016 victor sousa
** Last update Tue May  3 02:09:25 2016 Victor Sousa
*/

#include	"main.h"

static int		get_center(t_sphere *s, char **file, int id)
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
  s->center.x = my_getnbr(get);
  free(get);
  lf[30] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  s->center.y = my_getnbr(get);
  free(get);
  lf[30] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  s->center.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_radius(t_sphere *s, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:radius") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:radius");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  s->radius = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_mat_id(t_sphere *s, char **file, int id)
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
  s->material = my_getnbr(get);
  s->material2 = 1;
  free(get);
  free(lf);
  return (0);
}

t_obj_list              *add_sphere(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_sphere              *s;

  if ((new = malloc(sizeof(t_obj_list))) == NULL)
    return (NULL);
  if ((s = malloc(sizeof(t_sphere))) == NULL)
    return (NULL);
  if (get_center(s, file, id) != 0)
    return (NULL);
  if (get_radius(s, file, id) != 0)
    return (NULL);
  if (get_mat_id(s, file, id) != 0)
    return (NULL);
  new->obj = s;
  new->type = 's';
  new->next = prev;
  return (new);
}
