/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:12:32 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/04 15:19:36 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static size_t	ft_nextc(char *s, char c, int index)
{
	while (1)
	{
		while (s[index] && s[index] != c)
			index++;
		if (!s[index] || !ft_isinquote_now(s, index))
			break ;
		index++;
	}
	return (index);
}

static size_t	ft_nextnotc(char *s, char c, int index)
{
	while (s[index] && s[index] == c && !ft_isinquote_now(s, index))
		index++;
	return (index);
}

static size_t	ft_getnum(char *s, char c)
{
	int		onword;
	size_t	count;
	size_t	i;

	count = 0;
	onword = 1;
	i = -1;
	if (*s != c)
		onword = 0;
	while (s[++i])
	{
		if (onword == 0 && s[i] != c)
			count++;
		if (s[i] == c && !ft_isinquote_now(s, i))
			onword = 0;
		else
			onword = 1;
	}
	return (count);
}

static int	ft_myfrees(char **r, size_t n)
{
	size_t	i;
	int		b;

	i = -1;
	b = 1;
	while (++i < n)
		b *= r[i] != 0;
	if (b)
		return (1);
	i = -1;
	while (++i < n)
		if (r[i])
			free(r[i]);
	free(r);
	return (0);
}

char	**ft_splitq(char *s, char c)
{
	char			**r;
	size_t			i;
	size_t			j;
	size_t			n;
	size_t			n2;

	if (!s)
		return (0);
	n2 = ft_getnum(s, c);
	n = n2;
	r = malloc((n + 1) * sizeof(char *));
	if (!r)
		return (0);
	r[n] = 0;
	i = 0;
	while (n--)
	{
		i = ft_nextnotc(s, c, i);
		j = ft_nextc(s, c, i);
		*r++ = ft_substr(s, i, j - i);
		i += j - i;
	}
	if (!ft_myfrees(r - n2, n2))
		return (0);
	return (r - n2);
}
