NAME	= ex03
SRC 	= AMateria.cpp\
			Character.cpp\
			Cure.cpp\
			Ice.cpp\
			MateriaSource.cpp\
			IMateriaSource.cpp\
			main.cpp

HEADER	= AMateria.hpp\
			Character.hpp\
			ICharacter.hpp\
			Cure.hpp\
			Ice.hpp\
			MateriaSource.hpp\
			IMateriaSource.hpp\

RM		= rm -f
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g
CC		= c++

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME)

re: clean
	all

.PHONY: all clean re