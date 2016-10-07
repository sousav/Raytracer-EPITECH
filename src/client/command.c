/*
** command.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/client/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed May 11 00:37:45 2016 Gaëtan Léandre
** Last update Sun May 22 19:20:58 2016 Philippe Lefevre
*/

#include		"main.h"

char			*download_cmd_1(char *grille, SOCKET sock,
					int wait, int *status)
{
  int			size;
  int			tmp;

  if (grille != NULL)
    {
      write_server(sock, "k");
      size = 0;
      tmp = 0;
      while (size < wait && tmp >= 0)
	{
	  tmp = recv(sock, &grille[size], wait - size , 0);
	  size += tmp;
	}
    }
  else
    write_server(sock, "n");
  if (grille != NULL && tmp >= 0)
    {
      *status = 3;
      return (grille);
    }
    return (NULL);
}

char			*download_cmd(int *status, char **tab,
				      t_prog *prog, SOCKET sock)
{
  char			*grille;
  int			wait;

  if (tab[0] && !my_strcmp(tab[0], "download") && tab[1] && tab[2])
    {
      my_printf(1, "Reception de l'image.\n");
      prog->win_size.x = my_getnbr(tab[1]);
      prog->win_size.y = my_getnbr(tab[2]);
      wait = prog->win_size.x * prog->win_size.y;
      wait *= sizeof(unsigned int);
      grille = malloc(wait);
      return (download_cmd_1(grille, sock, wait, status));
    }
  return (NULL);
}

void			cpy_in_pix(t_prog *prog, unsigned int *grille,
				   int *status)
{
  int			i;
  int			max;

  max = prog->win_size.x * prog->win_size.y;
  if (create_pix(prog) || create_win(prog))
    {
      *status = -1;
      return;
    }
  i = 0;
  while (i < max)
    {
      ((t_color *)prog->pix->pixels)[i].full = grille[i];
      i++;
    }
}

char			*exec_command(SOCKET sock, char **tab, int *status,
				      t_prog *prog)
{
  char			*str;
  char			*grille;

  grille = NULL;
  if ((str = launch_cmd(sock, tab, status)) == NULL
      && exit_cmd(status, tab) == 0
      && (grille = download_cmd(status, tab, prog, sock)) == NULL)
    my_printf(2, "Commande recue erronée\n");
  if (grille != NULL)
    {
      cpy_in_pix(prog, (unsigned int *)grille, status);
      free(grille);
    }
  return (str);
}
