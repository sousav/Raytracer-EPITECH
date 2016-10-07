/*
** add_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May  2 17:19:25 2016 Ethan Kerdelhue
** Last update Mon May 16 07:15:24 2016 Philippe Lefevre
*/

#include		"main.h"

int			add_obj_plan(t_prog *prog)
{
  t_plan		plan;

  my_printf(1, "Entrez les coordonées centre du plan :\n");
  get_coord(&plan.center);
  my_printf(1, "Entrez les coordonées de direction du plan :\n");
  get_coord(&plan.dir);
  my_printf(1, "Material 1 :\n");
  if ((plan.material = get_material(prog)) == -1)
    return (-1);
  my_printf(1, "Material 2 :\n");
  if ((plan.material2 = get_material(prog)) == -1)
    return (-1);
  push_plan(prog, plan);
  return (0);
}

int			add_obj_cone(t_prog *prog)
{
  t_cone		cone;
  char			*str;

  my_printf(1, "Entrez les coordonées centre du cone :\n");
  get_coord(&cone.center);
  my_printf(1, "Entrez les coordonées de direction du cone :\n");
  get_coord(&cone.dir);
  my_printf(1, "Entrez le rayon:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  cone.radius = my_getnbr(str);
  free(str);
  my_printf(1, "Entrez la hauteur:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  cone.height = my_getnbr(str);
  free(str);
  if ((cone.material = get_material(prog)) == -1)
    return (-1);
  push_cone(prog, cone);
  return (0);
}

int			add_obj_cylindre(t_prog *prog)
{
  t_cylin		cylindre;
  char			*str;

  my_printf(1, "Entrez les coordonées centre du cylindre :\n");
  get_coord(&cylindre.center);
  my_printf(1, "Entrez les coordonées de direction du cylindre :\n");
  get_coord(&cylindre.dir);
  my_printf(1, "Entrez le rayon:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  cylindre.radius = my_getnbr(str);
  free(str);
  my_printf(1, "Entrez la hauteur:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  cylindre.height = my_getnbr(str);
  free(str);
  if ((cylindre.material = get_material(prog)) == -1)
    return (-1);
  push_cylindre(prog, cylindre);
  return (0);
}

int			add_obj_pillule(t_prog *prog)
{
  t_cylin		pill;
  char			*str;

  my_printf(1, "Entrez les coordonées centre du pillule :\n");
  get_coord(&pill.center);
  my_printf(1, "Entrez les coordonées de direction du pillule :\n");
  get_coord(&pill.dir);
  my_printf(1, "Entrez le rayon:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  pill.radius = my_getnbr(str);
  free(str);
  my_printf(1, "Entrez la hauteur:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  pill.height = my_getnbr(str);
  free(str);
  if ((pill.material = get_material(prog)) == -1)
    return (-1);
  push_pillule(prog, pill);
  return (0);
}

int			add_obj_circle(t_prog *prog)
{
  t_circle		circle;
  char			*str;

  my_printf(1, "Entrez les coordonées du centre du cercle :\n");
  get_coord(&circle.plan.center);
  my_printf(1, "Entrez les coordonées de direction du cercle :\n");
  get_coord(&circle.plan.dir);
  my_printf(1, "Entrez le rayon:\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  circle.radius = my_getnbr(str);
  free(str);
  if ((circle.material = get_material(prog)) == -1)
      return (-1);
  push_circle(prog, circle);
  return (0);
}
