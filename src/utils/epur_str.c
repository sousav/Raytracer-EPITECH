/*
** epur_str.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Apr 25 22:53:30 2016 Gaëtan Léandre
** Last update Mon Apr 25 23:34:11 2016 Gaëtan Léandre
*/

#include 	"main.h"

int		is_separator(char c, char *separ)
{
  int		i;

  i = 0;
  while (separ && separ[i])
    {
      if (separ[i] == c)
	return (1);
      i++;
    }
  return (-1);
}

int		count_size(char *str, char *separ)
{
  int		i;
  int		size;

  i = 0;
  size = 0;
  while (str[i])
    {
      if ((is_separator(str[i], separ) == 1 && str[i + 1] != '\0'
	   && is_separator(str[i + 1], separ) == -1)
	  || is_separator(str[i], separ) == -1)
	size++;
      i++;
    }
  return (size);
}

char		*epur_str(char *str, char *separ)
{
  char		*new;
  int		i;
  int		j;

  if ((new = malloc(sizeof(char) * (count_size(str, separ) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
    {
      if ((is_separator(str[i], separ) == 1 && str[i + 1] != '\0'
	   && is_separator(str[i + 1], separ) == -1))
	new[j++] = ' ';
      else if (is_separator(str[i], separ) == -1)
	new[j++] = str[i];
     i++;
    }
  new[j] = '\0';
  free(str);
  return (new);
}
