/*
** get_next_line.h for get_next_line in /home/leandr_g/rendu/Janvier_2016/CPE_2015_getnextline
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Jan  4 15:51:07 2016 Gaëtan Léandre
** Last update Mon May 16 08:25:15 2016 Philippe Lefevre
*/

#ifndef			GET_NEXT_LINE_H_
# define		GET_NEXT_LINE_H_

#ifndef			READ_SIZE
# define		READ_SIZE (1024)
#endif			/* !READ_SIZE */

#include		<stdlib.h>
#include		<unistd.h>

typedef struct		s_text
{
  int	i;
  char	*result;
  char	*stock;
}			t_text;

typedef struct		s_line_list
{
  char			*str;
  struct s_line_list	*next;
}			t_line_list;

char			*get_next_line(const int fd);
char			*get_next_line_size(const int fd, int i);

#endif			/* !GET_NEXT_LINE_H_*/
