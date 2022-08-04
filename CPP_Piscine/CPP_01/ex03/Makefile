NAME	= ex03
SRC 	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEADER	= Weapon.hpp HumanA.hpp HumanB.hpp
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