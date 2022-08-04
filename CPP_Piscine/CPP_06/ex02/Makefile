NAME	= ex02
SRC 	= main.cpp A.cpp B.cpp C.cpp Base.cpp
HEADER	= A.hpp B.hpp C.hpp Base.hpp
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