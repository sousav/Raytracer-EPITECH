/*
** add_light.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Apr 27 18:13:39 2016 Ethan Kerdelhue
** Last update Mon May  2 22:47:46 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			push_light(t_prog *prog, t_light_list light)
{
  t_light_list		*tmp;
  t_light_list		*new;

  tmp = prog->light_list;
  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (-1);
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->center = light.center;
  new->intensity = light.intensity;
  new->next = NULL;
  return (0);
}

int			add_light_s(t_prog *prog)
{
  t_light_list		tmp;
  char 			*str;

  my_printf(1, "Entrez le point de la camera:\n");
  get_coord(&tmp.center);
  my_printf(1, "Intensiter :\n");
  str = get_next_line(0);
  tmp.intensity = my_getnbr(str);
  free(str);
  push_light(prog, tmp);
  return (0);
}
