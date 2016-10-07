/*
** parsing_scene.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 04:25:03 2016 victor sousa
** Last update Sun May 22 16:55:09 2016 Philippe Lefevre
*/

#include		"main.h"

t_line_list		*add_line_list(t_line_list *head, char *str)
{
  t_line_list		*new;
  t_line_list		*tmp;

  if ((new = malloc(sizeof(t_line_list))) == NULL)
    return (NULL);
  new->str = str;
  new->next = NULL;
  if (head == NULL)
    return new;
  else
    {
      tmp = head;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      return (head);
    }
}

int			list_len(t_line_list *list)
{
  int			i;
  t_line_list		*tmp;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}

char			**my_list_to_wordtab(t_line_list *list)
{
  char			**out;
  t_line_list		*tmp;
  int			i;

  if ((out = malloc(sizeof(char *) * (list_len(list) + 1))) == NULL)
    return (NULL);
  tmp = list;
  i = 0;
  while (tmp != NULL)
    {
      out[i] = tmp->str;
      tmp = tmp->next;
      i++;
    }
  out[i] = '\0';
  return (out);
}

char			**load_scene_file(char *path, int i, int fd,
					  int verbose)
{
  char			*str;
  char			**file;
  t_line_list		*file_list;
  time_t		time_beg;
  time_t		time_end;

  time_beg = time(NULL);
  if ((fd = open(path, O_RDONLY)) == -1)
    return (NULL);
  file_list = NULL;
  while ((str = get_next_line_size(fd, 0)) != NULL)
    file_list = add_line_list(file_list, str);
  time_end = time(NULL);
  if (verbose)
    my_printf(1, "Open/Read en %d heures %d minutes %d secondes\n",
	      (time_end - time_beg) / 3600, ((time_end - time_beg) % 3600)
	      / 60, ((time_end - time_beg) % 3600) % 60);
  if ((file = my_list_to_wordtab(file_list)) == NULL)
    return (NULL);
  while (file[++i])
    if ((file[i] = epur_str(file[i], " \t\n")) == NULL)
      return (NULL);
  close(fd);
  return (file);
}
