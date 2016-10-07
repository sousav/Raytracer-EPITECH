##
## Makefile for test in /home/leandr_g/Shared/testServer
##
## Made by
## Login   <leandr_g@epitech.net>
##
## Started on  Wed May  4 23:49:13 2016
## Last update Mon May 16 10:26:15 2016 Philippe Lefevre
##

NAME		=	server

CFLAGS		=	-W -Wall -Werror -pedantic		\
			-I./include

SPRTFDIR	=	src/my_sprintf
PRTFDIR		=	src/my_printf

SRC		=	src/main.c				\
			src/main2.c				\
			src/comunicate.c			\
			src/command.c				\
			src/command2.c				\
			src/connection.c			\
			src/reciv_img.c				\
			src/reciv_img2.c			\
			src/recive_and_launch.c

## SPRINTF ##
SRC             +=      $(SPRTFDIR)/my_disp_unprintable.c    	\
	                $(SPRTFDIR)/my_sprintf.c               	\
                        $(SPRTFDIR)/my_sprintf2.c              	\
			$(SPRTFDIR)/my_sprintf3.c              	\
		        $(SPRTFDIR)/my_sprintf4.c              	\
		        $(SPRTFDIR)/my_put_nbr.c              	\
		        $(SPRTFDIR)/my_put_u_nbr_base.c        	\
		        $(SPRTFDIR)/my_put_unbr.c               \
		        $(SPRTFDIR)/my_putnbr_base.c            \
		        $(SPRTFDIR)/my_putnbr_base_add.c        \
			$(SPRTFDIR)/my_put_fnbr.c		\
			$(SPRTFDIR)/my_strcat.c

SRC             +=      $(PRTFDIR)/my_disp_unprintable.c        \
			$(PRTFDIR)/my_printf.c                  \
			$(PRTFDIR)/my_printf2.c                 \
			$(PRTFDIR)/my_printf3.c                 \
			$(PRTFDIR)/my_printf4.c                 \
			$(PRTFDIR)/my_put_nbr.c                 \
			$(PRTFDIR)/my_put_u_nbr_base.c          \
			$(PRTFDIR)/my_put_unbr.c                \
			$(PRTFDIR)/my_putchar.c                 \
			$(PRTFDIR)/my_putnbr_base.c             \
			$(PRTFDIR)/my_putnbr_base_add.c         \
			$(PRTFDIR)/my_putstr.c			\
			$(PRTFDIR)/my_put_fnbr.c


SRC		+=	src/get_next_line.c			\
			src/utils.c				\
			src/str_to_wordtab.c			\
			src/send_file.c				\
			src/xml/get_field.c			\
			src/xml/get_field_bis.c			\
			src/my_getnbr.c

OBJ		=	$(SRC:.c=.o)


all		:	$(NAME)

$(NAME)		:	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean		:
			rm -rf $(OBJ)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
