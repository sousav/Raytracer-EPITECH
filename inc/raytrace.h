/*
** raytrace.h for raytracing in /home/sousa_v/rendu/lapin/gfx_raytracer1
**
** Made by victor sousa
** Login   <sousa_v@epitech.net>
**
** Started on  Fri Mar 11 01:05:12 2016 victor sousa
** Last update Sat May 21 02:18:45 2016 Philippe Lefevre
*/

#ifndef			RAYTRACE_H_
# define		RAYTRACE_H_

# include		"main.h"

# define		MAX_DEPTH		10
# define		SIZE_TILE		101

typedef struct		s_noise
{
  int			X;
  int			Y;
  int			Z;
  double		u;
  double		v;
  double		w;
  int			A;
  int			AA;
  int			AB;
  int			B;
  int			BA;
  int			BB;
  int			*p;
}			t_noise;

typedef struct		s_normal_sphere
{
  t_coord		vn;
  t_coord		ve;
  t_coord		vp;
  float			phi;
  float			theta;
  float 		u;
  float 		v;
}			t_normal_sphere;

int                     raytrace(t_prog *prog);
int                     raytrace_threading(t_prog *prog, int nb_client,
					   int all_client);
t_color			raytrace_loop(t_prog *prog,
				      t_raycast *rcast,
				      t_bunny_position pos);

unsigned int		calcul_pixel(t_prog *prog,
				     t_raycast raycast,
				     t_bunny_position pos);
void                    process_shadow(t_prog *prog, t_raycast *rcast);
int                     process_light(t_prog *prog, t_raycast *rcast);
void                    process_reflect(t_raycast *rcast);
int                     reflect_loop(t_prog *prog, t_raycast *rcast);

/*OBJECT CALCULS*/
int			calc_normale(t_prog *prog, t_raycast *rcast);
void			calc_sphere_normale(t_prog *prog, t_raycast *rcast);
void			calc_triangle_normale(t_prog *prog, t_raycast *rcast);
void			calc_plan_normale(t_prog *prog, t_raycast *rcast);
void			calc_cone_normale(t_prog *prog, t_raycast *rcast);
void			calc_cyl_normale(t_prog *prog, t_raycast *rcast);
void			calc_circle_normale(t_prog *prog, t_raycast *rcast);
double			fade(double t);
void			noise_init(int p[512]);
void			noise_init_0(int p[512]);
void			noise_init_1(int p[512]);
void			noise_init_2(int p[512]);
void			noise_init_3(int p[512]);
void			noise_init_4(int p[512]);
void			noise_init_5(int p[512]);
void			noise_init_6(int p[512]);
void			noise_init_7(int p[512]);
void			noise_init_8(int p[512]);
void			noise_init_9(int p[512]);
void			noise_init_10(int p[512]);
void			noise_init_11(int p[512]);
void			noise_init_12(int p[512]);
void			noise_init_13(int p[512]);
void			noise_init_14(int p[512]);
void			noise_init_15(int p[512]);
void			noise_init_16(int p[512]);
void			noise_init_17(int p[512]);
void			noise_init_18(int p[512]);
void			noise_init_19(int p[512]);
void			noise_init_20(int p[512]);
void			noise_init_21(int p[512]);
void			noise_init_22(int p[512]);
double			noise_end(t_noise noise, double x, double y, double z);
void			calc_sphere_normale_bis(t_raycast *rcast,
						t_normal_sphere sphere);
int			damier(t_coord *pos);
int                     process_light(t_prog *prog, t_raycast *rcast);

#endif		      /*RAYTRACE_H*/
