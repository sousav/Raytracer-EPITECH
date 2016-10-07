/*
** get_field.c for raytracer.c in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 05:02:48 2016 victor sousa
** Last update Mon May 16 10:24:36 2016 Philippe Lefevre
*/

#include	"server.h"

char		*get_next_occurence(char *str, char separator)
{
  int		i;
  char		*out;

  i = 0;
  while (str[i] && str[i] != separator)
    i++;
  if ((out = malloc(sizeof(char) * (i + 1))) == NULL)
	    {
	      my_printf(1, "Malloc failed..\n");
	      return (NULL);
	    }
  i = 0;
  while (str[i] && str[i] != separator)
    {
      out[i] = str[i];
      i++;
    }
  out[i] = 0;
  return (out);
}

char		*parse_value(char *str)
{
  char		*out;
  int	        i;
  int		j;

  i = 0;
  while (str[i] && str[i] != '>')
    i++;
  if ((out = malloc(sizeof(char) * 2)) == NULL)
    {
      my_printf(1, "Malloc failed..\n");
      return (NULL);
    }
  j = 0;
  while (str[++i] && str[i] != '<')
    {
      out[j] = str[i];
      out[j++ + 1] = 0;
      if ((out = realloc(out, sizeof(char) * (my_strlen(out) + 2))) == NULL)
	{
	  my_printf(1, "Malloc failed..\n");
	  return (NULL);
	}
    }
  return (out);
}

char		*get_field_end(char **scene, char **parent,
			       int i, int current)
{
  while (parent[i + ++current * 0])
    if (my_strstr(scene[current], parent[i]) != 0)
      i++;
    else if (my_strstr(scene[current], parent[(i > 0 ? i - 1 : 0)]) != 0)
      return (NULL);
  return (parse_value(scene[current - 1]));
}

char		*get_field(char **scene, char *field)
{
  char		**parent;
  int		field_decal;
  int		current;
  int		i;

  if ((parent = malloc(8 * (how_much_char(field, ':') + 1))) == NULL)
    {
      my_printf(1, "Malloc failed..\n");
      return (NULL);
    }
  i = 0;
  field_decal = 0;
  while (contains_char(field + field_decal, ':') != -1)
    {
      parent[i++] = get_next_occurence(field + field_decal, ':');
      field_decal += contains_char(field + field_decal, ':');
    }
  parent[i++] = get_next_occurence(field + field_decal, ':');
  parent[i] = 0;
  current = -1;
  i = 0;
  return (get_field_end(scene, parent, i, current));
}
