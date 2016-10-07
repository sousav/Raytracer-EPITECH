/*
** edit_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 27 18:31:29 2016 Ethan Kerdelhue
** Last update Mon May 16 07:09:37 2016 Philippe Lefevre
*/

#include		"main.h"

static int		edit_obj_select_1(t_prog *prog, t_obj_list *obj)
{
  if (obj->type == 's')
    edit_sphere(prog, (t_sphere *)obj->obj);
  if (obj->type == 't')
    edit_triangle(prog, (t_triangle *)obj->obj);
  if (obj->type == 'p')
    edit_plan(prog, (t_plan *)obj->obj);
  return (0);
}

static int		edit_obj_select_2(t_prog *prog, t_obj_list *obj)
{
  t_pill		*pill;

  if (obj->type == 'c')
    edit_cone(prog, (t_cone *)obj->obj);
  if (obj->type == 'y')
    edit_cylindre(prog, (t_cylin *)obj->obj);
  if (obj->type == 'l')
    {
      pill = (t_pill *)obj->obj;
      edit_cylindre(prog, pill->cylin);
    }
  return (0);
}

int			edit_obj(t_prog *prog)
{
  int			id;
  int			flag;
  char			*str;
  t_obj_list		*obj;

  flag = 0;
  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  while (flag != 1)
    {
      my_printf(1, "Entrez l'id de l'objet a modifier (ex : 1 pour obj1):\n");
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      id = (count_object(prog)) - my_getnbr(str);
      if (check_obj_id(prog, id) != 1 && id != count_object(prog))
	my_printf(1, "l'id %d n'existe pas !", (count_object(prog) - id));
      else
	flag = 1;
    }
  if ((aff_obj_spec(prog, id)))
    return (-1);
  obj = get_obj_ptr(prog, id);
  edit_obj_select_1(prog, obj);
  edit_obj_select_2(prog, obj);
  return (0);
}
