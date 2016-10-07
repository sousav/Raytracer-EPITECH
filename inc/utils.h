/*
** utils.h for raytracer in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Tue Feb  9 05:29:22 2016 victor sousa
** Last update Sun May 22 17:22:39 2016 Philippe Lefevre
*/

#ifndef			UTILS_H_
# define		UTILS_H_

# include		"main.h"

# define 		DTR(ang) 	((ang) / 180.0 * M_PI)
# define		RTD(rad) 	((rad) * (180.0 / M_PI))
# define		invsqrtf(x)	(1.0f / sqrt(x))

int			my_strlen(char *str);
char			*read_opti(char *file);
int			my_tablen(char **str);
char			*my_strstr(char *str, char *to_find);
char			*my_strcat(char *dest, char *src);
char			**my_str_to_wordtab(char *str, int i, int j);
char			**str_to_wordtab(char *str, char *delim);
int			my_getnbr(char *str);
float			my_get_float(char *p);
char			*my_realloc(char *str, int size);
char			*get_next_line(const int fd);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int nb);
char			*my_itoa(int nb);
char			*my_strcatpp(char *desc, char *src);
char			*epur_str(char *str, char *separ);
char			*my_strcpy(char *dest, char *src);
char			*my_strdup(char *str);

/* vector operator */
float                   mult_vector(const t_coord v1, const t_coord v2);
t_coord                 minus_vector(const t_coord v1, const t_coord v2);
t_coord                 minus_point(const t_point v1, const t_point v2);
t_coord                 add_vector(const t_coord v1, const t_coord v2);
t_coord                 float_time_vector(float c, const t_coord v);
t_coord                 float_minus_vector(float c, const t_coord v);
t_coord                 float_plus_vector(float c, const t_coord v);
t_coord			crossProduct(t_coord c1, t_coord c2);
t_coord                 normalize(t_coord vec);
t_coord                 normalize_p(t_point vec);
float			min(float a, float b);
float			max(float a, float b);
double			my_atof(char *str);
int			my_isnum(char ch);
/* WTF */
float			invsqrt(float number);

/* tcore */
void                    tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym key,
			    void *p);

#endif		      /*UTILS_H*/
