# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 09:43:30 by dszklarz          #+#    #+#              #
#    Updated: 2021/10/14 09:43:43 by dszklarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME    = minitalk

NAME1	= client

NAME2	= server

SRCDIR	= src

SRC	=	src/ft_printf.c src/ft_output.c src/utils.c src/client.c src/server.c

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRC:.c=.o))

INCDIR	= inc

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)

$(NAME): $(NAME1) $(NAME2)

$(NAME1): $(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) obj/ft_printf.o obj/ft_output.o obj/client.o \
			obj/utils.o -o $(NAME1)

$(NAME2): $(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) obj/server.o obj/ft_printf.o obj/ft_output.o \
			obj/utils.o -o $(NAME2)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c

clean:
			$(RM) -r $(OBJDIR)

fclean: clean
		$(RM) $(NAME1) $(NAME2)

re: fclean all
