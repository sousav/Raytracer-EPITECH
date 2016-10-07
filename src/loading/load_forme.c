/*
** load_forme.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/loading/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 25 23:38:14 2016 Gaëtan Léandre
** Last update Sat May 21 17:53:24 2016 Philippe Lefevre
*/

#include		"main.h"

int			where_are_formes(char **file)
{
  int			i;

  i = 0;
  while (file[i] && file[i][0] != 'f')
    i++;
  return (i);
}

int			get_sommet_size(char *str)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' && (i - 1 < 0 || str[i - 1] == ' '))
	j++;
      i++;
    }
  return (j - 1);
}

t_obj_list		*create_triangle(char *str, t_obj_list *prev,
					 t_vtx_list *list)
{
  t_obj_list            *new;
  t_triangle            *t;
  int			i;
  int			j;
  int			pos;

  if (((new = malloc(sizeof(t_obj_list))) == NULL)
      || ((t = malloc(sizeof(t_triangle))) == NULL))
    return (NULL);
  i = (j = 0) * 0;
  pos = 0;
  while (i < 3)
    {
      while (str[pos] != ' ')
	pos++;
      t->angle[i] = get_vertex_in_list(list, my_getnbr(&str[++pos]), &j);
      i++;
      if (j == -1)
	return (NULL);
    }
  t->material = 1;
  new->obj = t;
  new->type = 't';
  new->next = prev;
  return (new);
}
