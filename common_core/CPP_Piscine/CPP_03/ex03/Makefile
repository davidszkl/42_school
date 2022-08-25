NAME	= ex03
SRC 	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HEADER	= ClapTrap.hpp ScavTrap.hpp Fragtrap.hpp DiamondTrap.hpp
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