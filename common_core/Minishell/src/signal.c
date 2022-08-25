/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:47:34 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/17 12:47:36 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

extern t_main	*g_glb;

static void	ft_signal_main2(int signbr)
{
	if (signbr == SIGINT)
	{
		g_glb->rval = 1;
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signbr == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sigint_exec(int signbr)
{
	int	n;

	n = -1;
	if (signbr == SIGINT)
	{
		ft_putstr_fd("^C\n", 2);
		rl_on_new_line();
		while (g_glb->cline[++n].line)
			if (g_glb->cline[n].pid)
				kill(g_glb->cline[n].pid, SIGINT);
	}
	else if (signbr == SIGQUIT)
	{
		ft_putstr_fd("^", 2);
		write(2, "\\", 1);
		ft_putstr_fd("Quit: 3\n", 2);
		rl_on_new_line();
		while (g_glb->cline[++n].line)
			if (g_glb->cline[n].pid)
				kill(g_glb->cline[n].pid, SIGQUIT);
	}
}

int	ft_signal_main(void)
{
	signal(SIGINT, ft_signal_main2);
	signal(SIGQUIT, ft_signal_main2);
	return (0);
}

int	ft_signal_exec(void)
{	
	signal(SIGINT, ft_sigint_exec);
	signal(SIGQUIT, ft_sigint_exec);
	return (0);
}

void	ft_sigint_heredoc2(int signbr)
{
	(void)signbr;
	write(1, "\n", 1);
	rl_on_new_line();
	exit(0);
}
