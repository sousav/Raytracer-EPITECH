/*
** export_to_bmp.c for Raytracer in /home/lefevr_h/Workspace/Github/Raytracer/src/export
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun May 22 02:16:59 2016 Philippe Lefevre
** Last update Sun May 22 16:58:49 2016 Philippe Lefevre
*/

#include		"main.h"

int			export_to_bmp_init(t_prog *prog,
					   int fd, t_bitmap *pbitmap)
{
  my_strcpy(pbitmap->fileheader.signature, "BM");
  pbitmap->fileheader.filesize = _filesize;
  pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
  pbitmap->bitmapinfoheader.dibheadersize = sizeof(t_bitmapinfoheader);
  pbitmap->bitmapinfoheader.width = prog->win_size.x;
  pbitmap->bitmapinfoheader.height = prog->win_size.y;
  pbitmap->bitmapinfoheader.planes = _planes;
  pbitmap->bitmapinfoheader.bitsperpixel = _bitsperpixel;
  pbitmap->bitmapinfoheader.compression = _compression;
  pbitmap->bitmapinfoheader.imagesize = _pixelbytesize;
  pbitmap->bitmapinfoheader.ypixelpermeter = _ypixelpermeter ;
  pbitmap->bitmapinfoheader.xpixelpermeter = _xpixelpermeter ;
  pbitmap->bitmapinfoheader.numcolorspallette = 0;
  write (fd, pbitmap, sizeof(t_bitmap));
  free(pbitmap);
  return (0);
}

int			export_to_bmp_write(t_prog *prog, int fd,
					    t_bunny_position *pos)
{
  t_color		color;
  t_color		out;

  color = ((t_color *)prog->pix->pixels)[pos->x
      + prog->pix->clipable.clip_width * pos->y];
  out.argb[0] = color.argb[2];
  out.argb[1] = color.argb[1];
  out.argb[2] = color.argb[0];
  out.argb[3] = color.argb[3];
  write(fd, out.argb, 3);
  return (0);
}

int			export_to_bmp(t_prog *prog)
{
  t_bunny_position	pos;
  t_bitmap		*pbitmap;
  int			fd;

  if (((fd = open(prog->opt->export_path, O_CREAT | O_TRUNC | O_RDWR,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
      || ((pbitmap  = malloc(sizeof(t_bitmap))) == NULL))
    return (my_printf(2, "Erreur: cannot create %s file\n",
		      prog->opt->export_path) - 1);
  export_to_bmp_init(prog, fd, pbitmap);
  pos.y = prog->win_size.y - 1;
  while (--pos.y > 0)
    {
      pos.x = -1;
      while (++pos.x < prog->win_size.x)
	export_to_bmp_write(prog, fd, &pos);
    }
  close(fd);
  if (prog->opt->verbose)
    my_printf(1, "Rendu save in %s\n", prog->opt->export_path);
  free(prog->opt->export_path);
  return (0);
}
