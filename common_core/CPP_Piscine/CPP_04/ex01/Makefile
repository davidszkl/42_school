NAME	= ex01
SRC 	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
HEADER	= Animal.hpp Dog.hpp Cat.hpp Brain.hpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -std=c++98
CC		= c++

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re