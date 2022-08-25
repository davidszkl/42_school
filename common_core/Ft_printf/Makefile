NAME	= ft_printf

SRCDIR	= src

SRC	=	src/ft_printf.c \
			src/ft_output.c src/utils.c src/main.c

CFLAGS	= -Wall -Wextra -Werror

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRC:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJDIR) $(OBJS)
		gcc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -f *.o a.out

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
