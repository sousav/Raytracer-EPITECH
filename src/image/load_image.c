/*
** load_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:25:07 2016 Gaëtan Léandre
** Last update Sun May  1 14:42:18 2016 Gaëtan Léandre
*/

#include 		"main.h"

t_texture		*pix_array_to_texture(t_bunny_pixelarray *pix)
{
  t_texture		*ou;
  t_bunny_position	pos;

  if ((ou = malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  ou->width = pix->clipable.clip_width;
  ou->height = pix->clipable.clip_height;
  if ((ou->color = malloc(sizeof(t_color *) * (ou->height + 1))) == NULL)
    return (NULL);
  pos.y = 0;
  while (pos.y < ou->height)
    {
      if ((ou->color[pos.y] = malloc(4 * (ou->width + 1))) == NULL)
	return (NULL);
      pos.x = 0;
      while (pos.x < ou->width)
	{
	  ou->color[pos.y][pos.x].full =
	    ((t_color *)pix->pixels)[pos.y * ou->width + pos.x].full;
	  pos.x++;
	}
      pos.y++;
    }
  bunny_delete_clipable(&pix->clipable);
  return (ou);
}

t_texture		*create_text_uni(int width, int height,
					 unsigned int col)
{
  int			x;
  int			y;
  t_texture		*ou;

  if ((ou = malloc(sizeof(t_texture))) == NULL)
    return (NULL);
  ou->width = width;
  ou->height = height;
  if ((ou->color = malloc(sizeof(t_color *) * (ou->height + 1))) == NULL)
    return (NULL);
  y = 0;
  while (y < ou->height)
    {
      if ((ou->color[y] = malloc(4 * (ou->width + 1))) == NULL)
	return (NULL);
      x = 0;
      while (x < ou->width)
      	{
      	  ou->color[y][x].full = col;
	  x++;
	}
      y++;
    }
  return (ou);
}

t_texture      		*load_image(const char *file)
{
  t_bunny_pixelarray	*tmp;

  if ((tmp = bunny_load_pixelarray(file)) == NULL)
    return (NULL);
  return (pix_array_to_texture(tmp));
}
