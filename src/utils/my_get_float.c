/*
** my_get_float.c for  in /home/sousa_v/rendu/lapin/raytracer_temp/src/utils/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 25 09:19:12 2016 Victor Sousa
** Last update Mon May 16 18:06:08 2016 Philippe Lefevre
*/

#include		"main.h"

float			my_get_float_end(char *str, float demical_digit,
					 float sign, float number)
{
  int			tmp;

  if (*str == '.')
    str++;
  while (*str >= '0' && *str <= '9' && *str != '\0')
    {
      tmp = *str - '0';
      number = number * 10.0 + tmp;
      str++;
      demical_digit *= 10.0;
    }
  if (sign > 0)
    return (number / demical_digit);
  return (sign*number / demical_digit);
}

float			my_get_float(char *str)
{
  float			number;
  float			demical_digit;
  float			sign;
  int			tmp;

  number = 0.0;
  demical_digit = 1.0;
  sign = 1.0;
  tmp = 0;
  if (str == NULL)
    return 0.0;
  if (*str == '-')
    {
      sign = -1.0;
      str++;
    }
  while (*str >= '0' && *str <= '9' && *str != '\0')
    {
      tmp = *str - '0';
      number = number * 10.0 + tmp;
      str++;
    }
  return (my_get_float_end(str, demical_digit, sign, number));
}
