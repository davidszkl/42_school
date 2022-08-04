/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:35:52 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/01 14:05:03 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	nextc(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	nextnotc(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static size_t	getnum(char const *s, char c)
{
	int		onword;
	size_t	count;

	count = 0;
	onword = 1;
	if (*s != c)
		onword = 0;
	s--;
	while (*++s)
	{
		if (onword == 0 && *s != c)
			count++;
		if (*s == c)
			onword = 0;
		else
			onword = 1;
	}
	return (count);
}

static int	myfrees(char **r, size_t n)
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

char	**ft_split(char const *s, char c)
{
	char			**r;
	size_t			i;
	size_t			j;
	size_t			n;
	size_t			n2;

	if (!s)
		return (0);
	n2 = getnum(s, c);
	n = n2;
	r = malloc((n + 1) * sizeof(char *));
	if (!r)
		return (0);
	r[n] = 0;
	while (n--)
	{
		i = nextnotc(s, c);
		j = nextc(s + i, c);
		*r++ = ft_substr(s, i, j);
		s = s + j + i;
	}
	if (!myfrees(r - n2, n2))
		return (0);
	return (r - n2);
}
