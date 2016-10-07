/*
** edit_obj.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 27 18:31:29 2016 Ethan Kerdelhue
** Last update Mon May 16 06:34:25 2016 Philippe Lefevre
*/

#include		"main.h"

int			edit_sphere(t_prog *prog, t_sphere *sph)
{
  char 			*str;

  my_printf(1, "Laissez vide pour oncerver la valeur\nPoint du centre :\n");
  edit_coord(&sph->center);
  my_printf(1, "radius :\n");
  str = get_next_line(0);
  sph->radius = ((str[0] != '\0') ? (my_getnbr(str)) : (sph->radius));
  free(str);
  sph->material = edit_material_id(prog, sph->material);
  return (0);
}

int			edit_plan(t_prog *prog, t_plan *pla)
{
  my_printf(1, "Laissez vide si vous voulez concerver la valeur\n");
  my_printf(1, "Point central du plan :\n");
  edit_coord(&pla->center);
  my_printf(1, "Direction du plan :\n");
  edit_coord(&pla->dir);
  my_printf(1, "Materiel 1 :\n");
  pla->material = edit_material_id(prog, pla->material);
  my_printf(1, "Materiel 2 :\n");
  pla->material2 = edit_material_id(prog, pla->material2);
  return (0);
}

int			edit_triangle(t_prog *prog, t_triangle *tri)
{
  my_printf(1, "Laissez vide si vous voulez concerver la valeur\n");
  my_printf(1, "Premier point du triangle :\n");
  edit_coord(&tri->angle[0]);
  my_printf(1, "Second point du triangle :\n");
  edit_coord(&tri->angle[1]);
  my_printf(1, "Troisième point du triangle :\n");
  edit_coord(&tri->angle[2]);
  tri->material = edit_material_id(prog, tri->material);
  return (0);
}

int			edit_cylindre(t_prog *prog, t_cylin *cyl)
{
  char			*str;

  my_printf(1, "Laissez vide si vous voulez concerver la valeur\n");
  my_printf(1, "Coordonées de centre\n");
  edit_coord(&cyl->center);
  my_printf(1, "Coordonées de direction\n");
  edit_coord(&cyl->dir);
  my_printf(1, "Entrez le rayon");
  str = get_next_line(0);
  cyl->radius = ((str[0] != 0) ? (my_getnbr(str)) : (cyl->radius));
  free(str);
  my_printf(1, "Entrez la hauteur");
  str = get_next_line(0);
  cyl->height = ((str[0] != 0) ? (my_getnbr(str)) : (cyl->height));
  free(str);
  cyl->material = edit_material_id(prog, cyl->material);
  return (0);
}

int			edit_cone(t_prog *prog, t_cone *con)
{
  char			*str;

  my_printf(1, "Laissez vide si vous voulez concerver la valeur\n");
  my_printf(1, "Coordonées de centre\n");
  edit_coord(&con->center);
  my_printf(1, "Coordonées de direction\n");
  edit_coord(&con->dir);
  my_printf(1, "Entrez le rayon :\n");
  str = get_next_line(0);
  con->radius = ((str[0] != 0) ? (my_getnbr(str)) : (con->radius));
  free(str);
  my_printf(1, "Entrez la hauteur :\n");
  str = get_next_line(0);
  con->height = ((str[0] != 0) ? (my_getnbr(str)) : (con->height));
  free(str);
  con->material = edit_material_id(prog, con->material);
  return (0);
}
