/*
** aff_win.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:06:01 2016 Ethan Kerdelhue
** Last update Wed May  4 21:56:21 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			aff_win_prop(int fd, t_prog *prog)
{
  my_printf(fd, "\t<view>\n");
  my_printf(fd, "\t\t<x_size>");
  my_printf(fd, "%d", prog->win_size.x);
  my_printf(fd, "</x_size>\n");
  my_printf(fd, "\t\t<y_size>");
  my_printf(fd, "%d", prog->win_size.y);
  my_printf(fd, "</y_size>\n");
  my_printf(fd, "\t\t<cam_pos>\n\t\t\t<x>%d</x>\n", prog->cam_pos.x);
  my_printf(fd, "\t\t\t<y>%d</y>\n\t\t\t<z>%d</z>\n\t\t</cam_pos>\n",
	    prog->cam_pos.y, prog->cam_pos.z);
  my_printf(fd, "\t\t<look_at>\n\t\t\t<x>%d>/x>\n", prog->look_at.x);
  my_printf(fd, "\t\t\t<y>%d</y>\n\t\t\t<z>%d</z>\n\t\t</look_at>\n",
	    prog->look_at.y, prog->look_at.z);
  my_printf(fd, "\t\t<fov>%d</fov>\n", prog->cam_fov.x);
  my_printf(fd, "\t\t<alias>%d</alias>\n", prog->anti_alias);
  my_printf(fd, "\t\t<background>%s</background>\n", prog->background_path);
  my_printf(fd, "\t</view>\n");
  return (0);
}
