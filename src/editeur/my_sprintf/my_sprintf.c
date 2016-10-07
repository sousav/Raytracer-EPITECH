/*
** my_printf.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 12:27:44 2015 Gaëtan Léandre
** Last update Sat May 14 00:59:16 2016 Philippe Lefevre
*/

#include 		"main.h"

char			*va_my_putfnbr_s(va_list ap)
{
  return (my_put_fnbr_s(va_arg(ap, double)));
}

static t_sfonct		*init_sstruct(t_sfonct *tab, char *flag, int nb_flag)
{
  int			i;

  i = -1;
  if ((tab = malloc(12 * sizeof(t_sfonct))) == NULL)
    return (NULL);
  while (++i < nb_flag)
    tab[i].flag = flag[i];
  (tab[0].f) = va_my_putchar_s;
  (tab[1].f) = va_my_putstr_s;
  (tab[2].f) = va_my_putnbr_s;
  (tab[3].f) = va_my_putnbr_s;
  (tab[4].f) = va_my_putunbr_s;
  (tab[5].f) = va_my_octal_s;
  (tab[6].f) = va_my_examin_s;
  (tab[7].f) = va_my_examaj_s;
  (tab[8].f) = va_my_bin_s;
  (tab[9].f) = va_my_disp_unp_s;
  (tab[10].f) = va_my_adress_s;
  (tab[11].f) = va_my_putfnbr_s;
  return (tab);
}

static int			chose_ffunction(char c, t_sfonct *tab)
{
  int			i;

  i = 0;
  while (i < 12)
    {
      if (c == tab[i].flag)
	return (i);
      i++;
    }
  if (c == '\0')
    return (-2);
  return (-1);
}

static char			*print_ffct(va_list ap, t_sfonct *tab,
					   char *str, int *i)
{
  int			fct;
  int			wait;
  char			*result;

  if ((result = malloc_and_init()) == NULL)
    return (NULL);
  (*i)++;
  wait = str[*i] == ' ' ? 1 : 0;
  while (str[*i] == ' ')
    (*i)++;
  fct = chose_ffunction(str[*i], tab);
  if (fct == -1)
    {
      result = my_strcatchar(result, '%');
      if (str[*i] != '%')
	result = ((wait == 1) ? (my_strcatchar(result, ' '))
		  : (my_strcatchar(result, str[*i])));
    }
  else if (fct > -1)
    result = ((wait == 1) ? (my_strcatchar(result, ' '))
	      : (my_strcatprint(result, tab[fct].f(ap))));
  return (result);
}

char			*my_sprintf(char *str, ...)
{
  va_list		ap;
  t_sfonct		*tab;
  int	 		i;
  char			*result;

  tab = NULL;
  tab = init_sstruct(tab, "csiduoxXbspf", 12);
  if ((result = malloc_and_init()) == NULL)
    return (NULL);
  i = 0;
  if (str == NULL || tab == NULL)
    return (NULL);
  va_start(ap, str);
  while (i < my_strlen(str))
    {
      if (str[i] == '%')
	result = my_strcatprint(result, print_ffct(ap, tab, str, &i));
      else
	result = my_strcatchar(result, str[i]);
      i++;
    }
  va_end(ap);
  free(tab);
  return (result);
}
