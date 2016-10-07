/*
** command.c for server in /Users/leandr_g/Documents/Shared folder/testServer/server_src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat May  7 05:54:51 2016 Gaëtan Léandre
** Last update Sun May 22 20:02:40 2016 Philippe Lefevre
*/

#include		"server.h"

int			cmd_download(SOCKET sock, char **tab, t_connected *co)
{
  char			*str;
  char			buffer[BUF_SIZE];

  if (tab == NULL)
    return (0);
  if (co->master && sock == co->master->sock && my_strcmp(tab[0], "download")
      && tab[1] == NULL && co->end != NULL)
    {
      str = my_sprintf("/download %d %d", co->width, co->height);
      write_client(sock, str);
      if (read_client(sock, buffer) > 0 && my_strcmp(buffer, "k") == 1)
	send(sock, co->end, sizeof(unsigned int) * co->height * co->width, 0);
      free(str);
      return (1);
    }
  return (0);
}

int			cmd_exit(char **tab, t_connected *co)
{
  if (tab == NULL)
    return (0);
  if (my_strcmp(tab[0], "exit") && tab[1] == NULL)
    {
      write_all_client(co, "/halt", -1);
      co->status = -1;
      return (1);
    }
  return (0);
}

void			launch_command_server(char **tab, t_connected *co)
{

  if (!tab || !cmd_exit(tab, co))
    my_printf(1, "Commande inconnue\n");
  free_tab(tab);
}

void			launch_command_client(SOCKET sock, char **tab,
                                            t_connected *co)
{
  if ((co->master == NULL
       || co->master->sock != sock
       || cmd_exit(tab, co) == 0)
      && cmd_sudo(sock, tab, co) == 0 && cmd_launch(sock, tab, co) == 0
      && cmd_download(sock, tab, co) == 0 && cmd_name(tab, co, sock) == 0)
    write_client(sock, "Commande inconnue");
  free_tab(tab);
}

void			exec_command(t_connected *co)
{
  char			*str;
  char			**tab;
  char			*msg;

  if ((str = get_next_line(0)) != NULL)
    {
      if ((tab = is_command(str)) != NULL)
      launch_command_server(tab, co);
      else
      {
         msg = my_sprintf("\033[31m%s\033[0m", str);
         if (msg != NULL)
           {
                write_all_client(co, msg, -1);
              free(msg);
           }
      }
      free(str);
    }
}
