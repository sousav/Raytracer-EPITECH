/*
** get_xml.c for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/src/editeur/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Apr 25 03:54:51 2016 Ethan Kerdelhue
** Last update Sat May 21 00:30:21 2016 Philippe Lefevre
*/

#include		"main.h"

int			aff_help(t_prog *prog)
{
  int			i;

  i = 0;
  while (my_strncmp(prog->editor->cmd[i].index, "END", 3))
    {
      my_putstr(prog->editor->cmd[i].index);
      my_putstr(" : ");
      my_putstr(prog->editor->cmd[i].desc);
      my_putstr("\n");
      i++;
    }
  return (0);
}

int			fill_struct(t_prog *prog)
{
  if (my_access(prog->editor->arg[1]) == 0)
    return (put_error(ERR_NOACC));
  if (prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 1] == 'l' &&
      prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 2] == 'm' &&
      prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 3] == 'x' &&
      prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 4] == '.')
    load_scene(prog, prog->editor->arg[1]);
  else if (prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 1] == 'j' &&
	   prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 2] == 'b' &&
	   prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 3] == 'o' &&
	   prog->editor->arg[1][my_strlen(prog->editor->arg[1]) - 4] == '.')
    load_obj_file(prog, prog->editor->arg[1]);
  prog->editor->fd = open(prog->editor->arg[1], O_RDONLY);
  return (0);
}

char			*get_type(char c)
{
  char			flag[7];
  char			*ret[7];
  int			i;

  flag[0] = 's';
  ret[0] = "sphere";
  flag[1] = 't';
  ret[1] = "triangle";
  flag[2] = 'p';
  ret[2] = "plan";
  flag[3] = 'c';
  ret[3] = "cone";
  flag[4] = 'y';
  ret[4] = "cylinder";
  flag[5] = 'i';
  ret[5] = "circle";
  flag[6] = 'l';
  ret[6] = "pill";
  i = -1;
  while (++i < 7)
    if (c == flag[i])
      return (ret[i]);
  return (NULL);
}

int			aff_xml(t_prog *prog)
{
  int			fd;

  fd = 0;
  if (prog->editor->fd == -1)
    return (put_error(ERR_NOFD));
  my_printf(fd, "<scene>\n");
  aff_win_prop(fd, prog);
  aff_mat_list(fd, prog);
  aff_obj_list(fd, prog);
  aff_light_list(fd, prog);
  my_printf(fd, "</scene>\n");
  return (0);
}

int			editor(int ac, char **av)
{
  t_prog		*prog;
  t_cmd			cmd;
  char			*str;

  if (ac == 2 && (!(my_strcmp("--edit", av[1]))))
    {
      if ((prog = malloc(sizeof(t_prog))) == NULL)
	return (-1);
      if ((prog->editor = malloc(sizeof(t_editor))) == NULL)
	return (-1);
      prog->editor->cmd = init_cmd(&cmd);
      prog->editor->fd = -1;
      while (!disp_info() && (str = get_next_line(0)) != NULL)
	{
	  prog->editor->arg = str_to_wordtab(str, " ");
	  free(str);
	  if (prog->editor->arg[0] != NULL
	      && !(my_strcmp(prog->editor->arg[0], "exit")))
	    return (-1);
	  put_error(check_cmd(prog));
	}
    }
  return (0);
}
