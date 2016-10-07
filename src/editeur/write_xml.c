/*
** write_xml.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:08:41 2016 Ethan Kerdelhue
** Last update Mon May 16 07:59:05 2016 Philippe Lefevre
*/

#include		"main.h"

int			write_fd_xml(int fd, t_prog *prog)
{
  my_printf(fd, "<scene>\n");
  aff_win_prop(fd, prog);
  aff_mat_list(fd, prog);
  aff_obj_list(fd, prog);
  aff_light_list(fd, prog);
  my_printf(fd, "</scene>\n");
  return (0);
}

int			write_xml(t_prog *prog)
{
  int			fd;

  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  if ((fd = open(prog->editor->arg[1], O_WRONLY | O_CREAT, 0666)) == -1)
    {
      my_printf(1, "Error : Could not open specified path.");
      return (-1);
    }
  write_fd_xml(fd, prog);
  return (0);
}
