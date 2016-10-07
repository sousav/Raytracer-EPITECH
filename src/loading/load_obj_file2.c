/*
** load_obj_file.c for  in /home/sousa_v/rendu/lapin/raytracer_temp/src/loading/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Apr 25 08:37:20 2016 Victor Sousa
** Last update Sat May 21 04:35:04 2016 Philippe Lefevre
*/

#include		"main.h"

t_light_list		*add_empty_light(t_light_list *prev)
{
  t_light_list          *new;

  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (NULL);
  new->center.x = 0;
  new->center.y = 500;
  new->center.z = 0;
  new->intensity = 200;
  new->next = prev;
  return (new);
}
t_light_list		*add_empty_light2(t_light_list *prev)
{
  t_light_list          *new;

  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (NULL);
  new->center.x = 0;
  new->center.y = -500;
  new->center.z = 0;
  new->intensity = 200;
  new->next = prev;
  return (new);
}
t_light_list		*add_empty_light3(t_light_list *prev)
{
  t_light_list          *new;

  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (NULL);
  new->center.x = 500;
  new->center.y = 0;
  new->center.z = 0;
  new->intensity = 200;
  new->next = prev;
  return (new);
}
t_light_list		*add_empty_light4(t_light_list *prev)
{
  t_light_list          *new;

  if ((new = malloc(sizeof(t_light_list))) == NULL)
    return (NULL);
  new->center.x = -500;
  new->center.y = 0;
  new->center.z = 0;
  new->intensity = 200;
  new->next = prev;
  return (new);
}

t_mat_list              *add_empty_mat(t_mat_list *prev)
{
  t_mat_list            *new;

  if ((new = malloc(sizeof(t_mat_list))) == NULL)
    return (NULL);
  new->color.full = 0xFFFFAF00;
  new->reflect = 10;
  new->id = 1;
  new->next = prev;
  return (new);
}
