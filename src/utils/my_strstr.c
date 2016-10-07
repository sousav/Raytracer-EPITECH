/*
** my_strstr.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 07:36:05 2016 victor sousa
** Last update Sun May  8 04:24:09 2016 Philippe Lefevre
*/

#include	"main.h"

char		*my_strstr(char *str, char *to_find)
{
  int		i;

  if (str[0] != '\0')
    {
      i = 0;
      while (to_find[i] != '\0')
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  i = i + 1;
	}
      return (str);
    }
  else
    return (0);
}
