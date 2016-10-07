/*
** add_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May  2 17:19:25 2016 Ethan Kerdelhue
** Last update Mon May 16 07:12:01 2016 Philippe Lefevre
*/

#include		"main.h"

int			add_obj(t_prog *prog)
{
  char			*str;

  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  my_printf(1, "Quelle objet voulez-vous rajoutez ?\n\n 1 - Sphere\n");
  my_printf(1, " 2 - Triangle\n 3 - Plan\n 4 - Cone\n 5 - Cylindre\n 6 \
	    - Cercle\n 7 - Pillule\n");
  str = get_next_line(0);
  if (my_strcmp(str, "1") == 0)
    add_obj_sphere(prog);
  else if (my_strcmp(str, "2") == 0)
    add_obj_triangle(prog);
  else if (my_strcmp(str, "3") == 0)
    add_obj_plan(prog);
  else if (my_strcmp(str, "4") == 0)
    add_obj_cone(prog);
  else if (my_strcmp(str, "5") == 0)
    add_obj_cylindre(prog);
  else if (my_strcmp(str, "6") == 0)
    add_obj_circle(prog);
  else if (my_strcmp(str, "7") == 0)
    add_obj_cylindre(prog);
  else
    my_printf(1, "Error : Your choice has no result\n");
  return (0);
}
