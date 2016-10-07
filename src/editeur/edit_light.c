/*
** edit_light.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr 29 23:03:14 2016 Ethan Kerdelhue
** Last update Mon May  2 22:48:43 2016 Ethan Kerdelhue
*/

#include		"main.h"

t_light_list		*get_ptr_light(t_prog *prog, int id)
{
  t_light_list		*tmp;
  int			i;

  tmp = prog->light_list;
  i = 0;
  while (id != i)
    {
      i++;
      tmp = tmp->next;
    }
  return (tmp);
}

int			check_light_id(t_prog *prog, int id)
{
  t_light_list		*tmp;
  int			i;

  i = 0;
  tmp = prog->light_list;
  while (tmp != NULL)
    {
      i++;
      if (id == i)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int			select_light(t_prog *prog)
{
  int			flag;
  char			*str;
  int			id;

  my_printf(1, "Selectionnez la lumière :\n");
  flag = 0;
  while (flag != 1)
    {
      my_printf(1, "Entrez l'id de l'objet a modifier (ex : 1 pour obj1):\n");
      str = get_next_line(0);
      id = count_light(prog) - my_getnbr(str);
      if (check_light_id(prog, id) != 1)
	my_printf(1, "l'id %d n'existe pas !", (count_object(prog) - id));
      else
       flag = 1;
    }
  return (id);
}

int			edit_light(t_prog *prog)
{
  t_light_list		*light;
  int			id;
  char			*str;

  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  my_printf(1, "Entrez l'id de la lumière a modifier\n");
  id = count_material(prog) - select_light(prog);
  if ((light = get_ptr_light(prog, id)) == NULL)
    return (-1);
  aff_light(0, light);
  edit_coord(&light->center);
  my_printf(1, "Intensiter :\n");
  str = get_next_line(0);
  light->intensity = (str[0] != '\0') ? (my_getnbr(str)) : (light->intensity);
  return (-1);
}
