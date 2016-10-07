/*
** my_printf.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 12:27:44 2015 Gaëtan Léandre
** Last update Sun May 22 20:12:16 2016 Philippe Lefevre
*/

#include 		"server.h"

static int		init_flag(t_fonct *tab)
{
  tab[0].flag = 'c';
  tab[1].flag = 's';
  tab[2].flag = 'i';
  tab[3].flag = 'd';
  tab[4].flag = 'u';
  tab[5].flag = 'o';
  tab[6].flag = 'x';
  tab[7].flag = 'X';
  tab[8].flag = 'b';
  tab[9].flag = 'S';
  tab[10].flag = 'p';
  tab[11].flag = 'f';
  return (0);
}

t_fonct			*init_struct(t_fonct *tab)
{
  if ((tab = malloc(12 * sizeof(t_fonct))) == NULL)
    return (NULL);
  init_flag(tab);
  (tab[0].f) = va_my_putchar;
  (tab[1].f) = va_my_putstr;
  (tab[2].f) = va_my_putnbr;
  (tab[3].f) = va_my_putnbr;
  (tab[4].f) = va_my_putunbr;
  (tab[5].f) = va_my_octal;
  (tab[6].f) = va_my_examin;
  (tab[7].f) = va_my_examaj;
  (tab[8].f) = va_my_bin;
  (tab[9].f) = va_my_disp_unp;
  (tab[10].f) = va_my_adress;
  (tab[11].f) = va_my_putfnbr;
  return (tab);
}

int			chose_function(char c, t_fonct *tab)
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

int			print_fct(va_list ap, t_fonct *tab,
				  char *str, t_print pri)
{
  int			fct;
  int			wait;

  pri.i++;
  wait = str[pri.i] == ' ' ? 1 : 0;
  while (str[pri.i] == ' ')
    pri.i++;
  fct = chose_function(str[pri.i], tab);
  if (fct == -1)
    {
      my_putchar_in(pri.fd, '%');
      if (str[pri.i] != '%')
	{
	  if (wait == 1)
	    my_putchar_in(pri.fd, ' ');
	  my_putchar_in(pri.fd, str[pri.i]);
	}
    }
  else if (fct > -1)
    {
      if (wait == 1)
	my_putchar_in(pri.fd, ' ');
      tab[fct].f(pri.fd, ap);
    }
  return (pri.i);
}

int			my_printf(int fd, char *str, ...)
{
  va_list	ap;
  t_fonct	*tab;
  t_print	pri;

  pri.fd = fd;
  tab = NULL;
  tab = init_struct(tab);
  pri.i = 0;
  if (str == NULL || tab == NULL)
    return (-1);
  va_start(ap, str);
  while (pri.i < my_strlen(str))
    {
      if (str[pri.i] == '%')
	pri.i = print_fct(ap, tab, str, pri);
      else
	my_putchar_in(fd, str[pri.i]);
      pri.i++;
    }
  va_end(ap);
  free(tab);
  return (0);
}
