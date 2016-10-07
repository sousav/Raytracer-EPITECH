/*
** count.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/my_printf/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:04:04 2016 Ethan Kerdelhue
** Last update Tue May  3 00:15:47 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			count_material(t_prog *prog)
{
  int			i;
  t_mat_list		*tmp;

  tmp = prog->mat_list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

int			count_object(t_prog *prog)
{
  int			i;
  t_obj_list		*tmp;

  tmp = prog->obj_list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

int			count_light(t_prog *prog)
{
  int			i;
  t_light_list		*tmp;

  tmp = prog->light_list;
  i = 0;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
