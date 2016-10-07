/*
** my_printf.h for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 14:36:04 2015 Gaëtan Léandre
** Last update Tue Apr 26 02:36:54 2016 Gaëtan Léandre
*/

#ifndef		MY_PRINTF_H_
# define 	MY_PRINTF_H_

# include	<stdlib.h>
# include	<stdarg.h>

typedef struct	s_fonct
{
  char		flag;
  void		(*f)(int fd, va_list ap);
}		t_fonct;

typedef struct	s_print
{
  int		fd;
  int		i;
}		t_print;

int		my_printf(int fd, char *str, ...);
t_fonct		*init_struct(t_fonct *tab);
int		chose_function(char c, t_fonct *tab);
int		print_fct(va_list ap, t_fonct *tab, char *str, t_print pri);

void		va_my_putchar(int fd, va_list ap);
void		va_my_putstr(int fd, va_list ap);
void		va_my_putnbr(int fd, va_list ap);
void		va_my_putunbr(int fd, va_list ap);
void		va_my_disp_unp(int fd, va_list ap);
void		va_my_examaj(int fd, va_list ap);
void		va_my_examin(int fd, va_list ap);
void		va_my_octal(int fd, va_list ap);
void		va_my_bin(int fd, va_list ap);
void		va_my_adress(int fd, va_list ap);
void		va_my_putfnbr(int fd, va_list ap);

void		my_putstr_in(int fd, char *str);

void		my_putchar_in(int fd, char c);

void		my_put_nbr_in(int fd, int nbr);
int		positif(int nbr, int test);

void		my_put_unbr_in(int fd, unsigned int nbr);

void		disp_unprintable_in(int fd, char *str);

int		my_strlen(char *str);
void		my_putnbr_base_in(int fd, int nbr, char *base, int taille);
int		big_pow(int nbr, int base_size);
int		power(int nbr, int pow);

void		my_put_fnbr_in(int fd, float nbr);
void		my_putnbr_base_u_in(int fd, unsigned int nbr, char *base);
int		big_pow_u(unsigned int nbr, int base_size);
unsigned int	power_u(unsigned int nbr, int pow);

void		my_putnbr_base_add_in(int fd, size_t nbr, char *base, int taille);
int		big_pow_add(size_t nbr, int base_size);
size_t		power_add(size_t nbr, int pow);

#endif	      /*MY_PRINTF_H_*/
