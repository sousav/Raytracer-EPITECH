/*
** load_material.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Thu Mar 10 23:55:20 2016 victor sousa
** Last update Sun May 22 18:57:27 2016 Philippe Lefevre
*/

#include	"main.h"

void		my_atof_e(int *e, int *c, char *s)
{
  int		sign;
  int		i;

  if (*c == 'e' || *c == 'E')
    {
      sign = 1;
      i = 0;
      *c = *s++;
      if (*c == '+')
	*c = *s++;
      else if (*c == '-')
	{
	  *c = *s++;
	  sign = -1;
	}
      while (my_isnum(*c))
	{
	  i = i * 10 + (*c - '0');
	  *c = *s++;
	}
      *e += i * sign;
    }
}

double		my_atof_lefevr(char *s)
{
  double	a = 0.0;
  int		e = 0;
  int		c;

  while ((c = *s++) != '\0' && my_isnum(c))
    a = a * 10.0 + (c - '0');
  if (c == '.')
    while ((c = *s++) != '\0' && my_isnum(c))
      {
	a = a * 10.0 + (c - '0');
	e = e - 1;
      }
  my_atof_e(&e, &c, s);
  while (e > 0)
    {
      a *= 10.0;
      e--;
    }
  while (e < 0)
    {
      a *= 0.1;
      e++;
    }
  return (a);
}

int			get_mat_bump(t_mat_list *new, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:material_list:matX:bump") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:material_list:matX:bump");
  lf[23] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    {
      my_printf(1, "Could not find scene:material_list:mat%d:bump\n", id + 1);
      return (-1);
    }
  new->bump = my_atof_lefevr(get);
  free(get);
  free(lf);
  return (0);
}

int			get_mat_texture(t_mat_list *new, char **file, int id)
{
  char			*lf;
  char			*get;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:material_list:matX:texture") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:material_list:matX:texture");
  lf[23] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (my_printf(1, "Could not find scene:material_"
		      "list:matX:texture\n") - 1);
  if ((new->texture_path = malloc(my_strlen(get) + 1)) == NULL)
    return (-1);
  new->texture_path[0] = '\0';
  new->texture_path = my_strcat(new->texture_path, get);
  if (my_strcmp(get, "NULL") == 0)
    {
      if ((new->texture = create_text_uni(300, 100, 0xff000000)) == NULL)
	return (-1);
    }
  else if ((new->texture = load_image(get)) == NULL)
    return (-1);
  return (0);
}

t_mat_list              *add_mat(t_mat_list *prev, char **file, int id)
{
  t_mat_list            *new;

  if (((new = malloc(sizeof(t_mat_list))) == NULL)
      || (get_mat_red(new, file, id) != 0)
      || (get_mat_green(new, file, id) != 0)
      || (get_mat_blue(new, file, id) != 0)
      || (get_mat_reflect(new, file, id) != 0)
      || (get_mat_sky(new, file, id) != 0)
      || (get_mat_bump(new, file, id) != 0)
      || (get_mat_texture(new, file, id) != 0))
    return (NULL);
  new->id = id + 1;
  new->next = prev;
  return (new);
}
