/*
** utils.c for utils in /Users/leandr_g/Documents/Shared folder/testServer/commun/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat May  7 05:04:52 2016 Gaëtan Léandre
** Last update Mon May 16 11:17:04 2016 Gaëtan Léandre
*/

#include		"utils.h"

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char			*my_strdup(char *str)
{
  char			*result;
  int			i;

  if ((result = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    result[i] = str[i];
  result[i] = '\0';
  return (result);
}

int			my_strcmp(char *a, char *b)
{
  int			i;

  i = 0;
  while (a[i] || b[i])
    {
      if (a[i] != b[i])
	return (0);
      i++;
    }
  return (1);
}

char			**is_command(char *str)
{
  int			i;

  i = 0;
  if (my_strlen(str) > 0)
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      if (str[i] == '/')
	return (str_to_wordtab(&str[i + 1], " "));
    }
  return (NULL);
}

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i])
    {
      free(tab[i++]);
    }
  free(tab);
}
