/*
** my_disp_unprintable.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 14:59:18 2015 Gaëtan Léandre
** Last update Tue May 10 18:14:46 2016 Gaëtan Léandre
*/

#include "server.h"

char			*disp_unprintable_s(char *str)
{
  int			i;
  char			*result;

  if ((result = malloc_and_init()) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  result = my_strcatchar(result, '\\');
	  result = my_strcatprint(result,
				  my_putnbr_base_s(str[i], "01234567", 2));
	}
      else
	result = my_strcatchar(result, str[i]);
      i++;
    }
  return (result);
}
