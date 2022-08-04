NAME	= ex01
SRC 	= main.cpp Zombie.cpp ZombieHorde.cpp
HEADER	= Zombie.hpp
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
CC		= c++ -std=c++98

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re