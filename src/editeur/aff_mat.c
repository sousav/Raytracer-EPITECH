/*
** aff_mat.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 09:58:25 2016 Ethan Kerdelhue
** Last update Thu May  5 10:09:20 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			aff_mat(int fd, t_mat_list *mat)
{
  my_printf(fd, "\t\t<red>%d</red>\n", mat->color.argb[RED_CMP]);
  my_printf(fd, "\t\t<green>%d</green>\n", mat->color.argb[GREEN_CMP]);
  my_printf(fd, "\t\t<blue>%d</blue>\n", mat->color.argb[BLUE_CMP]);
  my_printf(fd, "\t\t<reflect>%d</reflect>\n", mat->reflect);
  my_printf(fd, "\t\t<bump>%f</bump>\n", mat->bump);
  my_printf(fd, "\t\t<texture>%s</texture>\n", mat->texture_path);
  return (0);
}

int			aff_mat_list(int fd, t_prog *prog)
{
  char			*id;
  t_mat_list		*tmp;

  tmp = prog->mat_list;
  my_printf(fd, "\t<material_list>\n");
  my_printf(fd, "\t\t<count>");
  my_printf(fd, "%d", count_material(prog));
  my_printf(fd, "</count>\n");
  while (tmp != NULL)
    {
      id = my_strcatpp("mat", my_itoa(tmp->id));
      my_printf(fd, "\t<");
      my_printf(fd, id);
      my_printf(fd, ">\n");
      aff_mat(fd, tmp);
      my_printf(fd, "\t</");
      my_printf(fd, id);
      my_printf(fd, ">\n");
      tmp = tmp->next;
      free(id);
    }
  my_printf(fd, "\t</material_list>\n");
  return (0);
}
