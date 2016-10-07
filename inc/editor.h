/*
** editor.h for  in /Users/ethankerdelhue/Documents/Shared/Raytracer/includes/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Apr 25 04:09:19 2016 Ethan Kerdelhue
** Last update Mon May 16 09:35:39 2016 Philippe Lefevre
*/

#ifndef			EDITOR_H_
# define		EDITOR_H_

# include		"main.h"

# define		ERR_NOCMD		-1
# define 		ERR_NOACC		-2
# define		ERR_NOSTR		-3
# define		ERR_NOFD		-4

int			editor(int ac, char **av);
int			aff_light(int fd, t_light_list *light);
int			aff_light_list(int fd, t_prog *prog);
int			aff_mat(int fd, t_mat_list *mat);
int			aff_mat_list(int fd, t_prog *prog);
int			aff_obj_list(int fd, t_prog *prog);
int			aff_obj_triangle(int fd, t_obj_list *obj, int i);
int			aff_obj_sphere(int fd, t_obj_list *obj);
int			aff_obj(int fd, t_obj_list *obj);
int			aff_win_prop(int fd, t_prog *prog);
t_cmd			*init_cmd(t_cmd *cmd);
int			count_material(t_prog *prog);
int			count_light(t_prog *prog);
int			count_object(t_prog *prog);
int			put_error(int error);
void			free_tab(char **tab);
int			my_access(char *file);
int			disp_info();
int			check_cmd(t_prog *prog);
int			write_xml(t_prog *prog);
int			write_fd_xml(int fd, t_prog *prog);
char			*get_type(char c);
int			fill_struct(t_prog *prog);
int			aff_help(t_prog *prog);
int			aff_xml(t_prog *prog);
int			add_obj(t_prog *prog);
int			edit_win_size_x(t_prog *prog);
int			edit_win_size_y(t_prog *prog);
int			edit_win(t_prog *prog);
int			edit_point(t_point *tmp);
int			edit_cam_pos(t_prog *prog);

			/* PUSH FUNC */
int			push_sphere(t_prog *prog, t_sphere sph);
int			push_mat(t_prog *prog, t_mat_list mat);
int			push_cone(t_prog *prog, t_cone con);
int			push_plan(t_prog *prog, t_plan pla);
int			push_cylindre(t_prog *prog, t_cylin cyl);
int			push_circle(t_prog *prog, t_circle cir);
int			push_triangle(t_prog *prog, t_triangle tri);
int			push_pillule(t_prog *prog, t_cylin cyl);

int			check_material_id(t_prog *prog, char m_id);
int			add_obj_sphere(t_prog *prog);
int			add_mat_s(t_prog *prog);
int			add_light_s(t_prog *prog);
t_coord			*get_coord(t_coord *tmp);
int			edit_obj(t_prog *prog);
int			aff_obj_spec(t_prog *prog, int id);
t_obj_list		*get_obj_ptr(t_prog *prog, int id);
t_obj_list		*get_obj_ptr(t_prog *prog, int id);
int			edit_coord(t_coord *tmp);
int			check_obj_id(t_prog *prog, int id);
char			edit_material_id(t_prog *prog, char mat);
int			edit_sphere(t_prog *prog, t_sphere *sph);
int			edit_plan(t_prog *prog, t_plan *pla);
int			edit_triangle(t_prog *prog, t_triangle *tri);
int			edit_cylindre(t_prog *prog, t_cylin *cyl);
int			edit_cone(t_prog *prog, t_cone *con);
int			edit_sphere(t_prog *prog, t_sphere *sph);
int			edit_mat(t_prog *prog);
int			edit_cam(t_prog *prog);
int			edit_point(t_point *tmp);
int			edit_light(t_prog *prog);
int			edit_coord(t_coord *tmp);
char			get_material(t_prog *prog);
int			add_obj_plan(t_prog *prog);
int			add_obj_cone(t_prog *prog);
int			add_obj_cylindre(t_prog *prog);
int			add_obj_pillule(t_prog *prog);
int			add_obj_circle(t_prog *prog);
int			check_material_id(t_prog *prog, char m_id);
t_coord			*get_coord(t_coord *tmp);
char			get_material(t_prog *prog);
int			add_obj_triangle(t_prog *prog);
int			add_obj_sphere(t_prog *prog);
int			aff_obj_list(int fd, t_prog *prog);
int			aff_obj_triangle(int fd, t_obj_list *obj, int i);
int			aff_obj_sphere(int fd, t_obj_list *obj);
int			aff_obj_plan(int fd, t_obj_list *obj);
int			aff_obj_cone(int fd, t_obj_list *obj);
int			push_cone(t_prog *prog, t_cone con);
int			push_plan(t_prog *prog, t_plan pla);
int			push_sphere(t_prog *prog, t_sphere sph);

#endif		      /*EDITOR_H_*/
