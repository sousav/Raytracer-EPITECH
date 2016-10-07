/*
** load_plan_params.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed Apr 27 17:06:03 2016 Victor Sousa
** Last update Sat May 21 17:48:22 2016 Philippe Lefevre
*/

#include		"main.h"

static int		get_mat_id(t_plan *p, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:material_id1")
		  + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:material_id1");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  p->material = my_getnbr(get);
  free(get);
  lf[34] = '2';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  p->material2 = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static int		get_end(char *get, char *lf, char **file)
{
  int			ret;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  ret = my_getnbr(get);
  free(get);
  free(lf);
  return (ret);
}

static int		get_dir(t_plan *p, char **file, int id)
{
  char			*lf;
  char			*get;
  t_point		tmp;

  if ((lf = malloc(sizeof(char) * my_strlen("scene:object_list:objX:dir:x")
		   + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:dir:x");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp.x = my_getnbr(get);
  free(get);
  lf[27] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp.y = my_getnbr(get);
  free(get);
  lf[27] = 'z';
  tmp.z = get_end(get, lf, file);
  p->dir.x = tmp.x;
  p->dir.y = tmp.y;
  p->dir.z = tmp.z;
  return (0);
}

static int		get_center(t_plan *p, char **file, int id)
{
  char			*lf;
  char			*get;
  t_point		tmp;

  if ((lf = malloc(sizeof(char) * my_strlen("scene:object_list:objX:center:x")
		   + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:center:x");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp.x = my_getnbr(get);
  free(get);
  lf[30] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  tmp.y = my_getnbr(get);
  free(get);
  lf[30] = 'z';
  tmp.z = get_end(get, lf, file);
  p->center.x = tmp.x;
  p->center.y = tmp.y;
  p->center.z = tmp.z;
  return (0);
}

t_obj_list              *add_plan(t_obj_list *prev, char **file, int id)
{
  t_obj_list            *new;
  t_plan           	*p;

  if ((new = malloc(sizeof(t_obj_list))) == NULL)
    return (NULL);
  if ((p = malloc(sizeof(t_plan))) == NULL)
    return (NULL);
  if (get_center(p, file, id) != 0)
    return (NULL);
  if (get_dir(p, file, id) != 0)
    return (NULL);
  if (get_mat_id(p, file, id) != 0)
    return (NULL);
  new->obj = p;
  new->type = 'p';
  new->next = prev;
  return (new);
}
