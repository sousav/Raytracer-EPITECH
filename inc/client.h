/*
** client.h for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/inc/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue May 10 22:56:16 2016 Gaëtan Léandre
** Last update Sun May 22 01:31:38 2016 Philippe Lefevre
*/

#ifndef			_CLIENT_H_
# define		_CLIENT_H_

# define		PORT		666
# define		BUF_SIZE	1024

# include		<sys/types.h>
# include		<sys/socket.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<unistd.h>
# include		"get_next_line.h"
# include 		"utils.h"

typedef 		int SOCKET;
typedef struct 		sockaddr_in SOCKADDR_IN;
typedef struct 		sockaddr SOCKADDR;
typedef struct 		in_addr IN_ADDR;

typedef struct		s_connected
{
  int			max;
  int			status;
}			t_connected;

typedef union		s_size
{
  int			i;
  unsigned char		csize[4];
}			t_size;

typedef struct		s_pass
{
  t_prog 		*prog;
  unsigned int		*grille;
}			t_pass;

SOCKET			init_connection();
void			write_server(SOCKET sock, char *buffer);
int			read_server(SOCKET sock, char *buffer);
int			client(t_prog *prog);
int			send_file(SOCKET sock, char *file, int siz);
char			*reciv_file(SOCKET sock);
char			**is_command(char *str);
char			*exec_command(SOCKET sock, char **tab, int *status,
				      t_prog *prog);
void			client_raytrace(char *str, int *status, SOCKET sock);
unsigned int		*raytrace_threading_client(t_prog *prog, int start,
						   int stop);
int			load_scene_open(t_prog *prog, char *str);
char			*launch_cmd(SOCKET sock, char **tab, int *status);
int			exit_cmd(int *status, char **tab);

#endif			/* _CLIENT_H_ */
