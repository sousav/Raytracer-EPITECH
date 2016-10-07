/*
** load_mtl.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/loading/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue May  3 02:15:04 2016 Ethan Kerdelhue
** Last update Sun May 22 16:37:29 2016 Philippe Lefevre
*/

#include		"main.h"

char			*get_mtl_name(char **file)
{
  int			i;

  i = 0;
  while (file[i])
    {
      if (my_strncmp(file[i], "Ks", 2))
	{
	  if (my_strncmp(file[i - 1], "newmtl", 6))
	      return (my_strdup(file[i - 1] + 7));
	  else
	    {
	      my_printf(1, "Error : bad MTL format\n");
	      return (NULL);
	    }
	}
      i++;
    }
  return (0);
}

int			create_mat(t_prog *prog, char **file, char **tab_color)
{
  t_mat_list		mat;
  float			r;
  float			g;
  float			b;

  r = my_atof(tab_color[1]) * 255;
  g = my_atof(tab_color[2]) * 255;
  b = my_atof(tab_color[3]) * 255;
  mat.color.argb[RED_CMP] = (int) r;
  mat.color.argb[GREEN_CMP] = (int) g;
  mat.color.argb[BLUE_CMP] = (int) b;
  mat.reflect = 15;
  if ((mat.mtl_name = get_mtl_name(file)) == NULL)
    return (-1);
  if ((push_mat(prog, mat)) == -1)
    return (-1);
  return (0);
}

char			*get_kd(char **file)
{
  int			i;

  i = 0;
  while (file[i])
    {
      if (my_strncmp(file[i], "Kd", 2))
	return (file[i]);
      i++;
    }
  return (NULL);
}

int			load_mtl(char *path, t_prog *prog)
{
  char			**file;
  char			*kd;
  char			**tab_color;

  if ((file = load_scene_file(path, -1, 0, prog->opt->verbose)) == NULL)
    return (-1);
  kd = get_kd(file);
  tab_color = str_to_wordtab(kd, " ");
  free(kd);
  if ((create_mat(prog, file, tab_color)) == -1)
    return (-1);
  return (0);
}
