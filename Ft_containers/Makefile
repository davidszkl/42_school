NAME	= main
SRCS	= main.cpp

HEADERS	= pair.hpp\
			RandIter.hpp\
			RBTree.hpp\
			ReverseRandIter.h\
			utils.hpp\

OBJDIR	= obj

OBJS	= $(subst $(SRCS), $(OBJDIR), $(SRCS:.cpp=.o))

INCDIR	= utils

CC		= c++

RM		= rm -f

CFLAGS	= -g -Wall -Wextra -Werror

all:	$(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			mv *.o obj/

$(OBJDIR)/%.o:	$(SRCS) $(HEADERS)
				$(CC) $(CFLAGS) -I$(INCDIR)  -c $< -o $@

$(OBJDIR):
			mkdir -p $(OBJDIR)



install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR) $(NAME).dSYM .DS_Store

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re install