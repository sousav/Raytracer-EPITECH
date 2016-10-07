/*
** edit_cam.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr 29 22:08:18 2016 Ethan Kerdelhue
** Last update Wed May 11 14:57:00 2016 Philippe Lefevre
*/

#include		"main.h"

int			edit_cam_bis(t_prog *prog, char *str)
{
  my_printf(1, "Chemin du background :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  prog->background_path = ((str[0] != 0) ? (str) : (prog->background_path));
  return (0);
}

int			edit_cam(t_prog *prog)
{
  char			*str;

  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  if (aff_win_prop(0, prog) == -1)
    return (-1);
  my_printf(1, "Laissez vide pour concerver la valeur\nScreen size\n");
  if (edit_win(prog) || edit_cam_pos(prog))
    return (-1);
  my_printf(1, "Champs de vision (field of view)\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (str[0] != '\0')
    {
      prog->cam_fov.x = my_getnbr(str);
      prog->cam_fov.y = prog->cam_fov.x *
	  ((prog->win_size.x / prog->win_size.y) / 1.5);
    }
  my_printf(1, "Anti-aliasing :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  prog->anti_alias = ((str[0] != 0) ? (my_getnbr(str)) : (prog->anti_alias));
  free(str);
  return (edit_cam_bis(prog, str));
}
