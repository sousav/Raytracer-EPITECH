##
## Makefile for raytracer1 in /home/sousa_v/rendu/lapin/gfx_raytracer1
##
## Made by victor sousa
## Login   <sousa_v@epitech.net>
##
## Started on  Tue Feb  9 01:56:43 2016 victor sousa
## Last update Sat May 21 00:55:46 2016 Philippe Lefevre
##

NAME		=	raytracer2

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

SRCDIR		=	src

RAYTRACEDIR	=	$(SRCDIR)/raytrace
PRTFDIR		=	$(SRCDIR)/editeur/my_printf
SPRTFDIR	=	$(SRCDIR)/editeur/my_sprintf
EDITDIR		=	$(SRCDIR)/editeur
LOADIR		=	$(SRCDIR)/loading
XMLDIR		=	$(SRCDIR)/xml
HITDIR		=	$(SRCDIR)/hit
UTILSDIR	=	$(SRCDIR)/utils
IMAGEDIR	=	$(SRCDIR)/image
CLIENTDIR	=	$(SRCDIR)/client
OUTPUTDIR	=	$(SRCDIR)/output
EXPORTDIR	=	$(SRCDIR)/export

INCDIR		=	inc
LIBDIR		=	lib

RM		=	rm -f

CC		=	gcc
CFLAG		=	-W -Wall -Wextra -ansi -pedantic	\
			-DMACRO	-std=c99			\
			-I/home/${USER}/.froot/include		\
			-I$(INCDIR)

LDFLAG		=	-L/home/${USER}/.froot/lib		\
			-llapin					\
			-L/usr/local/lib			\
			-lsfml-audio				\
			-lsfml-graphics				\
			-lsfml-window				\
			-lsfml-system				\
			-lstdc++ -ldl				\
			-lm -lpthread

##  MAIN  ##
SRC		=	$(SRCDIR)/main.c			\
			$(SRCDIR)/init.c			\
			$(SRCDIR)/init2.c			\
			$(SRCDIR)/loop.c			\
			$(SRCDIR)/end.c

## LOADING ##
SRC		+=	$(LOADIR)/parsing_scene.c		\
			$(LOADIR)/parsing_scene2.c		\
			$(LOADIR)/load_mat.c			\
			$(LOADIR)/load_mtl.c			\
			$(LOADIR)/load_mat_param.c		\
			$(LOADIR)/load_mat_param2.c		\
			$(LOADIR)/load_light.c			\
			$(LOADIR)/load_obj.c			\
			$(LOADIR)/load_sphere_param.c		\
			$(LOADIR)/load_triangle_param.c		\
			$(LOADIR)/load_cone_params.c		\
			$(LOADIR)/load_cone_params2.c		\
			$(LOADIR)/load_cyl_params.c		\
			$(LOADIR)/load_cyl_params2.c		\
			$(LOADIR)/load_cube_param.c		\
			$(LOADIR)/load_pill_params.c		\
			$(LOADIR)/load_pill_params2.c		\
			$(LOADIR)/load_plan_params.c		\
			$(LOADIR)/load_obj_file.c		\
			$(LOADIR)/load_obj_file2.c		\
			$(LOADIR)/load_vertex.c			\
			$(LOADIR)/load_forme.c			\
			$(LOADIR)/load_forme2.c			\
			$(LOADIR)/load_screen.c

##  HIT  ##
SRC		+=	$(HITDIR)/hit.c				\
			$(HITDIR)/sphere.c			\
			$(HITDIR)/triangle.c			\
			$(HITDIR)/cone.c			\
			$(HITDIR)/cylinder.c			\
			$(HITDIR)/plan.c

##  RAYTRACE  ##
SRC		+=	$(RAYTRACEDIR)/raytrace.c		\
			$(RAYTRACEDIR)/raytrace_threading.c	\
			$(RAYTRACEDIR)/shad_n_light.c		\
			$(RAYTRACEDIR)/shad_n_light2.c		\
			$(RAYTRACEDIR)/reflect.c		\
			$(RAYTRACEDIR)/obj_calculs.c		\
			$(RAYTRACEDIR)/obj_calculs2.c		\
			$(RAYTRACEDIR)/obj_calculs_normal.c	\
			$(RAYTRACEDIR)/obj_calculs_normal_sphere.c	\
			$(RAYTRACEDIR)/noise_init_1.c		\
			$(RAYTRACEDIR)/noise_init_2.c		\
			$(RAYTRACEDIR)/noise_init_3.c		\
			$(RAYTRACEDIR)/noise_init_4.c		\
			$(RAYTRACEDIR)/noise_init_5.c

##  XML  ##
SRC		+=	$(XMLDIR)/get_field.c			\
			$(XMLDIR)/get_field_bis.c

