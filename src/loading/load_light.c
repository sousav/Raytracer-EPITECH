/*
** load_light.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Thu Mar 10 23:38:31 2016 victor sousa
** Last update Fri Mar 11 00:33:58 2016 victor sousa
*/

#include	"main.h"

static int		get_light_center(t_light_list *new, char **file, int id)
{
  char			*get;
  char			*lf;

  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:light_list:lightX:center:x") + 1)) == NULL)
    return (1);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:light_list:lightX:center:x");
  lf[22] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  new->center.x = my_getnbr(get);
  free(get);
  lf[31] = 'y';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  new->center.y = my_getnbr(get);
  free(get);
  lf[31] = 'z';
  if ((get = get_field(file, lf)) == NULL)
    return (1);
  new->center.z = my_getnbr(get);
  free(get);
  free(lf);
  return (0);
}

static t_light_list	*add_light(t_light_list *prev, char **file, int id)
{
  t_light_list          *new;
  char                  *lf;
  char                  *get;

  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (NULL);
  if (get_light_center(new, file, id) != 0)
    return (NULL);
  if ((lf = malloc(sizeof(char) *
		   my_strlen("scene:light_list:lightX:intensity") + 1)) == NULL)
    return (NULL);
  lf[0] = '\0';
  lf = my_strcat(lf, "scene:light_list:lightX:intensity");
  lf[22] = id + 49;
  if ((get = get_field(file, lf)) == NULL)
    return (NULL);
  new->intensity = my_getnbr(get);
  free(get);
  free(lf);
  new->next = prev;
  return (new);
}

int                     load_light(t_prog *prog, char **file)
{
  int                   i;
  int                   light_count;
  char                  *get;

  if ((get = get_field(file, "scene:light_list:count")) == NULL)
    return (-1);
  light_count = my_getnbr(get);
  free(get);
  prog->light_list = NULL;

  i = 0;
  while (i < light_count)
    {
      if ((prog->light_list = add_light(prog->light_list, file, i)) == NULL)
        return (-1);
      i++;
    }
  return (0);
}
