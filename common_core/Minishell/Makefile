# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 10:09:38 by dszklarz          #+#    #+#              #
#    Updated: 2021/12/08 09:04:16 by dszklarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= minishell

SRCDIR	= src

OBJDIR	= obj

OBJS	= $(subst $(SRCDIR), $(OBJDIR), $(SRCS:.c=.o))

EXPORT = export

UNSET = unset

CD = cd

ECHO = echo

PWD = pwd

ENV = env

EXIT = exit

BINDIR = bin

INCDIR	= inc

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

LIB		= -lreadline

IREAD = -I/Users/$(USER)/.brew/opt/readline/include

LREAD = -L/Users/$(USER)/.brew/opt/readline/lib

SRCS = $(addprefix $(SRCDIR)/,\
	check.c\
	enter_child.c\
	envp_utils.c\
	error.c\
	error2.c\
	error3.c\
	error4.c\
	expand_variables.c\
	expand_variables_utils.c\
	fill_struct.c\
	find_command.c\
	ft_assign.c\
	ft_atoi.c\
	ft_cd.c\
	ft_exec.c\
	ft_exec_utils.c\
	ft_exec_utils_2.c\
	ft_exec_utils_3.c\
	ft_exit.c\
	ft_export.c\
	ft_export_utils.c\
	ft_export_utils_2.c\
	ft_export_utils_3.c\
	ft_isalnum.c\
	ft_itoa.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_splitq.c\
	ft_unset.c\
	is_valid_export_args_2.c\
	main2.c\
	minishell.c\
	parser.c\
	read_chev.c\
	read_chev2.c\
	read_lpipe.c\
	remove_quotes.c\
	signal.c\
	signal2.c\
	to_erase.c\
	utils.c\
	utils2.c\
	utils3.c\
	utils4.c\
	utils5.c\
	print_empty_export.c\
	shlvl_init.o\
	)

ECHO_OBJS = $(addprefix $(OBJDIR)/, builtins/echo_main.o\
			ft_putstr_fd.o\
			ft_unset.o\
			utils.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			to_erase.o\
			print_empty_export.o\
			)

CD_OBJS = $(addprefix $(OBJDIR)/, builtins/cd_main.o\
			ft_assign.o\
			is_valid_export_args_2.o\
			ft_exec.o\
			ft_exec_utils.o\
			ft_exec_utils_2.o\
			ft_exec_utils_3.o\
			enter_child.o\
			ft_cd.o\
			find_command.o\
			ft_split.o\
			ft_putstr_fd.o\
			ft_unset.o\
			utils.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			to_erase.o\
			print_empty_export.o\
			expand_variables.o\
			expand_variables_utils.o\
			ft_itoa.o\
			)

PWD_OBJS = $(addprefix $(OBJDIR)/, builtins/pwd_main.o\
			ft_unset.o\
			utils.o\
			ft_putstr_fd.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			to_erase.o\
			print_empty_export.o\
			)

EXPORT_OBJS = $(addprefix $(OBJDIR)/, builtins/export_main.o\
			ft_export.o\
			envp_utils.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			ft_putstr_fd.o\
			utils.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			error.o\
			error4.o\
			to_erase.o\
			print_empty_export.o\
			)

ASSIGN_OBJS = $(addprefix $(OBJDIR)/, builtins/export_main.o\
			ft_assign.o\
			ft_export.o\
			envp_utils.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			ft_putstr_fd.o\
			utils.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			error.o\
			error4.o\
			to_erase.o\
			print_empty_export.o\
			)

UNSET_OBJS = $(addprefix $(OBJDIR)/, builtins/unset_main.o\
			ft_unset.o\
			utils.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			ft_putstr_fd.o\
			to_erase.o\
			print_empty_export.o\
			)

ENV_OBJS = $(addprefix $(OBJDIR)/, builtins/env_main.o\
			to_erase.o\
			ft_unset.o\
			utils.o\
			ft_putstr_fd.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			to_erase.o\
			print_empty_export.o\
			)

EXIT_OBJS = $(addprefix $(OBJDIR)/, builtins/exit_main.o\
			ft_atoi.o\
			ft_exit.o\
			ft_unset.o\
			utils.o\
			ft_putstr_fd.o\
			utils2.o\
			utils3.o\
			utils4.o\
			utils5.o\
			envp_utils.o\
			ft_export.o\
			ft_export_utils.o\
			ft_export_utils_2.o\
			ft_export_utils_3.o\
			error.o\
			error4.o\
			ft_isalnum.o\
			to_erase.o\
			print_empty_export.o\
			)

BUILTINS = $(addprefix $(BINDIR)/, $(ECHO)\
		   $(CD)\
		   $(PWD)\
		   $(EXPORT)\
		   assign\
		   $(UNSET)\
		   $(ENV)\
		   $(EXIT))

all:	$(NAME) $(BINDIR) $(BUILTINS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h
			$(CC) $(CFLAGS) -I$(INCDIR) $(IREAD) -c $< -o $@

$(OBJDIR)/builtins/%.o: $(SRCDIR)/builtins/%.c
			$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@           

$(BINDIR)/assign: $(ASSIGN_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(ECHO): $(ECHO_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(CD): $(CD_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(PWD): $(PWD_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(EXPORT): $(EXPORT_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(UNSET): $(UNSET_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(ENV): $(ENV_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(BINDIR)/$(EXIT): $(EXIT_OBJS)
	$(CC) $(CFLAGS)  -Iinc $^ -o $@

$(OBJDIR):
			mkdir -p $(OBJDIR)
			mkdir $(OBJDIR)/builtins
$(BINDIR):
	mkdir $(BINDIR)

$(NAME):        $(OBJDIR) $(OBJS)
			$(CC) $(CFLAGS) $(LIB)  $(OBJS) $(LREAD) -o $(NAME)

install:
			mkdir $(OBJDIR) $(SRCDIR) $(INCDIR) $(BINDIR)
			touch $(INCDIR)/$(NAME).h
			touch $(SRCDIR)/$(NAME).c
clean:
			$(RM) -r $(OBJDIR)

fclean:	clean
			$(RM) -r $(NAME).dSYM
			$(RM) $(NAME)
			$(RM) -r $(BINDIR)

re:	fclean all

.PHONY:	all clean fclean re install
