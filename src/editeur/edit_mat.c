/*
** edit_mat.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr 29 19:34:34 2016 Ethan Kerdelhue
** Last update Thu May  5 08:10:21 2016 Ethan Kerdelhue
*/

#include		"main.h"

t_mat_list		*get_ptr_mat(t_prog *prog, int id)
{
  t_mat_list		*tmp;
  int			i;

  i = 0;
  tmp = prog->mat_list;
  while (id != i)
    {
      if (tmp->next)
	tmp = tmp->next;
      else
	return (NULL);
      i++;
    }
  return (tmp);
}

int			edit_color(int old)
{
  int			flag;
  char			*str;
  int			val;

  flag = 0;
  while (flag != 1)
    {
      str = get_next_line(0);
      val = my_getnbr(str);
      if ((val >= 0 && val <= 255)|| str[0] == '\0')
	{
	  if (str[0] == '\0')
	    val = old;
	  flag = 1;
	}
      else
	my_printf(1, "Error : la valeur doit être comprise entre 0 et 255\n");
      free (str);
    }
  return (val);
}

int			edit_rgb(t_color *color)
{
  my_printf(1, "Rouge :\n");
  color->argb[RED_CMP] = edit_color(color->argb[RED_CMP]);
  my_printf(1, "Vert :\n");
  color->argb[GREEN_CMP] = edit_color(color->argb[GREEN_CMP]);
  my_printf(1, "Bleue :\n");
  color->argb[BLUE_CMP] = edit_color(color->argb[BLUE_CMP]);
  return (0);
}

int			select_mat(t_prog *prog)
{
  int			flag;
  char			*str;
  int			val;

  my_printf(1, "Selectionnez le matériaux :\n");
  flag = 0;
  while (flag != 1)
    {
      str = get_next_line(0);
      val = my_getnbr(str);
      if (check_material_id(prog, val) == 1)
	{
	  free(str);
	  return (val);
	}
      else
	my_printf(1, "Error : id du matériaux inexistant\n");
      free(str);
    }
  return (0);
}

int			edit_mat(t_prog *prog)
{
  t_mat_list		*mat;
  int			id;
  char			*str;

  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  my_printf(1, "Entrez l'id du matériaux a modifier\n");
  id = count_material(prog) - select_mat(prog);
  if ((mat = get_ptr_mat(prog, id)) == NULL)
    return (-1);
  aff_mat(0, mat);
  edit_rgb(&mat->color);
  my_printf(1, "Reflection :\n");
  str = get_next_line(0);
  mat->reflect = ((str[0] != '\0') ? (my_getnbr(str)) : (mat->reflect));
  my_printf(1, "Coefficient de bump mapping (conseil : > 0 && < 1) :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  mat->bump = ((str[0] != 0) ? (my_atof(str)) : (mat->bump));
  free(str);
  my_printf(1, "Chemin de texture :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  mat->texture_path = ((str[0] != 0) ? (str) : (mat->texture_path));
  return (0);
}
