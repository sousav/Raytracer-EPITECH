/*
** edit_cam.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Fri Apr 29 22:08:18 2016 Ethan Kerdelhue
** Last update Wed May 11 14:39:58 2016 Philippe Lefevre
*/

#include		"main.h"

int			edit_win_size_x(t_prog *prog)
{
  char			*str;
  int			flag;
  int			val;

  val = 0;
  flag = 0;
  my_printf(1, "Width size (x)\n");
  while (flag != 1)
    {
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      val = my_getnbr(str);
      if ((val >= 1 && val <= 1980) || str[0] == '\0')
	{
	  if (str[0] == '\0')
	    prog->win_size.x = prog->win_size.x;
	  else
	    prog->win_size.x = val;
	  flag = 1;
        }
      else
	my_printf(1, "Error : la valeur doit être comprise entre 1 et 1980\n");
      free(str);
    }
  return (0);
}

int			edit_win_size_y(t_prog *prog)
{
  char			*str;
  int			flag;
  int			val;

  val = 0;
  flag = 0;
  my_printf(1, "Height size (y)\n");
  while (flag != 1)
    {
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      val = my_getnbr(str);
      if ((val >= 1 && val <= 1080) || str[0] == '\0')
	{
	  if (str[0] == '\0')
	    prog->win_size.y = prog->win_size.y;
	  else
	    prog->win_size.y = val;
	  flag = 1;
        }
      else
	my_printf(1, "Error : la valeur doit être comprise entre 1 et 1080\n");
      free(str);
    }
  return (0);
}

int			edit_win(t_prog *prog)
{
  if ((edit_win_size_x(prog)) == -1)
    return (-1);
  if ((edit_win_size_y(prog)) == -1)
    return (-1);
  return (0);
}

int			edit_point(t_point *tmp)
{
  char			*str;

  my_printf(1, "x :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp->x = ((str[0] != '\0') ? (my_getnbr(str)) : (tmp->x));
  free(str);
  my_printf(1, "y :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp->y = ((str[0] != '\0') ? (my_getnbr(str)) : (tmp->y));
  free(str);
  my_printf(1, "z :\n");
  if ((str = get_next_line(0)) == NULL)
    return (-1);
  tmp->z = ((str[0] != '\0') ? (my_getnbr(str)) : (tmp->z));
  return (0);
}

int			edit_cam_pos(t_prog *prog)
{
  my_printf(1, "Position de la caméra\n");
  if ((edit_point(&prog->cam_pos)) == -1)
    return (-1);
  my_printf(1, "Regard de la caméra\n");
  if ((edit_point(&prog->cam_pos)) == -1)
    return (-1);
  return (0);
}
