/*
** hitbox_creator.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:47:57 2016 Gaëtan Léandre
** Last update Sun May  1 15:47:42 2016 Gaëtan Léandre
*/

#include 		"main.h"

void		place_into_hitbox(t_texture *dest, t_texture *src,
				  t_hitbox hit)
{
  t_bunny_position	tmp;
  t_bunny_position	pos;
  int			i;
  int			j;

  i = 0;
  tmp.y = hit.y;
  while (i < hit.height)
    {
      j = 0;
      tmp.x = hit.x;
      while (j < hit.width)
	{
	  pos.y = (int)(((float)i / (float)hit.height) * (float)(src->height));
	  pos.x = (int)(((float)j / (float)hit.width) * (float)(src->width));
	  if (tmp.x < dest->width && tmp.y < dest->height && tmp.x >= 0
	      && tmp.y >= 0 && pos.x < src->width && pos.y < src->height
	      && pos.x >= 0 && pos.y >= 0)
	    dest->color[tmp.y][tmp.x].full = src->color[pos.y][pos.x].full;
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

t_hitbox	create_hitbox(int x, int y, int width, int height)
{
  t_hitbox	result;

  result.x = x;
  result.y = y;
  result.width = width;
  result.height = height;
  return (result);
}

t_hitbox	*create_hitbox_ptr(t_bunny_position pos, int width, int height)
{
  t_hitbox	*result;

  if ((result = malloc(sizeof(t_hitbox))) == NULL)
    return (NULL);
  result->x = pos.x;
  result->y = pos.y;
  result->width = width;
  result->height = height;
  return (result);
}

int			in_hitbox(t_hitbox *hitbox, t_bunny_position *pos)
{
  if (pos->x > hitbox->x && pos->x < hitbox->x + hitbox->width
      && pos->y > hitbox->y && pos->y < hitbox->y + hitbox->height)
    return (1);
  return (0);
}
