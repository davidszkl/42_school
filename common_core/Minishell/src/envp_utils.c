/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 08:39:25 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/10 12:10:57 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

size_t	get_envp_size(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

int	sort_envp(char **envp)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	j = -1;
	while (envp[++j])
	{
		i = -1;
		while (envp[++i] && envp[i + 1])
		{
			if (ft_strncmp(envp[i], envp[i + 1], -1) > 0)
			{
				tmp = envp[i];
				envp[i] = envp[i + 1];
				envp[i + 1] = tmp;
			}
		}
	}
	return (1);
}

static int	check_r(char **r, size_t l)
{
	int		b;
	size_t	i;

	i = -1;
	b = 1;
	while (++i < l)
		b *= r[i] != 0;
	if (b)
		return (1);
	i = -1;
	while (++i < l)
		free(r[i]);
	free(r);
	return (0);
}

char	**init_locals(void)
{
	char	**r;

	r = malloc(sizeof(char *));
	if (!r)
		return (0);
	r[0] = 0;
	return (r);
}

char	**init_envp(char **envp)
{
	const size_t	l = get_envp_size(envp);
	size_t			i;
	char			**r;

	r = malloc((l + 1) * sizeof(char *));
	if (!r)
		return (0);
	i = -1;
	while (++i < l)
		r[i] = ft_strdup(envp[i]);
	r[i] = 0;
	if (!check_r(r, l))
		return (0);
	return (r);
}
