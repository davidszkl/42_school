NAME	= philo

SRCDIR	= src

SRCS	= src/philo.c \
			src/ft_actions.c src/ft_error.c src/ft_utils.c

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

INCDIR	= inc

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			$(CC) $(CFLAGS) -g -I$(INCDIR) -c $^ -o $@

all:            $(NAME)

$(OBJDIR):
			mkdir -p $(OBJDIR)

$(NAME):        $(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) -I$(INCDIR)\ $(OBJS) -o $(NAME)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
			cp ~/Desktop/Proj_init/inc.h $(INCIDR)/${NAME}.h
clean:
			$(RM) -r $(OBJDIR)

fclean:            clean
			$(RM) $(NAME)

re:                fclean all

.PHONY:            all clean fclean re install
