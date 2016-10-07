/*
** raytrace_threading.c for Raytracer in /home/lefevr_h/Workspace/Github/Raytracer/src/raytrace/
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun May  8 02:20:22 2016 Philippe Lefevre
** Last update Sun May 22 16:44:29 2016 Philippe Lefevre
*/

#include		"main.h"

void			*raytrace_verticale(void *p)
{
  static int		thread_id = -1;
  t_prog		*prog;
  t_raycast		raycast;
  t_bunny_position      pos;
  t_color		pixel_color;
  int			end;

  prog = p;
  raycast.touch_circle = 0;
  pos.x = ((prog->win_size.x / prog->opt->thread_nb) * ++thread_id) - 1;
  end = ((prog->win_size.x / prog->opt->thread_nb) * (thread_id + 1));
  if (prog->opt->verbose)
    my_printf(1, "Thread number %d : %d to %d\n", thread_id, pos.x, end);
  while (++pos.x < end)
    {
      pos.y = prog->opt->start - 1;
      while (++pos.y < prog->opt->stop)
	{
	  pixel_color.full = calcul_pixel(prog, raycast, pos);
	  tekpixel(prog->pix, &pos, &pixel_color);
	}
    }
  prog->opt->rendu_success -= (thread_id + 1);
  pthread_exit(NULL);
}

void			*raytrace_horizontale(void *p)
{
  static int		thread_id = -1;
  t_prog		*prog;
  t_raycast		raycast;
  t_bunny_position      pos;
  t_color		pixel_color;
  int			end;

  prog = p;
  raycast.touch_circle = 0;
  pos.y = ((prog->win_size.y / prog->opt->thread_nb) * ++thread_id) - 1;
  end = ((prog->win_size.y / prog->opt->thread_nb) * (thread_id + 1));
  if (prog->opt->verbose)
    my_printf(1, "Thread number %d : %d to %d\n", thread_id, pos.y, end);
  while (++pos.y < end)
    {
      pos.x = prog->opt->start - 1;
      while (++pos.x < prog->opt->stop)
	{
	  pixel_color.full = calcul_pixel(prog, raycast, pos);
	  tekpixel(prog->pix, &pos, &pixel_color);
	}
    }
  prog->opt->rendu_success -= (thread_id + 1);
  pthread_exit(NULL);
}

int			raytrace_thread_create(t_prog *prog, int i,
					       pthread_t thread_id[])
{
  prog->opt->rendu_success += i + 1;
  if (pthread_create(&thread_id[i], NULL,
		     ((prog->opt->rendu_vertical) ? (raytrace_verticale)
		      : (raytrace_horizontale)), (void *)prog))
    return (my_printf(2, "Error: can not create thread\n") - 1);
  return (0);
}

static int		raytrace_end(t_prog *prog, pthread_t thread_id[],
				     time_t time_beg, t_bunny_position *pos)
{
  int			i;
  time_t		time_end;

  i = -1;
  while (prog->opt->rendu_display && (prog->opt->rendu_success > 0))
    {
      bunny_blit(&prog->win->buffer, &prog->pix->clipable, pos);
      bunny_display(prog->win);
    }
  while (++i < prog->opt->thread_nb)
    pthread_join(thread_id[i], NULL);
  time_end = time(NULL);
  if (prog->opt->verbose)
    my_printf(1, "\nRendu en %d heures %d minutes %d secondes\n",
	      (time_end - time_beg) / 3600, ((time_end - time_beg) % 3600) / 60,
	      ((time_end - time_beg) % 3600) % 60);
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, pos);
  bunny_display(prog->win);
  if (prog->opt->verbose)
    my_putstr("Raytracing multi-threading successfull\n");
  return (0);
}

int			raytrace_threading(t_prog *prog, int start,
					  int stop)
{
  pthread_t		thread_id[prog->opt->thread_nb];
  time_t		time_beg;
  t_bunny_position      pos;
  int			i;

  pos.x = 0;
  pos.y = 0;
  prog->opt->start = start;
  prog->opt->stop = stop;
  bunny_blit(&prog->win->buffer, &prog->pix->clipable, &pos);
  bunny_display(prog->win);
  if (prog->opt->verbose)
    my_putstr("\nRaytracing multi-threading started\n");
  i = -1;
  if (prog->opt->verbose)
    my_putstr("\nStarting create thread\n");
  prog->opt->rendu_success = 0;
  time_beg = time(NULL);
  while (++i < prog->opt->thread_nb)
    if (raytrace_thread_create(prog, i, thread_id))
	return (-1);
  if (prog->opt->verbose)
    my_putstr("Thread create successfull\n");
  return (raytrace_end(prog, thread_id, time_beg, &pos));
}
