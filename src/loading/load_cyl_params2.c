/*
** load_cone_params.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Apr 29 05:54:30 2016 Victor Sousa
** Last update Sat May 21 03:06:42 2016 Philippe Lefevre
*/

#include		"main.h"

int			get_center_cyl(t_cylin *c, char **file, int id)
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

int			get_dir_cyl(t_cylin *c, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:object_list:objX:dir:x") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:object_list:objX:dir:x");
  lf[21] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->dir.x = my_getnbr(get);
  free(get);
  lf[27] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->dir.y = my_getnbr(get);
  free(get);
  lf[27] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  c->dir.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

int			get_radius_cyl(t_cylin *c, char **file, int id)
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
  c->radius = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

int			get_mat_id_cyl(t_cylin *c, char **file, int id)
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

int			get_cone_height_cyl(t_cylin *c, char **file, int id)
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
  c->height = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}
