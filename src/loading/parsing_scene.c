/*
** parsing_scene.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 04:25:03 2016 victor sousa
** Last update Sun May 22 16:33:10 2016 Philippe Lefevre
*/

#include		"main.h"

int			get_cam_pos(char **file, t_prog *prog)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:view:cam_pos:x")
		   + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:view:cam_pos:x");
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:cam_pos:x\n") - 1);
  prog->cam_pos.x = my_getnbr(get);
  free(get);
  lf[19] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:cam_pos:y\n") - 1);
  prog->cam_pos.y = my_getnbr(get);
  free(get);
  lf[19] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:cam_pos:z\n") - 1);
  prog->cam_pos.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

int			get_cam_look_at(char **file, t_prog *prog)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:view:look_at:x")
		   + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:view:look_at:x");
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:look_at:x\n") - 1);
  prog->look_at.x = my_getnbr(get);
  free(get);
  lf[19] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:look_at:y\n") - 1);
  prog->look_at.y = my_getnbr(get);
  free(get);
  lf[19] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:view:look_at:z\n") - 1);
  prog->look_at.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

int			load_scene_beg_bis(t_prog *prog, char *get,
					   char **file)
{
  if ((get = get_field(file, "scene:view:background")) == NULL)
    return (my_printf(1, "Could not find scene:view:background\n") - 1);
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

int			load_scene_beg(t_prog *prog, char **file)
{
  char			*get;

  if ((get = get_field(file, "scene:view:x_size")) == NULL)
    return (my_printf(1, "Could not find scene:view:x_size\n") - 1);
  prog->win_size.x = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:y_size")) == NULL)
    return (my_printf(1, "Could not find scene:view:y_size\n") - 1);
  prog->win_size.y = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:fov")) == NULL)
    return (my_printf(1, "Could not find scene:view:fov\n") - 1);
        prog->cam_fov.x = my_getnbr(get);
  free(get);
  if ((get = get_field(file, "scene:view:alias")) == NULL)
    return (my_printf(1, "Could not find scene:view:alias\n") - 1);
  prog->anti_alias = my_getnbr(get);
  free(get);
  return (load_scene_beg_bis(prog, get, file));
}

int			load_scene(t_prog *prog, char *scene_path)
{
  char			**file;
  t_coord		dir;

  if ((file = load_scene_file(scene_path, -1, 0, prog->opt->verbose)) == NULL)
    return (-1);
  if (load_scene_beg(prog, file))
    return (-1);
  prog->cam_fov.y =
    prog->cam_fov.x * ((prog->win_size.x / prog->win_size.y) / 1.5);
  if (get_cam_pos(file, prog) == 1 ||
      get_cam_look_at(file, prog) == 1 ||
      load_mat(prog, file) == -1 ||
      load_light(prog, file) == -1 ||
      load_obj(prog, file) == -1)
    return (-1);
  if (prog->look_at.x == prog->cam_pos.x &&
      prog->look_at.y == prog->cam_pos.y &&
      prog->look_at.z == prog->cam_pos.z)
    return (my_printf(1, "Wrong camera placement\n") - 1);
  dir = normalize(minus_point(prog->look_at, prog->cam_pos));
  prog->cam_rot.x = RTD(acos(-(dir.z / sqrt(pow(dir.x, 2)
					    + pow(dir.z, 2))))) - 90;
  prog->cam_rot.y = RTD((M_PI / 2 - acos(dir.y)));
  prog->cam_dir = normalize(minus_point(prog->look_at, prog->cam_pos));
  return (0);
}
