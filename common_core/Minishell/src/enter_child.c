/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:14:49 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/26 13:55:56 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include "../inc/minishell.h"
#include "../inc/ft_exec_args.h"

void	close_pipes(int *pipes, size_t n);
void	*exec_perror(const char *str);
char	*find_command_wrapper(char *str, char **envp,
			const char *bindir, int *exit_val);
void	close_files(t_file *files, int n);
int		open_files(t_file *files, int n);

static void	sub_1(t_exec_args *args, t_comm *comm, int *b)
{
	*b = open_files(comm->file_in, comm->rin);
	close_files(comm->file_in, comm->rin - 1);
	args->fd_r = comm->file_in[comm->rin - 1].fd;
}

static void	sub_2(t_exec_args *args, t_comm *comm)
{
	open_files(comm->file_out, comm->rout);
	close_files(comm->file_out, comm->rout - 1);
	args->fd_w = comm->file_out[comm->rout - 1].fd;
}

static void	sub_3(t_exec_args *args, t_main *main)
{
	close_pipes(args->pipes, main->pipecount);
	free(args->pipes);
	ft_freeshell4(main);
	exit(1);
}

static void	child_ifs(t_exec_args *args, t_comm *comm, t_main *main, int *b)
{
	if (comm->rin)
		sub_1(args, comm, b);
	if (*b && comm->rout)
		sub_2(args, comm);
	if (!*b || args->fd_r == -1 || args->fd_w == -1)
		sub_3(args, main);
	if (dup2(args->fd_r, 0) == -1)
		*b = *(int*)exec_perror("dup2");
	if (*b && dup2(args->fd_w, 1) == -1)
		*b = *(int*)exec_perror("dup2");
	if (comm->rin)
		close(args->fd_r);
	if (comm->rout)
		close(args->fd_w);
}

void	enter_child(t_exec_args args, t_comm comm, t_main *main)
{
	int		exit_val;
	char	*path;
	int		b;

	exit_val = 1;
	b = 1;
	child_ifs(&args, &comm, main, &b);
	close_pipes(args.pipes, main->pipecount);
	free(args.pipes);
	path = find_command_wrapper(comm.argv[0],
			main->envp, main->bindir, &exit_val);
	if (!path)
	{
		ft_freeshell4(main);
		exit(exit_val);
	}
	if (b)
		execve(path, comm.argv, main->envp);
	exec_perror(path);
	free(path);
	ft_freeshell4(main);
	exit(exit_val);
}
