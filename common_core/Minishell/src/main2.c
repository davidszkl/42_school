/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:52:06 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/22 10:52:10 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	ft_chevpipe_loop(t_main *main)
{
	ft_getcount(main);
	if (main->error == 1)
		return (0);
	if (ft_read_chev(main) == 1)
		return (ft_myfreemain(main));
	if (main->error == 1)
		return (0);
	if (main->line[ft_strlen(main->line) - 1] == '|')
		if (ft_read_lpipe(main) == 1)
			return (ft_myfreemain(main));
	return (0);
}

int	ft_exit_check(t_main *main)
{
	if (!main->cline[0].argv[0])
		return (0);
	if (!main->pipecount && !ft_strncmp(main->cline[0].argv[0], "exit", -1))
	{
		write(1, "exit\n", 5);
		main->rval = ft_exit(main->cline[0].argv);
		ft_freeshell3(main);
		if (main->rval != -1)
			exit(main->rval);
		else
		{
			main->rval = 1;
			return (1);
		}
	}
	return (0);
}

int	ft_readline(t_main *main)
{
	int	n;

	n = 0;
	ft_signal_main();
	main->error = 0;
	main->line = readline(PROMPT);
	if (main->line && main->line[0])
		add_history(main->line);
	if (!main->line)
		return (1);
	while (main->line[n])
	{
		if (main->line[n] == 9)
		{
			main->temp = ft_strdup(main->line);
			free(main->line);
			main->line = ft_replace_str(main->temp, n, 1, "    ");
			free(main->temp);
			n = 0;
			continue ;
		}
		n++;
	}
	return (0);
}

int	ft_loop(t_main *main)
{
	while (ft_check_chevpipe(main->line) == 1)
		if (ft_chevpipe_loop(main))
			return (1);
	return (0);
}
