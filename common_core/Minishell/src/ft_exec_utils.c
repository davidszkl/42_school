/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:11:15 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 12:45:56 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include "../inc/ft_exec_args.h"
#include "../inc/minishell.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	close_pipes(int *pipes, size_t n)
{
	n = n * 2;
	while (n--)
		close(*pipes++);
}

void	*exec_perror(const char *str)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(": ", 2);
	perror(str);
	return (0);
}

int	is_abs_path(const char *str)
{
	return (!ft_strncmp(str, "/", 1) || !ft_strncmp(str, "./", 2)
		|| !ft_strncmp(str, "../", 3));
}

void	init_r_w(t_exec_args *args, t_main *main)
{
	if (((int)args->i - 1) * 2 < 0)
		args->fd_r = 0;
	else
		args->fd_r = args->pipes[((int)args->i - 1) * 2];
	if (((int)args->i - 1) * 2 + 3 > main->pipecount * 2 - 1)
		args->fd_w = 1;
	else
		args->fd_w = args->pipes[((int)args->i - 1) * 2 + 3];
}

int	wexitstatus(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			return (131);
		else if (WTERMSIG(status) == SIGINT)
			return (130);
	}
	return (((*(int *)&(status)) >> 8) & 0x000000ff);
}
