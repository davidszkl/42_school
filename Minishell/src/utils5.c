/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:38:38 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/11 14:38:44 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	ft_isinquote_now(char *str, int index)
{
	int		b;
	int		i;

	b = 0;
	i = -1;
	while (++i <= index && str[i])
	{
		if (b != '"' && str[i] == '\'')
			while (str[++i] && str[i] != '\'' && i <= index)
				b = '\'';
		if (i > index)
			return (b != 0);
		b = 0;
		if (b != '\'' && str[i] == '"')
			while (str[++i] && str[i] != '"' && i <= index)
				b = '"';
		if (i > index)
			return (b != 0);
	}
	return (b != str[i - 1] && (b == '\'' || b == '"'));
}

int	ft_isquote(char c)
{
	if (c == 34)
		return (1);
	else if (c == 39)
		return (2);
	return (0);
}

int	ft_myfree(char *str)
{
	free(str);
	return (1);
}

char	*ft_getword_simple(char *str, int n)
{
	char	*new;
	int		j;
	int		t;

	j = 0;
	while (str[n] && ft_isspace(str[n]) == 1)
	{
		j++;
		n++;
	}
	t = n;
	while (str[n] && ft_isalnumx(str, n) == 1)
		n++;
	new = malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	n = t;
	j = 0;
	while (str[n] && ft_isalnumx(str, n) == 1)
		new[j++] = str[n++];
	new[j] = 0;
	return (new);
}

int	ft_open_quote(char *str)
{
	int	b;

	b = 0;
	str--;
	while (*++str)
	{
		if (b == '\'' && *str != '\'')
			continue ;
		if (b == '"' && *str != '"')
			continue ;
		if (b == '\'' && *str == '\'')
		{
			b = 0;
			continue ;
		}
		if (b == '"' && *str == '"')
		{
			b = 0;
			continue ;
		}
		if (!b && (*str == '\'' || *str == '"'))
			b = *str;
	}
	return (b == '\'' || b == '"');
}
