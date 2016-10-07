/*
** my_realloc.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Tue Feb  9 05:25:59 2016 victor sousa
** Last update Fri Mar 11 00:19:38 2016 victor sousa
*/

#include	"main.h"

char		*my_realloc(char *str, int size)
{
  char		*output;
  int		i;

  if ((output = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      output[i] = str[i];
      ++i;
    }
  output[i] = 0;
  free(str);
  return (output);
}
