NAME	= webserv
CC		= c++ -Wall -Wextra -Werror -std=c++98
SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj
SRC		= $(shell find src/*.cpp)
INC		= $(shell find inc/*.hpp)
OBJ		= $(subst $(SRCDIR), $(OBJDIR), $(SRC:cpp=o))

all: $(OBJDIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

test: $(INCDIR)/*.hpp
	$(CC) -I$(INCDIR) $(SRC) -o $(NAME)

$(NAME): all

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM
	rm -rf $(OBJDIR)

re: fclean all
