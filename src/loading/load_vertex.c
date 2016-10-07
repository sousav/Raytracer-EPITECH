/*
** load_vertex.c for  in /home/sousa_v/rendu/lapin/raytracer_tmp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 25 23:13:37 2016 Victor Sousa
** Last update Mon May 16 17:58:04 2016 Philippe Lefevre
*/

#include		"main.h"

int			where_are_vertex(char **file)
{
  int			i;

  i = 0;
  while (file[i][0] != 'v')
    i++;
  return (i);
}

t_coord			get_vertex_line(char *_str)
{
  t_coord		out;
  char			*str;

  str = _str + 1;
  while (*str == ' ')
    str++;
  out.x = my_get_float(str);
  while (*str != ' ')
    str++;
  while (*str == ' ')
    str++;
  out.y = my_get_float(str);
  while (*str != ' ')
    str++;
  while (*str == ' ')
    str++;
  out.z = my_get_float(str);
  return (out);
}

t_vtx_list		*add_end_vtx(t_vtx_list *head, t_coord vtx)
{
  t_vtx_list		*new;
  t_vtx_list		*tmp;

 if ((new = malloc(sizeof(t_vtx_list))) == NULL)
    return (NULL);
  new->vtx = vtx;
  new->next = NULL;
  if (head == NULL)
    return (new);
  else
    {
      tmp = head;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      return (head);
    }
}

t_vtx_list		*get_vertex(char **file)
{
  t_vtx_list		*out;
  int			i;
  t_coord		cur;

  out = NULL;
  i = where_are_vertex(file);
  while (file[i])
     {
      if (file[i][0] == 'v' && file[i][1] == ' ')
	{
	  cur = get_vertex_line(file[i]);
	  if ((out = add_end_vtx(out, cur)) == NULL)
	    return (NULL);
	}
      i++;
    }
  return (out);
}

t_coord			get_vertex_in_list(t_vtx_list *list, int id, int *flag)
{
  int			i;
  t_vtx_list		*tmp;

  i = 1;
  tmp = list;
  while (tmp != NULL && i < id)
    {
      tmp = tmp->next;
      i++;
    }
  if (tmp == NULL)
    {
      *flag = -1;
      return (list->vtx);
    }
  return (tmp->vtx);
}
