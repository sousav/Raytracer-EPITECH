/*
** command.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/client/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed May 11 00:37:45 2016 Gaëtan Léandre
** Last update Sat May 21 23:21:58 2016 Philippe Lefevre
*/

#include		"main.h"

char			**is_command(char *str)
{
  int			i;

  i = 0;
  if (my_strlen(str) > 0)
    {
      while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	i++;
      if (str[i] == '/')
	return (str_to_wordtab(&str[i + 1], " "));
    }
  return (NULL);
}

char			*read_file_to_char(char *file)
{
  char			*str;
  int			fd;
  struct stat		file_s;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  fstat(fd, &file_s);
  if ((str = malloc(file_s.st_size + 1)) == NULL)
    return (NULL);
  str[file_s.st_size] = '\0';
  if (read(fd, str, file_s.st_size) == -1)
    return (NULL);
  close(fd);
  return (str);
}

char			*launch_cmd_1(SOCKET sock, char **tab, int *status)
{
  char			*str;

  my_printf(1, "Ouverture du fichier\n");
  if ((str = read_file_to_char(tab[2])) == NULL)
    {
      my_printf(1, "Path fichier invalide\n");
      write_server(sock, "error");
    }
  else
    {
      write_server(sock, "ok");
      my_printf(1, "Envois du fichier au serveur\n");
      if (send_file(sock, str, my_strlen(str)) == 0)
	*status = -1;
    }
  return ("k");
}

char			*launch_cmd(SOCKET sock, char **tab, int *status)
{
  char			*str;

  if (!my_strcmp(tab[0], "launch") && tab[1])
    {
      if (!my_strcmp(tab[1], "s") && tab[2] && !tab[3])
	{
	  return (launch_cmd_1(sock, tab, status));
	}
      else if (!my_strcmp(tab[1], "r") && !tab[2])
	{
	  my_printf(1, "Reception d'un fichier depuis le serveur\n");
	  if ((str = reciv_file(sock)) == NULL)
	    *status = -1;
	  else
	    *status = 2;
	  return (str);
	}
      else
	my_printf(1, "%s %d\n", tab[1], tab[1][1]);
    }
  return (NULL);
}

int			exit_cmd(int *status, char **tab)
{
  if (tab[0] && !my_strcmp(tab[0], "halt"))
    {
      my_printf(1, "Arret du serveur\n");
      *status = -1;
      return (1);
    }
  return (0);
}
