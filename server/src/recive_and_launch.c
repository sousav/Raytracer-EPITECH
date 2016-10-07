/*
** recive_and_launch.c for server in /Users/leandr_g/Documents/Shared folder/Raytracer/server/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed May 11 01:31:59 2016 Gaëtan Léandre
** Last update Sun May 22 00:20:32 2016 Philippe Lefevre
*/

#include		"server.h"

void			recive_and_launch_free(char **tab, char *get,
					       char *str)
{
  free_tab(tab);
  if (get != NULL)
    free(get);
  free(str);
}

void			recive_and_launch_end(t_connected *co, char *str,
					      int size)
{
  int			i;
  t_client		*tmp;

  my_printf(1, "Envois du fichier aux clients\n");
  write_all_client(co, "/launch r", -1);
  i = 0;
  while (i++ < 2000000000);
  send_file(co->master->sock, str, size);
  tmp = co->clients;
  while (tmp)
    {
      send_file(tmp->sock, str, size);
      tmp = tmp->next;
    }
  free(str);
}

int			recive_and_launch_mid(t_connected *co, char **tab,
					      char *get, char *str)
{
  if (co->form == 1)
    {
      tab = str_to_wordtab(str, "\n");
      if ((get = get_field(tab, "scene:view:x_size")) == NULL
	  || (co->width = my_getnbr(get)) <= 0)
	{
	  recive_and_launch_free(tab, get, str);
	  return (-1);
	}
      free(get);
      if ((get = get_field(tab, "scene:view:y_size")) == NULL
	  || (co->height = my_getnbr(get)) <= 0)
	{
	  recive_and_launch_free(tab, get, str);
	  return (-1);
	}
      free(get);
      free_tab(tab);
    }
  else if (co->form != 1)
    {
      co->width = 1080;
      co->height = 720;
    }
  return (0);
}

void			recive_and_launch(t_connected *co)
{
  char			buffer[10];
  char			*str;
  int			size;
  char			*get;
  char			**tab;

  tab = NULL;
  get = NULL;
  my_printf(1, "Téléchargement du fichier sur le serveur\n");
  if ((size = read_client(co->master->sock, buffer)) == 0
      || my_strcmp(buffer, "error"))
    {
      my_printf(1, "Ouverture du fichier impossible\n");
      co->status = 0;
      return;
    }
  else if ((str = reciv_file(co->master->sock)) == NULL)
    return;
  size = my_strlen(str);
  if (recive_and_launch_mid(co, tab, get, str))
    return;
  recive_and_launch_end(co, str, size);
}
