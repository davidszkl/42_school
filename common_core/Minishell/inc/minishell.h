/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:07:39 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/22 17:56:49 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "minishell> "
# define ERROR  "minishell"
# define SYNTAX "minishell: syntax error near unexpected token `"
# define SPIPE "minishell: syntax error near unexpected token `|'\n"

/*includes*/
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
#include <sys/wait.h>
#include <sys/param.h>
# include <readline/readline.h>
# include <readline/history.h>

/*structures*/

typedef struct s_file {
	char	*name;
	int		flags;
	int		fd;
}	t_file;

typedef struct s_comm {
	t_file	*file_in;
	t_file	*file_out;
	pid_t	pid;
	char	**argv;
	char	*line;
	int		rin;
	int		rout;
}	t_comm;

typedef struct s_chev {
	char	*path;
	char	*nbrs;
	int		nbr;
}	t_chev;

typedef struct s_main {
	struct termios	old;
	struct termios	new;
	t_comm			*cline;
	t_chev			chev;
	char			**envp;
	char			**locals;
	char			*line;
	char			*temp;
	int				dchevcount;
	int				pipecount;
	int				error;
	int				tmp;
	int				rval;
	pid_t			r;
	char			*bindir;
}	t_main;

/*checker*/

int		ft_single_pipe(t_main *main);
int		ft_check_echo(char *str);
int		ft_check_cmd(char *str);

/*parser*/

int		ft_read_chev(t_main *main);
int		ft_read_lpipe(t_main *main);
int		ft_parser(t_main *main);
int		ft_fillstruct(t_main *main);

/*expander*/

char	*expand_variables(const char *str, char **envp, char **locals, int ret);

/*executor*/

int		ft_exec(t_main *main);

/*functions*/

void	ft_child_doc(t_main *main, char *str);
char	**init_envp(char **envp);
char	**init_locals(void);
char	*ft_remquotestr(char *str);
int		ft_readline(t_main *main);
int		ft_remquote(t_main *main);
int		ft_getcount(t_main *main);
int		ft_open_quote(char *str);
int		ft_loop(t_main *main);

/*signals*/

void	ft_sigint_heredoc1(int signbr);
void	ft_sigint_heredoc2(int signbr);
void	ft_sigint_main(int signbr);
void	ft_sigint_exec(int signbr);
void	ft_sigquit(int signbr);
int		ft_signal_main(void);
int		ft_signal_exec(void);

/*errors*/

void	ft_freefiles(t_main *main, int n);
int		ft_syntax_check(t_main *main, int n, int j);
int		ft_freeshell_continue(t_main *main);
int		ft_dpipe_check(t_main *main);
int		ft_parse_error(t_main *main, char *str, int n);
int		ft_freefirst(t_main *main);
int		ft_freeshell(t_main *main);
int		ft_freeshell2(t_main *main);
int		ft_freeshell3(t_main *main);
int		ft_freeshell4(t_main *main);
int		ft_myfreemain(t_main *main);
int		ft_exit_check(t_main *main);
int		ft_tabcheck(t_main *main);
int		ft_space_check(char *str);
int		ft_myfree(char *str);
int		ft_exit(char **argv);

/*utils*/

size_t	ft_strlen(const char *str);
size_t	get_envp_size(char **envp);
char	**ft_splitq(char *str, char c);
char	*ft_replace_str(const char *s, size_t start, size_t n, const char *sub);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getword_simple(char *str, int n);
char	*ft_getword(char *str, int n);
char	*ft_strdup(const char *s1);
char	*ft_tolower(char *str);
char	*ft_itoas(int nbr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putendl_fd(char	*str, int fd);
void	ft_strcpy(char *dst, char *src);
void	ft_freetab(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isinquote_now(char *str, int index);
int		ft_putstr_fd(const char *str, int fd);
int		ft_spwordcount(char *str, int n);
int		ft_isalnumx(char *str, int n);
int		ft_check_chevpipe(char	*str);
int		ft_is_chev(char *str, int n);
int		ft_special(t_main *main);
int		ft_isinquote(char *str);
int		sort_envp(char **envp);
int		ft_isquote(char c);
int		ft_isspace(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	ft_showtab(char **tab);

/*TESTS*/

//>< salut >< hello <<a ||><< au revoi coucou <<b <<c <   
//salut << hello >> | C | < > < > <| A| F|A |FA AR AR >AR? G>?R AR|S 
//ARS A>R? < < <A ?R ?AGR> GAR |R|> 
//s << c"|"c
//salut << coucou | echo <<     bon"|"jour "|" |"|" salut << hello
//"echo"
//""
//| |

#endif
