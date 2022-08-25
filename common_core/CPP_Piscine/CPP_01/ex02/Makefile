NAME	= ex02
SRC 	= main.cpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
CC		= c++ -std=c++98

all:
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re