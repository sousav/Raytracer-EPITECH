/*
** disp_image.c for image in /Users/leandr_g/Documents/Shared folder/TekAdventure/src/image/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Wed Apr  6 23:28:22 2016 Gaëtan Léandre
** Last update Sun May  1 14:32:19 2016 Victor Sousa
*/

#include 		"main.h"

void			put_image(t_texture *bmp,
				  t_bunny_pixelarray *pix,
				  t_bunny_position *pos)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  i = 0;
  tmp.y = pos->y;
  while (i < bmp->height)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < bmp->width)
	{
	  tekpixel(pix, &tmp, &bmp->color[i][j]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

void			place_image(t_hitbox pos,
				    t_hitbox fetch,
				    t_texture *tex,
				    t_bunny_pixelarray *pix)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  i = 0;
  tmp.y = pos.y;
  while (i < pos.height)
    {
      j = 0;
      tmp.x = pos.x;
      while (j < pos.width)
	{
	  tekpixel(pix, &tmp,
		   &tex->color[(int)(((float)i / (float)pos.height) *
				(float)(fetch.height) + (float)fetch.y)]
		   [(int)(((float)j / (float)pos.width)
		     * (float)(fetch.width) + (float)fetch.x)]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}

void			redim_image(t_hitbox *pos,
				    t_texture *tex,
				    t_bunny_pixelarray *pix)
{
  t_bunny_position	tmp;
  int			i;
  int			j;

  if (pos == NULL)
    return;
  i = 0;
  tmp.y = pos->y;
  while (i < pos->height)
    {
      j = 0;
      tmp.x = pos->x;
      while (j < pos->width)
	{
	  tekpixel(pix, &tmp,
		   &tex->color[(int)(((float)i / (float)pos->height) *
				(float)(tex->height))]
		   [(int)(((float)j / (float)pos->width)
		     * (float)(tex->width))]);
	  tmp.x++;
	  j++;
	}
      tmp.y++;
      i++;
    }
}
