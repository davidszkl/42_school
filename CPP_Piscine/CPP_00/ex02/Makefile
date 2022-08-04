NAME	= tests
SRC 	= Account.cpp tests.cpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
CC		= clang++ -std=c++98

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean fclean