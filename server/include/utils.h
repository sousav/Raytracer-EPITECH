/*
** utils.h for utils in /Users/leandr_g/Documents/Shared folder/testServer/include/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat May  7 05:05:50 2016 Gaëtan Léandre
** Last update Mon May 16 11:17:15 2016 Gaëtan Léandre
*/

#ifndef			_UTILS_H_
# define		_UTILS_H_

# include 		<stdlib.h>

typedef union		s_size
{
  int			i;
  unsigned char		csize[4];
}			t_size;

char			**str_to_wordtab(char *str, char *separate);
int			my_strlen(char *str);
char			**is_command(char *str);
void			free_tab(char **tab);
int			my_strcmp(char *a, char *b);
char			*reciv_file(int sock);
int			send_file(int sock, char *file, int siz);
char			*my_strdup(char *str);

#endif			/* _UTILS_H_ */
