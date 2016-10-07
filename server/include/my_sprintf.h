/*
** my_printf.h for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 14:36:04 2015 Gaëtan Léandre
** Last update Mon May 16 10:17:42 2016 Philippe Lefevre
*/

#ifndef			MY_SPRINTF_H_
# define 		MY_SPRINTF_H_

# include		<stdlib.h>
# include		<stdarg.h>

typedef struct		s_sfonct
{
  char			flag;
  char			*(*f)(va_list ap);
}			t_sfonct;

char			*my_sprintf(char *str, ...);

char			*va_my_putchar_s(va_list ap);
char			*va_my_putstr_s(va_list ap);
char			*va_my_putnbr_s(va_list ap);
char			*va_my_putunbr_s(va_list ap);
char			*va_my_disp_unp_s(va_list ap);
char			*va_my_putfnbr_s(va_list ap);
char			*va_my_octal_s(va_list ap);
char			*va_my_examin_s(va_list ap);
char			*va_my_examaj_s(va_list ap);
char			*va_my_adress_s(va_list ap);
char			*va_my_bin_s(va_list ap);

char			*my_strcatprint(char *a, char *b);
char			*my_strcatnofree(char *a, char *b);
char			*my_strcatchar(char *a, char b);
char			*malloc_and_init();

char			*disp_unprintable_s(char *str);
char			*my_put_fnbr_s(float nbr);
char			*my_put_nbr_s(int nbr);
char			*my_putnbr_base_u_s(unsigned int nbr, char *base);
char			*my_put_unbr_s(unsigned int nbr);
char			*my_putnbr_base_add_s(size_t nbr, char *base,
					      int taille);
char			*my_putnbr_base_s(int nbr, char *base, int taille);

#endif	      /*MY_SPRINTF_H_*/
