/*
** add_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May  2 17:19:25 2016 Ethan Kerdelhue
** Last update Mon May 16 07:12:10 2016 Philippe Lefevre
*/

#include		"main.h"

int			check_material_id(t_prog *prog, char m_id)
{
  t_mat_list		*tmp;

  tmp = prog->mat_list;
  while (tmp != NULL)
    {
      if ((int) m_id == tmp->id)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_coord			*get_coord(t_coord *tmp)
{
  char			*str;

  my_printf(1, "x :\n");
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  tmp->x = my_atof(str);
  free(str);
  my_printf(1, "y :\n");
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  tmp->y = my_atof(str);
  free(str);
  my_printf(1, "z :\n");
  if ((str = get_next_line(0)) == NULL)
    return (NULL);
  tmp->z = my_atof(str);
  free(str);
  return (tmp);
}

char			get_material(t_prog *prog)
{
  char			*str;
  int			flag;
  int			val;

  flag = 0;
  while (flag != 1)
    {
      my_printf(1, "material id :\n");
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      val = (char) my_getnbr(str);
      if (check_material_id(prog, (char) val) == 1)
	flag = 1;
      else
	my_printf(1, "material_id %d do not exist !\n", (int) val);
    }
  return (val);
}

int			add_obj_triangle(t_prog *prog)
{
  t_triangle 		tmp;

  my_printf(1, "Coordonée du premier point du triangle\n");
  if ((get_coord(&tmp.angle[0])) == NULL)
    return (-1);
  my_printf(1, "Coordonée du deuxième point du triangle\n");
  if ((get_coord(&tmp.angle[1])) == NULL)
    return (-1);
  my_printf(1, "Coordonée du troisième point du triangle\n");
  if ((get_coord(&tmp.angle[2])) == NULL)
    return (-1);
  if ((tmp.material = get_material(prog)) == -1)
    return (-1);
  push_triangle(prog, tmp);
  return (0);
}

int			add_obj_sphere(t_prog *prog)
{
  t_sphere		tmp;
  char			*str;

  my_printf(1, "Coordonée du point central :\n");
  get_coord(&tmp.center);
  my_printf(1, "rayon :\n");
  str = get_next_line(0);
  tmp.radius = my_getnbr(str);
  free(str);
  tmp.material = get_material(prog);
  if ((push_sphere(prog, tmp)) == -1)
    return (-1);
  return (0);
}
