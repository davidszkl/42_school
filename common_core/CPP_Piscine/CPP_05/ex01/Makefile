NAME	= ex01
SRC 	= main.cpp Bureaucrat.cpp Form.cpp
HEADER	= Bureaucrat.hpp Form.hpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= clang++

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re