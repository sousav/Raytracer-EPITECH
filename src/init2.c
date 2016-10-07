/*
** main.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 01:50:10 2016 victor sousa
** Last update Sun May 22 19:02:17 2016 Philippe Lefevre
*/

#include		"main.h"

int			verif_load(t_prog *prog, char *args)
{
  int			ret;
  int			size;

  size = my_strlen(args);
  ret = -1;
  if (args[size - 1] == 'l' && args[size - 2] == 'm'
      && args[size - 3] == 'x' && args[size - 4] == '.')
    ret = load_scene(prog, args);
  else if (args[size - 1] == 'j' && args[size - 2] == 'b'
	   && args[size - 3] == 'o' && args[size - 4] == '.')
    ret = load_obj_file(prog, args);
  else
    return (0);
  if (ret == -1)
    {
      return (my_printf(2, "scene   loading  failed... leaving\n") - 1);
    }
  else if (prog->opt->verbose)
    my_putstr("scene   loading  successfull\n");
  return (1);
}

int			verif_env(char **env)
{
  int			i;

  if (env == NULL)
    return (-1);
  i = -1;
  while (env[++i])
    {
      if (!(my_strncmp(env[i], "DISPLAY=", 8)))
	return (0);
    }
  return (-1);
}

int			init_rendu(char *arg, t_prog *prog)
{
  if (!(my_strcmp("--rendu_display", arg)))
    {
      prog->opt->rendu_display = 1;
      return (1);
    }
  else if (!(my_strcmp("--rendu_vertical", arg)))
    {
      prog->opt->rendu_vertical = 1;
      return (1);
    }
  else if (!(my_strncmp("--export=", arg, 9)))
    {
      if (my_strlen(arg) < 10)
	return (0);
      prog->opt->export = 1;
      prog->opt->export_path = my_strdup(arg + 9);
      return (1);
    }
  return (0);
}
