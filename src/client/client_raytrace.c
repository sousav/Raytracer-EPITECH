/*
** client_raytrace.c for raytracer in /Users/leandr_g/Documents/Shared folder/Raytracer/src/client/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Fri May 13 04:44:05 2016 Gaëtan Léandre
** Last update Sun May 22 19:20:17 2016 Philippe Lefevre
*/

#include		"main.h"

void 			load_obj_file_open_init(t_prog *prog)
{
  t_coord		dir;

  prog->win_size.x = 1080;
  prog->win_size.y = 720;
  prog->cam_pos.x = -500;
  prog->cam_pos.y = 125;
  prog->cam_pos.z = -500;
  prog->cam_fov.x = 90;
  prog->cam_fov.y = prog->cam_fov.x * ((prog->win_size.x
					/ prog->win_size.y) / 1.5);
  prog->look_at.x = 0;
  prog->look_at.y = 0;
  prog->look_at.z = 0;
  dir = normalize(minus_point(prog->look_at, prog->cam_pos));
  prog->cam_rot.x = RTD(acos(-(dir.z / sqrt(pow(dir.x, 2)
					    + pow(dir.z, 2))))) - 90;
  prog->cam_rot.y = RTD((M_PI / 2 - acos(dir.y)));
  prog->cam_dir = normalize(minus_point(prog->look_at, prog->cam_pos));
}

int			load_obj_file_open(t_prog *prog, char *str)
{
  char			**file;
  t_vtx_list		*vtx_list;

  load_obj_file_open_init(prog);
  if ((file = str_to_wordtab(str, "\n")) == NULL)
    return (-1);
  prog->light_list = NULL;
  if (((prog->light_list = add_empty_light(prog->light_list)) == NULL)
      || ((prog->light_list = add_empty_light2(prog->light_list)) == NULL)
      || ((prog->light_list = add_empty_light3(prog->light_list)) == NULL)
      || ((prog->light_list = add_empty_light4(prog->light_list)) == NULL)
      || ((prog->background = create_text_uni(prog->win_size.x,
					      prog->win_size.x,
					      0xff000000)) == NULL))
    return (-1);
  prog->anti_alias = 1;
  prog->mat_list = NULL;
  if (((prog->mat_list = add_empty_mat(prog->mat_list)) == NULL)
      || ((vtx_list = get_vertex(file)) == NULL)
      || ((prog->obj_list = parse_obj_formes(file, vtx_list)) == NULL))
    return (-1);
  free_tab(file);
  return (0);
}

t_opt			*client_raytrace_init(t_prog *prog)
{
  if ((prog->opt = malloc(sizeof(t_opt))) == NULL)
    return (NULL);
  prog->opt->thread_nb = 4;
  prog->opt->rendu_display = 0;
  prog->opt->rendu_vertical = 0;
  prog->opt->verbose = 1;
  return (prog->opt);
}

char			**client_raytrace_beg(int *status, t_prog *prog,
					      SOCKET sock, char *str)
{
  char			buffer[BUF_SIZE];
  char			**tab;

  if (read_server(sock, buffer) == 0)
    {
      *status = -1;
      return (NULL);
    }
  tab = str_to_wordtab(buffer, " ");
  if ((tab[2][0] == 'x' && load_scene_open(prog, str) == -1)
      || (tab[2][0] == 'o' && load_obj_file_open(prog, str) == -1))
        {
      *status = -1;
      return (NULL);
    }
  return (tab);
}

void			client_raytrace(char *str, int *status, SOCKET sock)
{
  unsigned int		*grille;
  char			**tab;
  t_prog		prog;

  tab = client_raytrace_beg(status, &prog, sock, str);
  if ((prog.opt = client_raytrace_init(&prog)) == NULL)
    return;
  grille = raytrace_threading_client(&prog, my_getnbr(tab[0]),
				     my_getnbr(tab[1]));
  my_printf(1, "Envois des calculs\n");
  if (grille == NULL || send(sock, grille, sizeof(unsigned int)
			     * (my_getnbr(tab[1]) - my_getnbr(tab[0]))
			     * prog.win_size.y, 0) < 0)
    *status = -1;
  else
    {
      my_printf(1, "Caluls envoyés, en attente d'une information serveur\n");
      *status = 0;
      free(grille);
    }
  free(prog.opt);
  free(str);
  free_tab(tab);
}