## PRINTF ##
SRC             +=      $(PRTFDIR)/my_disp_unprintable.c        \
                        $(PRTFDIR)/my_printf.c                  \
                        $(PRTFDIR)/my_printf2.c                 \
                        $(PRTFDIR)/my_printf3.c                 \
                        $(PRTFDIR)/my_put_nbr.c                 \
                        $(PRTFDIR)/my_put_u_nbr_base.c          \
                        $(PRTFDIR)/my_put_unbr.c                \
                        $(PRTFDIR)/my_putchar.c                 \
                        $(PRTFDIR)/my_putnbr_base.c             \
                        $(PRTFDIR)/my_putnbr_base_add.c         \
                        $(PRTFDIR)/my_putstr.c			\
			$(PRTFDIR)/my_put_fnbr.c

## SPRINTF ##
SRC             +=      $(SPRTFDIR)/my_disp_unprintable.c    	\
                        $(SPRTFDIR)/my_sprintf.c               	\
                        $(SPRTFDIR)/my_sprintf2.c              	\
                        $(SPRTFDIR)/my_sprintf3.c              	\
                        $(SPRTFDIR)/my_put_nbr.c              	\
                        $(SPRTFDIR)/my_put_u_nbr_base.c        	\
                        $(SPRTFDIR)/my_put_unbr.c               \
                        $(SPRTFDIR)/my_putnbr_base.c            \
                        $(SPRTFDIR)/my_putnbr_base_add.c        \
			$(SPRTFDIR)/my_put_fnbr.c		\
			$(SPRTFDIR)/my_strcat.c

##  EDITEUR  ##
SRC		+=	$(EDITDIR)/editor.c			\
			$(EDITDIR)/aff_light.c			\
			$(EDITDIR)/aff_mat.c			\
			$(EDITDIR)/add_obj.c			\
			$(EDITDIR)/add_obj2.c			\
			$(EDITDIR)/add_obj3.c			\
			$(EDITDIR)/add_mat.c			\
			$(EDITDIR)/edit_obj.c			\
			$(EDITDIR)/edit_obj2.c			\
			$(EDITDIR)/edit_obj3.c			\
			$(EDITDIR)/edit_light.c			\
			$(EDITDIR)/push_func.c			\
			$(EDITDIR)/push_func2.c			\
			$(EDITDIR)/edit_cam.c			\
			$(EDITDIR)/edit_cam_bis.c		\
			$(EDITDIR)/aff_obj.c			\
			$(EDITDIR)/aff_obj2.c			\
			$(EDITDIR)/aff_win.c			\
			$(EDITDIR)/add_light.c			\
			$(EDITDIR)/cmd.c			\
			$(EDITDIR)/count.c			\
			$(EDITDIR)/utils.c			\
			$(EDITDIR)/edit_mat.c			\
			$(EDITDIR)/write_xml.c

##  IMAGE  ##
SRC		+=	$(IMAGEDIR)/load_image.c		\
			$(IMAGEDIR)/disp_image.c		\
			$(IMAGEDIR)/hitbox_creator.c

##  UTILS  ##
SRC		+=	$(UTILSDIR)/tekpixel.c			\
			$(UTILSDIR)/my_tablen.c			\
			$(UTILSDIR)/my_str_to_wordtab.c		\
			$(UTILSDIR)/str_to_wordtab.c		\
			$(UTILSDIR)/my_strstr.c			\
			$(UTILSDIR)/my_atof.c			\
			$(UTILSDIR)/my_strlen.c			\
			$(UTILSDIR)/my_strcat.c			\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/my_get_float.c		\
			$(UTILSDIR)/my_realloc.c		\
			$(UTILSDIR)/key_handle.c		\
			$(UTILSDIR)/get_next_line.c		\
			$(UTILSDIR)/vect_operator.c		\
			$(UTILSDIR)/vect_operator2.c		\
			$(UTILSDIR)/vect_operator3.c		\
			$(UTILSDIR)/vect_operator4.c		\
			$(UTILSDIR)/wtf.c			\
			$(UTILSDIR)/epur_str.c

##  CLIENT  ##
SRC		+=	$(CLIENTDIR)/client.c			\
			$(CLIENTDIR)/client_init.c		\
			$(CLIENTDIR)/communicate.c		\
			$(CLIENTDIR)/command.c			\
			$(CLIENTDIR)/command2.c			\
			$(CLIENTDIR)/send_file.c		\
			$(CLIENTDIR)/client_raytrace.c		\
			$(CLIENTDIR)/client_raytrace_scene.c	\
			$(CLIENTDIR)/raytrace_to_table.c

##  OUTPUT  ##
SRC		+=	$(OUTPUTDIR)/my_putchar.c		\
			$(OUTPUTDIR)/my_putstr.c		\
			$(OUTPUTDIR)/my_put_nbr.c		\
			$(OUTPUTDIR)/my_strlen.c

##  EXPORT  ##
SRC		+=	$(EXPORTDIR)/export_to_bmp.c

OBJ		=	$(SRC:.c=.o)

all:			title $(NAME)

title		:
			@$(ECHO) $(GREEN)Raytracer$(TEAL)2$(DEFAULT)

$(NAME)		:	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(LDFLAG) &&	\
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
			$(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

.c.o		:
			@$(CC) $(CFLAG) $(LDFLAG) -c $< -o $@ && \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
			$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

clean		:
			@$(RM) $(OBJ)

fclean		:	clean
			@$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
