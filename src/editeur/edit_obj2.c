/*
** edit_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 27 18:31:29 2016 Ethan Kerdelhue
** Last update Mon May 16 06:37:34 2016 Philippe Lefevre
*/

#include		"main.h"

int			aff_obj_spec(t_prog *prog, int id)
{
  int			i;
  t_obj_list		*tmp;

  i = 0;
  tmp = prog->obj_list;
  while (id != i)
    {
      i++;
      if (tmp->next)
	tmp = tmp->next;
      else
	{
	  my_printf(1, "Error : id %d don't found\n", id);
	  return (-1);
	}
    }
  my_printf(1, "\t<obj%d>\n", (count_object(prog) - id));
  my_printf(1, "\t\t<type>%s</type>\n", get_type(tmp->type));
  aff_obj(0, tmp);
  my_printf(1, "\t</obj%d>\n", (count_object(prog) - id));
  return (0);
}

int			check_obj_id(t_prog *prog, int id)
{
  t_obj_list		*tmp;
  int			i;

  i = 0;
  tmp = prog->obj_list;
  while (tmp != NULL)
    {
      if (i == id)
	return (1);
      i++;
      tmp = tmp->next;
    }
  if (i == id)
    return (1);
  return (0);
}

t_obj_list		*get_obj_ptr(t_prog *prog, int id)
{
  t_obj_list		*tmp;
  int			i;

  i = 0;
  tmp = prog->obj_list;
  while (id != i)
    {
      i++;
      tmp = tmp->next;
    }
  return (tmp);
}

int			edit_coord(t_coord *tmp)
{
  char			*str;

  my_printf(1, "x :\n");
  str = get_next_line(0);
  tmp->x = ((str[0] != '\0') ? (my_atof(str)) : (tmp->x));
  free(str);
  my_printf(1, "y :\n");
  str = get_next_line(0);
  tmp->y = ((str[0] != '\0') ? (my_atof(str)) : (tmp->y));
  free(str);
  my_printf(1, "z :\n");
  str = get_next_line(0);
  tmp->z = ((str[0] != '\0') ? (my_atof(str)) : (tmp->z));
  return (0);
}

char			edit_material_id(t_prog *prog, char mat)
{
  char			flag;
  char			tmp;
  char			*str;

  flag = 0;
  while (flag != 1)
    {
      my_printf(1, "material id :\n");
      str = get_next_line(0);
      if ((check_material_id(prog, my_getnbr(str)) == 1) || str[0] == '\0')
	{
	  if (str[0] == '\0')
	    tmp = mat;
	  else
	    tmp = (char) my_getnbr(str);
	  flag = 1;
	}
      else
	my_printf(1, "Error : material id %d don't exist\n", my_getnbr(str));
      free(str);
    }
  return (tmp);
}
