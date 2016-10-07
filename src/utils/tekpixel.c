/*
** tekpixel.c for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Wed Mar  9 16:02:10 2016 victor sousa
** Last update Sun Mar 13 20:20:53 2016 victor sousa
*/

#include	        "lapin.h"

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  t_color	prev;

  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height &&
      pos->x >= 0 && pos->y >= 0)
    {
      prev =
	((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y];

      prev.argb[0] = (float)prev.argb[0] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[0] * ((float)color->argb[3] / 255));
      prev.argb[1] = (float)prev.argb[1] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[1] * ((float)color->argb[3] / 255));
      prev.argb[2] = (float)prev.argb[2] * ((255 -
					     (float)color->argb[3]) / 255)
	+ ((float)color->argb[2] * ((float)color->argb[3] / 255));
      prev.argb[3] = 255;
      ((t_color *)pix->pixels)[pos->x + pix->clipable.clip_width * pos->y]
	= prev;
    }
}
