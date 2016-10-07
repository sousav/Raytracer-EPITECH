/*
** client_raytrace.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/client/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri May 13 04:44:05 2016 Gaëtan Léandre
** Last update Sat May 21 22:14:08 2016 Philippe Lefevre
*/

#include		"main.h"

int			load_scene_open_beg_bis(t_prog *prog, char **file,
						char *get)
{
  if ((get = get_field(file, "scene:view:background")) == NULL)
    return (my_printf(2, "Could not find scene:view:background\n") - 1);
  if ((prog->background_path = malloc(my_strlen(get) + 1)) == NULL)
    return (-1);
  prog->background_path[0] = '\0';
  prog->background_path = my_strcat(prog->background_path, get);
        if (my_strcmp(get, "NULL") == 0)
    {
      if ((prog->background = create_text_uni(prog->win_size.x,
						    prog->win_size.x,
						    0xff000000)) == NULL)
	return (-1);
    }
  else
    {
      if ((prog->background = load_image(get)) == NULL)
	return (-1);
      place_into_hitbox(prog->background, prog->background,
			      create_hitbox(0, 0, prog->win_size.x,
				      prog->win_size.y));
    }
  free(get);
  return (0);
}

int			load_scene_open_beg(t_prog *prog, char **file)
{
  char			*get;

  if ((get = get_field(file, "scene:view:x_size")) == NULL)
    return (my_printf(2, "Could not find scene:view:x_size\n") - 1);
  prog->win_size.x = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:y_size")) == NULL)
    return (my_printf(2, "Could not find scene:view:y_size\n") - 1);
  prog->win_size.y = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:fov")) == NULL)
    return (my_printf(2, "Could not find scene:view:fov\n") - 1);
  prog->cam_fov.x = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:alias")) == NULL)
    return (my_printf(2, "Could not find scene:view:alias\n") - 1);
  prog->anti_alias = my_getnbr(get);
  free(get);
  return (load_scene_open_beg_bis(prog, file, get));
}

int			load_scene_open(t_prog *prog, char *str)
{
  char			**file;
  t_coord		dir;

  if (((file = str_to_wordtab(str, "\n")) == NULL)
      || (load_scene_open_beg(prog, file)))
    return (-1);
  prog->cam_fov.y = prog->cam_fov.x * ((prog->win_size.x
					/ prog->win_size.y) / 1.5);
  if (get_cam_pos(file, prog) == 1 ||
      get_cam_look_at(file, prog) == 1 ||
      load_mat(prog, file) == -1 ||
      load_light(prog, file) == -1 ||
      load_obj(prog, file) == -1)
    return (-1);
  if (prog->look_at.x == prog->cam_pos.x &&
      prog->look_at.y == prog->cam_pos.y &&
      prog->look_at.z == prog->cam_pos.z)
    return (my_printf(2, "Wrong camera placement\n") - 1);
  dir = normalize(minus_point(prog->look_at, prog->cam_pos));
  prog->cam_rot.x = RTD(acos(-(dir.z / sqrt(pow(dir.x, 2)
					    + pow(dir.z, 2))))) - 90;
  prog->cam_rot.y = RTD((M_PI / 2 - acos(dir.y)));
  prog->cam_dir = normalize(minus_point(prog->look_at, prog->cam_pos));
  free_tab(file);
  return (0);
}
