/*
** my_strcat.c for strcat in /Users/leandr_g/Documents/Shared folder/Raytracer/src/editeur/my_sprintf/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed May  4 01:44:32 2016 Gaëtan Léandre
** Last update Tue May 10 18:15:36 2016 Gaëtan Léandre
*/

#include	"server.h"

char		*my_strcatprint(char *a, char *b)
{
  int		i;
  int		j;
  char		*str;

  if (a == NULL || b == NULL)
    return (NULL);
  if ((str = malloc(my_strlen(a) + my_strlen(b) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      str[i] = a[i];
      i++;
    }
  j = 0;
  while (b[j])
    str[i++] = b[j++];
  str[i] = '\0';
  free(a);
  free(b);
  return (str);
}

char		*my_strcatnofree(char *a, char *b)
{
  int		i;
  int		j;
  char		*str;

  if (a == NULL || b == NULL)
    return (NULL);
  if ((str = malloc(my_strlen(a) + my_strlen(b) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      str[i] = a[i];
      i++;
    }
  j = 0;
  while (b[j])
    str[i++] = b[j++];
  str[i] = '\0';
  free(a);
  return (str);
}

char		*my_strcatchar(char *a, char b)
{
  int		i;
  char		*str;

  if (a == NULL)
    return (NULL);
  if ((str = malloc(my_strlen(a) + 2)) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      str[i] = a[i];
      i++;
    }
  str[i++] = b;
  str[i] = '\0';
  free (a);
  return (str);
}

char		*malloc_and_init()
{
  char		*str;

  if ((str = malloc(1)) == NULL)
    return (NULL);
  str[0] = '\0';
  return (str);
}
