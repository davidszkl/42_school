/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:30:55 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/26 13:55:14 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include "../inc/minishell.h"
#include "../inc/ft_exec_args.h"

void	init_r_w(t_exec_args *args, t_main *main);
int		wexitstatus(int status);
void	close_pipes(int *pipes, size_t n);
void	*exec_perror(const char *str);
int		is_c_e_u_ass(const char *s);
int		exec_c_e_u_ass(t_comm comm, char ***envp, char ***locals);
void	open_pipes(int *pipes, size_t n);
void	close_files(t_file *files, int n);
int		open_files(t_file *files, int n);
void	enter_child(t_exec_args args, t_comm comm, t_main *main);

static t_exec_args	init_exec_args(t_main *main)
{
	t_exec_args	r;

	r.n = main->pipecount + 1;
	r.pipes = 0;
	r.i = -1;
	return (r);
}

static int	fork_error(t_exec_args args, t_main *main)
{
	free(args.pipes);
	close_pipes(args.pipes, main->pipecount);
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(": ", 2);
	perror("fork");
	return (1);
}

int	ft_exec(t_main *main)
{
	t_exec_args	args;

	args = init_exec_args(main);
	if (args.n == 1 && is_c_e_u_ass(main->cline[0].argv[0]))
		return (exec_c_e_u_ass(main->cline[0], &main->envp, &main->locals));
	if (main->pipecount)
	{
		args.pipes = malloc(sizeof(int) * main->pipecount * 2);
		if (!args.pipes)
			return (1 + (int)exec_perror("malloc"));
	}
	open_pipes(args.pipes, main->pipecount);
	while (++args.i < args.n)
	{
		init_r_w(&args, main);
		main->cline[args.i].pid = fork();
		if (main->cline[args.i].pid == -1)
			return (fork_error(args, main));
		if (!main->cline[args.i].pid)
			enter_child(args, main->cline[args.i], main);
	}
	close_pipes(args.pipes, main->pipecount);
	free(args.pipes);
	waitpid(main->cline[args.i - 1].pid, &args.status, 0);
	return (wexitstatus(args.status));
}
