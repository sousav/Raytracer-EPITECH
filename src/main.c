/*
** main.c for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 01:50:10 2016 victor sousa
** Last update Sun May 22 17:00:57 2016 Philippe Lefevre
*/

#include		"main.h"

int			disp_help(char *bin)
{
  my_printf(1, "Usage:	%s	scene[.xml|.obj]\n", bin);
  my_printf(1, "			--thread=nb_thread\n");
  my_printf(1, "			--display_rendu\n");
  my_printf(1, "			--rendu_verticale\n");
  my_printf(1, "			--verbose\n");
  my_printf(1, "			--quiet\n");
  my_printf(1, "			--export=[path/output.bmp]\n");
  my_printf(1, "OR\n");
  my_printf(1, "	%s	--edit\n", bin);
  my_printf(1, "OR\n");
  my_printf(1, "	%s	--cluster\n", bin);
  my_printf(1, "OR\n");
  my_printf(1, "	%s	--credit\n", bin);
  return (-1);
}

int			disp_credit(char **av)
{
  int			i;

  i = 0;
  while (av[++i])
    if (!(my_strcmp("--credit", av[i])))
      return (my_printf(1, "Credit Raytracer Epitech\n")
              + my_printf(1, "	Leandre Gaetan\n")
              + my_printf(1, "	Sousa Victor\n")
              + my_printf(1, "	Lefevre Philippe\n")
              + my_printf(1, "	Kerdelhue Ethan\n") - 1);
  return (0);
}

int			create_pix(t_prog *prog)
{
  if ((prog->pix = bunny_new_pixelarray(prog->win_size.x, prog->win_size.y))
      == NULL)
    {
      my_printf(2, "buffer   creation failed... leaving\n");
      return (-1);
    }
  else if (prog->opt->verbose)
    my_putstr("buffer  creation successfull\n");
  return (0);
}

int			create_win(t_prog *prog)
{
  if ((prog->win = bunny_start(prog->win_size.x, prog->win_size.y,
			       false, "Raytracer 2")) == NULL)
    {
      my_printf(2, "windows creation failed... leaving\n");
      return (-1);
    }
  else if (prog->opt->verbose)
    my_putstr("windows creation successfull\n");
  return (0);
}

int			main(int ac, char **av, char **env)
{
  t_prog		prog;

  set_max_heap_size(RT_MAX_RAM);
  if (verif_env(env) || (ac < 2) || verif_arg(ac, av, &prog) == -1)
    return (-1);
  if (prog.opt->cluster)
    {
      if (client(&prog) == -1)
	    {
	      free(prog.opt);
	      return (-1);
	    }
    }
  else if (create_pix(&prog) || create_win(&prog) || waiting_screen(&prog))
    return (-1);
  else
    raytrace_threading(&prog, 0, ((prog.opt->rendu_vertical) ?
				  (prog.win_size.y) : (prog.win_size.x)));
  if (prog.opt->export)
    export_to_bmp(&prog);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(prog.win, 30, &prog);
  free_stuff(&prog);
  return (0);
}
