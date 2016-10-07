/*
** my_getnbr.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 08:36:58 2016 victor sousa
** Last update Mon Apr 25 21:04:04 2016 Ethan Kerdelhue
*/

#include	"main.h"

int		my_getnbr(char *str)
{
  int		sign;
  int		result;

  sign = 1;
  result = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = - sign;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (result > 214748364)
	return (0);
      if (result == 214748364 && *str > 7 && sign == 1)
	return (0);
      if (result == 214748364 && *str > 8 && sign == -1)
	return (0);
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  if (sign == -1)
    result = - result;
  return (result);
}

char		*my_itoa(int nb)
{
  int		len;
  char		*str;
  int		tmp;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
