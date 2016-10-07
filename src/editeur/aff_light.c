/*
** aff_light.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/my_printf/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:03:21 2016 Ethan Kerdelhue
** Last update Sat Apr 30 22:39:37 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			aff_light(int fd, t_light_list *light)
{
  my_printf(fd, "\t\t<center>\n\t\t\t<x>%f</x>\n", light->center.x);
  my_printf(fd, "\t\t\t<y>%f</y>\n\t\t\t<z>%f</z>\n\t\t</center>\n",
	    light->center.y, light->center.z);
  my_printf(fd, "\t\t<intensity>%d</intensity>\n", light->intensity);
  return (0);
}

int			aff_light_list(int fd, t_prog *prog)
{
  int			i;
  t_light_list		*tmp;

  i = count_light(prog);
  tmp = prog->light_list;
  my_printf(fd, "\t<light_list>\n");
  my_printf(fd, "\t\t<count>%d</count>\n", count_light(prog));
  while (tmp != NULL)
    {
      my_printf(fd, "\t<light%d>\n", i);
      aff_light(fd, tmp);
      my_printf(fd, "\t</light%d>\n", i);
      i--;
      tmp = tmp->next;
    }
  my_printf(fd, "\t</light_list>\n");
  return (0);
}
