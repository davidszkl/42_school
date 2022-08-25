NAME	= ex02
SRC 	= main.cpp
HEADER	= Array.hpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g
CC		= clang++

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re
