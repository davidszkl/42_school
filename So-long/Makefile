SRCS = src/main.c \
		src/parser.c src/utils.c src/ft_error.c src/mlx_base.c\
		src/ft_error2.c src/ft_keyhook.c src/ft_mousehook.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
API = -framework OpenGL -framework AppKit
NAME = so_long

all: ${NAME}

${NAME}: ${OBJS}
		make -C mlx
		gcc -c ${CFLAGS} ${SRCS}
		gcc ${CFLAGS} -o  ${NAME} -lmlx ${API} ${OBJS}

clean:
		rm -f src/*.o *.o

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
