/*
** my_strcat.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Mar  8 17:58:27 2016 victor sousa
** Last update Sun May 22 19:02:09 2016 Philippe Lefevre
*/

#include		"main.h"

char			*my_strdup(char *str)
{
  char			*s;

  if ((s = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  my_strcpy(s, str);
  return (s);
}

char			*my_strcpy(char *dest, char *src)
{
  int			i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char			*my_strcat(char *dest, char *src)
{
  int			len;
  int			i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}

char			*my_strcatpp(char *dest, char *src)
{
  char			*new;
  int			i;
  int			j;

  i = -1;
  j = 0;
  if ((new = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest[++i])
    new[i] = dest[i];
  while (src[j])
    {
      new[i] = src[j++];
      i++;
    }
  new[i] = 0;
  return (new);
}
