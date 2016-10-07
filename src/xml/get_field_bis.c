/*
** get_field_bis.c for raytracer in /home/lefevr_h/Workspace/Github/Raytracer/src/xml/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Wed May 11 14:28:02 2016 Philippe Lefevre
** Last update Wed May 11 14:28:33 2016 Philippe Lefevre
*/

#include	"main.h"

int		contains_char(char *str, char to_find)
{
  int		i;

  i = 0;
  while (str[i])
    if (str[i++] == to_find)
      return (i);
  return (-1);
}

int		how_much_char(char *str, char to_find)
{
  int		i;
  int		count;

  count = 1;
  i = 0;
  while (str[i])
    if (str[i++] == to_find)
      count++;
  return (count);
}
