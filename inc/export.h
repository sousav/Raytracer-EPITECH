/*
** export.h for Raytracer in /home/lefevr_h/Workspace/Github/Raytracer/inc
**
** Made by Philippe Lefevre
** Login   <lefevr_h@epitech.net>
**
** Started on  Sun May 22 02:17:24 2016 Philippe Lefevre
** Last update Sun May 22 04:59:24 2016 Philippe Lefevre
*/

#ifndef			EXPORT_H_
# define		EXPORT_H_

# include		<stdio.h>
# include		<stdint.h>
# include		<string.h>
# include		<malloc.h>

# define		_height		720
# define		_width		1080
# define		_bitsperpixel	24
# define		_planes		1
# define		_compression	0
# define		_pixelbytesize	_height * _width * _bitsperpixel / 4
# define		_filesize	_pixelbytesize + sizeof(t_bitmap)
# define		_xpixelpermeter	0x130B //2835 , 72 DPI
# define		_ypixelpermeter 0x130B //2835 , 72 DPI
# define		pixel		0x0F
# pragma		pack(push,1)

typedef struct		s_fileheader
{
  char			signature[2];
  uint32_t		filesize;
  uint32_t		reserved;
  uint32_t		fileoffset_to_pixelarray;
}			t_fileheader;

typedef struct		s_bitmapinfoheader
{
  uint32_t		dibheadersize;
  uint32_t		width;
  uint32_t		height;
  uint16_t		planes;
  uint16_t		bitsperpixel;
  uint32_t		compression;
  uint32_t		imagesize;
  uint32_t		ypixelpermeter;
  uint32_t		xpixelpermeter;
  uint32_t		numcolorspallette;
  uint32_t		mostimpcolor;
}			t_bitmapinfoheader;

typedef struct		s_bitmap
{
  t_fileheader		fileheader;
  t_bitmapinfoheader	bitmapinfoheader;
}			t_bitmap;

# pragma		pack(pop)

int			export_to_bmp(t_prog *prog);

#endif		      /* !EXPORT_H_ */
