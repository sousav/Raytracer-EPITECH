/*
** str_to_wordtab.c for str_to_wordtab in /Users/leandr_g/Documents/Shared folder/PSU_2015_minishell2/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr  9 01:06:04 2016 Gaëtan Léandre
** Last update Sat May 21 23:44:33 2016 Philippe Lefevre
*/

#include		"utils.h"

static int		is_separate(char c, char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

static char		*size_word(char *str, char *separate, int *i)
{
  char			*result;
  int			size;
  int			j;

  size = 0;
  j = *i;
  while (str[j] && is_separate(str[j], separate) == 0)
    {
      size++;
      j++;
    }
  if ((result = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[*i] && is_separate(str[*i], separate) == 0)
    {
      result[j] = str[*i];
      j++;
      (*i)++;
    }
  result[j] = '\0';
  return (result);
}

char			**str_to_wordtab(char *str, char *separate)
{
  char			**tab;
  int			words;
  int			i;

  words = 0;
  i = -1;
  while (str[++i])
    if (i - 1 < 0 || (is_separate(str[i], separate) == 1
		      && is_separate(str[i - 1], separate) == 0))
      words++;
  if (words == 0 || (tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  i = 0;
  words = 0;
  while (str[i])
    if (is_separate(str[i], separate) == 0)
      {
	if ((tab[words] = size_word(str, separate, &i)) == NULL)
	  return (NULL);
	words++;
      }
    else
      i++;
  tab[words] = NULL;
  return (tab);
}
