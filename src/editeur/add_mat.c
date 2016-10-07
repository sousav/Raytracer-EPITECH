/*
** add_mat.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 27 16:18:56 2016 Ethan Kerdelhue
** Last update Mon May 16 07:50:21 2016 Philippe Lefevre
*/

#include		"main.h"

int			push_mat(t_prog *prog, t_mat_list mat)
{
  t_mat_list		*tmp;
  t_mat_list		*new;

  tmp = prog->mat_list;
  if ((new = malloc(sizeof(t_mat_list))) == NULL)
    return (-1);
  new->id = count_material(prog) + 1;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->color = mat.color;
  new->reflect = mat.reflect;
  new->bump = mat.bump;
  new->texture_path = mat.texture_path;
  new->next = NULL;
  return (0);
}

t_color			get_rgb(int flag, int i, char *str)
{
  t_color		tmp;

  i = RED_CMP;
  while (flag != 1)
    {
      if (i == RED_CMP)
	my_printf(0, "Rouge :\n");
      if (i == GREEN_CMP)
	my_printf(0, "Vert :\n");
      if (i == BLUE_CMP)
	my_printf(0, "Bleu :\n");
      str = get_next_line(0);
      if (my_getnbr(str) >= 0 || my_getnbr(str) <= 255)
	{
	  tmp.argb[i] = my_getnbr(str);
	  if (i++ == BLUE_CMP)
	    flag = 1;
	}
      else
	my_printf(0, "Error : valeur uniquement entre 0 et 255");
      free(str);
    }
  return (tmp);
}

int			add_mat_s(t_prog *prog)
{
  t_mat_list		tmp;
  char 			*str;

  my_printf(0, "Entrez les couleurs RGB :\n");
  tmp.color = get_rgb(0, 0, NULL);
  my_printf(0, "Reflection :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp.reflect = my_getnbr(str);
  free(str);
  my_printf(1, "Coefficient de bump mapping (conseil : > 0 && < 1) :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp.bump = my_atof(str);
  free(str);
  my_printf(1, "Entrez le chemin de l'éventuel texture :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp.texture_path = ((str[0] != 0) ? (str) : ("NULL"));
  push_mat(prog, tmp);
  return (0);
}
