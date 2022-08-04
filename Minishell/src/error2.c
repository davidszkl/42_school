/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:37:24 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/22 13:45:21 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

extern t_main	*g_glb;

int	ft_parse_error(t_main *main, char *str, int n)
{
	while (main->line[n])
	{
		str = main->line;
		if (ft_is_chev(str, n++))
		{
			if (str[n] && str[n] == '|' && str[n + 1]
				&& ft_is_chev(str, n - 1) == 4)
			{
				main->line = ft_replace_str(str, n, ft_strlen(str) - n,
						&str[n + 1]);
				free(str);
			}
			else
			{
				while (ft_isspace(str[n]) || (ft_is_chev(str, n - 1) > 0
						&& ft_is_chev(str, n - 1) < 2))
					n++;
				if (str[n] == '|')
					return (1);
			}
		}
	}
	return (0);
}

int	ft_tabcheck(t_main *main)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (main->cline[n].argv[j])
	{
		if (ft_is_chev(main->cline[n].argv[j], 0)
			&& (!main->cline[n].argv[j + 1]
				|| ft_is_chev(main->cline[n].argv[j + 1], 0)))
			return (1);
		j++;
	}
	return (0);
}

int	ft_dpipe_check(t_main *main)
{
	int	count;
	int	n;

	count = 0;
	n = 0;
	while (main->line[n])
	{
		if (main->line[n++] == '|' && !ft_isinquote_now(main->line, n - 1))
			while (main->line[n] && count++ >= 0)
				if (!ft_isspace(main->line[n++]))
					break ;
		if (main->line[n - 1] == '|' && count == 1)
		{
			ft_putstr_fd("minishell: binary operand '||' not supported\n", 2);
			return (1);
		}
		else if (main->line[n - 1] == '|' && count)
		{
			g_glb->rval = 258;
			ft_putstr_fd(SPIPE, 2);
			return (1);
		}
	}
	return (0);
}

int	ft_syntax_check(t_main *main, int n, int j)
{
	while (main->cline[n].line)
	{
		j = 0;
		while (main->cline[n].argv[j])
		{
			if (ft_is_chev(main->cline[n].argv[j], 0))
			{
				if (!main->cline[n].argv[j + 1]
					|| ft_is_chev(main->cline[n].argv[j + 1], 0))
				{
					ft_putstr_fd(SYNTAX, 2);
					g_glb->rval = 258;
					if (!main->cline[n].argv[j + 1])
						ft_putstr_fd("newline", 2);
					else
						ft_putstr_fd(main->cline[n].argv[j + 1], 2);
					ft_putstr_fd("'\n", 2);
					return (1);
				}
			}
			j++;
		}
		n++;
	}
	return (0);
}
