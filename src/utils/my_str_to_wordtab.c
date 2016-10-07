/*
** my_str_to_wordtab.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 06:07:29 2016 victor sousa
** Last update Mon May 16 08:26:50 2016 Philippe Lefevre
*/

#include	"main.h"

int		line_counter(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    if (str[i++] == '\n')
      count++;
  return (count);
}

char		**my_str_to_wordtab(char *str, int i, int j)
{
  int		k;
  char		**tab;

  tab = malloc(sizeof(char *) * (line_counter(str) + 1));
  i = 0;
  j = 0;
  while (i < line_counter(str))
    {
      if ((tab[i] = malloc(sizeof(char) * 2)) == NULL)
	return (NULL);
      k = 0;
      while (str[j] && str[j] != '\n')
	{
	  tab[i][k] = str[j];
	  tab[i][k++ + 1] = 0;
	  if ((tab[i] = realloc(tab[i], sizeof(char) *
				(my_strlen(tab[i]) + 2))) == NULL)
	    return (NULL);
	  j++;
	}
      tab[i++][k] = 0;
      j++;
    }
  tab[i] = 0;
  return (tab);
}
