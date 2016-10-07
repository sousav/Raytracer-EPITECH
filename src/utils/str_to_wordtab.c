/*
** str_to_wordtab.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Apr 25 05:57:13 2016 Ethan Kerdelhue
** Last update Mon May 16 09:58:42 2016 Philippe Lefevre
*/

#include 	"main.h"

char		check(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    if (delim[i] == c)
      return (0);
  return (c);
}

int		countchars(char *str, char *delim)
{
  int		i;

  i = 0;
  while (check(str[i], delim))
    i++;
  return (i + 1);
}

int		countwords(char *str, char *delim)
{
  int		i;
  int		count;

  i = -1;
  count = 1;
  while (str[++i])
    if (!check(str[i], delim))
      {
	count++;
	while (str[i] && !check(str[i], delim))
	  i++;
	i--;
      }
return (count + 1);
}

char		**str_to_wordtab(char *str, char *delim)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  j = -1;
  if ((tab = malloc(countwords(str, delim) * sizeof(char *))) == NULL)
    return (NULL);
  while (str[i] && !check(str[i], delim))
    i++;
  while (str[i])
    {
      if ((tab[++j] = malloc(countchars(&str[i], delim)))== NULL)
	return (NULL);
      k = -1;
      while (check(str[i], delim))
	tab[j][++k] = str[i++];
      tab[j][++k] = 0;
      while (str[i] && !check(str[i], delim))
	i++;
    }
  tab[++j] = NULL;
  return (tab);
}
