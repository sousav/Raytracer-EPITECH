/*
** load_sphere.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:26:06 2016 victor sousa
** Last update Sat May 21 19:07:33 2016 Philippe Lefevre
*/

#include		"main.h"

int			is_load_obj_3(char *get, char **file,
				      t_prog *prog, int i)
{
  if (my_strstr(get, "cube"))
    {
      if ((prog->obj_list = add_cube(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  return (-1);
}

int			is_load_obj_2(char *get, char **file,
				      t_prog *prog, int i)
{
  if (my_strstr(get, "cone"))
    {
      if ((prog->obj_list = add_cone(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  else if (my_strstr(get, "pill"))
    {
      if ((prog->obj_list = add_pill(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  else if (my_strstr(get, "cylinder"))
    {
      if ((prog->obj_list = add_cyl(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  return (is_load_obj_3(get, file, prog, i));
}
int			is_load_obj_1(char *get, char **file,

				      t_prog *prog, int i)
{
  if (my_strstr(get, "sphere"))
    {
      if ((prog->obj_list = add_sphere(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  else if (my_strstr(get, "triangle"))
    {
      if ((prog->obj_list = add_triangle(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  else if (my_strstr(get, "plan"))
    {
      if ((prog->obj_list = add_plan(prog->obj_list, file, i)) == NULL)
	return (-1);
      return (0);
    }
  return (is_load_obj_2(get, file, prog, i));
}

int			while_load_obj(char **file, char *get,
				       char *type_lf, t_prog *prog)
{
  int			i;
  int			obj_count;

  obj_count = my_getnbr(get);
  free(get);
  i = -1;
  while (++i < obj_count)
    {
      type_lf[21] = i + 49;
      if ((get = get_field(file, type_lf)) == NULL)
	return (my_printf(1, "Could not find "
			  "scene:object_list:obj%d:type\n", i + 1) - 1);
      if (is_load_obj_1(get, file, prog, i))
	return (-1);
      free(get);
    }
  return (0);
}

int                     load_obj(t_prog *prog, char **file)
{
  char                  *type_lf;
  char                  *get;

  if ((get = get_field(file, "scene:object_list:count")) == NULL)
    {
      my_printf(1, "Could not find scene:object_list:count\n");
      return (-1);
    }
  prog->obj_list = NULL;
  if ((type_lf = malloc(sizeof(char) *
			my_strlen("scene:object_list:objX:type") + 1)) == NULL)
    return (-1);
  type_lf[0] = '\0';
  type_lf = my_strcat(type_lf, "scene:object_list:objX:type");
  return (while_load_obj(file, get, type_lf, prog));
}
