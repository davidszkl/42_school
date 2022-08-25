/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:04:06 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/22 17:58:13 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

void	ft_freetab(char **tab)
{
	int	n;

	n = 0;
	while (tab[n])
	{
		free(tab[n]);
		n++;
	}
	free(tab[n]);
	free(tab);
}

int	ft_freeshell(t_main *main)
{
	int	n;

	n = 0;
	while (main->cline[n].line)
	{
		free(main->cline[n].line);
		ft_freetab(main->cline[n++].argv);
	}
	free(main->line);
	free(main->cline);
	ft_freetab(main->envp);
	ft_freetab(main->locals);
	free(main->bindir);
	return (1);
}

int	ft_freeshell2(t_main *main)
{
	int	n;

	n = 0;
	while (main->cline[n].line)
	{
		ft_freefiles(main, n);
		free(main->cline[n].file_in);
		free(main->cline[n].file_out);
		free(main->cline[n].line);
		ft_freetab(main->cline[n++].argv);
	}
	free(main->line);
	free(main->cline);
	ft_freetab(main->envp);
	ft_freetab(main->locals);
	free(main->bindir);
	return (1);
}

int	ft_freeshell3(t_main *main)
{
	int	n;

	n = 0;
	while (main->cline[n].line)
	{	
		ft_freefiles(main, n);
		free(main->cline[n].file_in);
		free(main->cline[n].file_out);
		free(main->cline[n].line);
		ft_freetab(main->cline[n++].argv);
	}
	free(main->line);
	free(main->cline);
	return (0);
}

int	ft_freeshell4(t_main *main)
{
	int	n;

	n = 0;
	while (main->cline[n].line)
	{
		ft_freefiles(main, n);
		free(main->cline[n].file_in);
		free(main->cline[n].file_out);
		free(main->cline[n].line);
		ft_freetab(main->cline[n++].argv);
	}
	free(main->line);
	free(main->cline);
	ft_freetab(main->envp);
	ft_freetab(main->locals);
	free(main->bindir);
	tcsetattr(0, TCSANOW, &main->old);
	return (0);
}
