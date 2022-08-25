# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 09:50:32 by dszklarz          #+#    #+#              #
#    Updated: 2021/10/22 09:50:33 by dszklarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= push_swap

SRCDIR	= src

SRCS	= src/push_swap.c \
			src/ft_error.c src/ft_ops1.c src/ft_ops2.c src/ft_solve.c \
			src/ft_solve2.c src/utils.c

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR	= inc

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			$(CC) $(CFLAGS) -g -I$(INCDIR) -c $^ -o $@
                
all:            $(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR) 

$(NAME):        $(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME)

debug:	$(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME)	

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR)

fclean:            clean
			$(RM) $(NAME)

re:                fclean all

.PHONY:            all clean fclean re install debug
