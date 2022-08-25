NAME	= ex02
SRC 	= main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
HEADER	= Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
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