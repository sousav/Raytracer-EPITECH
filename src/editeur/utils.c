/*
** utils.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Apr 26 10:07:00 2016 Ethan Kerdelhue
** Last update Mon May 16 09:24:46 2016 Philippe Lefevre
*/

#include		"main.h"

int			put_error(int error)
{
  if (error == ERR_NOCMD)
    my_putstr("Error : No entry for this command \
	      use \"help\" for more details\n");
  if (error == ERR_NOACC)
    my_putstr("Error : No access to this file\n");
  if (error == ERR_NOSTR)
    my_putstr("");
  if (error == ERR_NOFD)
    my_putstr("Error : you need to open a .xml file before use command\n");
  return (-1);
}

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

int			my_access(char *file)
{
  if (access(file, F_OK) == 0)
    return (1);
  return (0);
}

int			disp_info()
{
  my_putstr("$> ");
  return (0);
}
