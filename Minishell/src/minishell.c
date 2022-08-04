/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:10:15 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/24 10:47:23 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../inc/minishell.h"

int	ft_mainloop(t_main *main);
int	shlvl_init(t_main *main);

t_main	*g_glb;

static int	ft_envpinit(t_main *main, char **envp, char **argv, int argc)
{
	(void)argv;
	(void)argc;
	tcgetattr(0, &main->old);
	tcgetattr(0, &main->new);
	main->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &main->new);
	main->rval = 0;
	main->cline = NULL;
	g_glb = main;
	main->envp = init_envp(envp);
	if (!envp)
		return (1);
	main->locals = init_locals();
	if (!main->locals)
	{
		ft_freetab(main->envp);
		return (1);
	}
	ft_signal_main();
	main->error = 0;
	return (0);
}

static int	ft_first_check(t_main *main)
{
	char	*str;
	int		n;

	n = 0;
	str = 0;
	if (!*main->line)
		return (ft_myfree(main->line));
	if (ft_space_check(main->line))
		return (ft_myfree(main->line));
	if (ft_dpipe_check(main))
		return (ft_myfree(main->line));
	if (ft_open_quote(main->line))
	{
		ft_putstr_fd("minishell: unclosed quote\n", 2);
		return (ft_myfree(main->line));
	}
	if (ft_parse_error(main, str, n) || ft_single_pipe(main))
	{
		ft_putstr_fd(SPIPE, 2);
		g_glb->rval = 258;
		return (ft_myfree(main->line));
	}
	return (0);
}

static int	ft_parse(t_main *main)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	main->line = expand_variables
		(main->line, main->envp, main->locals, main->rval);
	if (!main->line)
		return (ft_freeshell(main));
	if (ft_parser(main))
		return (ft_freeshell(main));
	main->error = ft_syntax_check(main, n, j);
	if (main->error == 1)
		return (ft_freeshell_continue(main));
	if (ft_remquote(main))
		return (ft_freeshell(main));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_main	main;
	char	*tmp;

	tmp = getcwd(0, 0);
	if (!tmp)
		return (1);
	main.bindir = ft_strjoin(tmp, "/bin/");
	free(tmp);
	if (!main.bindir)
		return (1);
	if (ft_envpinit(&main, envp, argv, argc))
	{
		free(main.bindir);
		return (1);
	}
	if (!shlvl_init(&main))
	{
		free(main.bindir);
		return (1);
	}
	ft_mainloop(&main);
	return (0);
}

int	ft_mainloop(t_main *main)
{
	while (1)
	{
		if (ft_readline(main))
			return (ft_freefirst(main));
		if (ft_first_check(main))
			continue ;
		if (ft_loop(main))
			return (1);
		if (main->error && ft_myfree(main->line))
			continue ;
		if (ft_parse(main))
		{
			if (main->error)
				continue ;
			return (1);
		}
		if (ft_fillstruct(main))
			return (ft_freeshell2(main));
		if (ft_exit_check(main))
			continue ;
		ft_signal_exec();
		if (!main->error)
			main->rval = ft_exec(main);
		ft_freeshell3(main);
	}
}
