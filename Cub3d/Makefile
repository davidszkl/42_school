# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 14:09:10 by mlefevre          #+#    #+#              #
#    Updated: 2021/12/09 11:34:03 by mlefevre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRCDIR	= src

SRCS	= src/apply_movement.c\
src/check_map.c\
src/check_params.c\
src/check_params1.c\
src/cub3d.c\
src/free.c\
src/ft_init_player.c\
src/ft_loop_func.c\
src/get_img_pixel.c\
src/get_texture_color.c\
src/mlx_hooks.c\
src/mlx_init.c\
src/raytrace.c\
src/read_file.c\
src/utils1.c\
src/utils2.c\
src/utils3.c\
src/utils4.c\
src/vector_utils.c\
src/gnl/get_next_line.c src/gnl/get_next_line_utils.c

HEADERS	= inc/cub3d.h\
inc/free.h\
inc/get_next_line.h\
inc/img.h\
inc/raytrace_return.h\
inc/utils.h\
inc/vector.h

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR	= inc

MLXDIR	= mlx

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

API		= -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HEADERS)
				$(CC) $(CFLAGS) -I$(INCDIR) -I$(MLXDIR) -c $< -o $@
                
all:		$(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)
			mkdir -p $(OBJDIR)/gnl

$(NAME):	$(OBJDIR) $(OBJS)
			make -C mlx
			$(CC) $(CFLAGS) $(OBJS) $(API) -o $(NAME)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR) $(NAME).dSYM .DS_Store

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re install
