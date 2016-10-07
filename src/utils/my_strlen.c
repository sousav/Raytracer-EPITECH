/*
** my_strlen.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 05:30:17 2016 victor sousa
** Last update Sun May  8 04:32:00 2016 Philippe Lefevre
*/

#include		"main.h"

int			my_strcmp(char *s1, char *s2)
{
  int			i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;
  int	s1_size;
  int	s2_size;

  i = 0;
  s1_size = my_strlen(s1);
  s2_size = my_strlen(s2);
  while (i <= s1_size || i <= s2_size)
    {
      if (i < nb)
	{
	  if (s1[i] == s2[i])
	    i = i + 1;
	  else
	    return (s1[i] - s2[i]);
	}
      else
	return (0);
    }
  return (0);
}
