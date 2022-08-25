/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:35:52 by mlefevre          #+#    #+#             */
/*   Updated: 2022/03/25 22:25:04 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string>

static size_t ft_strlen(const char * s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return i;
}

static char	*ft_strdup(const char *s1)
{
	const size_t	l = ft_strlen(s1);
	char			*s;

	s = (char *)malloc(l + 1);
	if (!s)
		return (0);
	while (*s1)
		*s++ = *s1++;
	*s = 0;
	return (s - l);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	r = (char *)malloc(len + 1);
	if (!r)
		return (0);
	i = -1;
	while (++i < len)
		r[i] = s[start + i];
	r[i] = 0;
	return (r);
}

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
	r = (char**)malloc((n + 1) * sizeof(char *));
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

static size_t tab_len(char **tab)
{
	size_t i = 0;
	while (tab[i])
		i++;
	return i;
}

void fix_content_in_split(char**& split)
{
	using std::string;
	size_t l = tab_len(split);
	for (int i = 0; split[i] && split[i + 1]; i++)
	{
		if (string(split[i]).substr(0, string("CONTENT_TYPE=").length()) != "CONTENT_TYPE=")
			continue;
		l--;
		string s = string(split[i]) + " " + string(split[i + 1]);
		free(split[i]);
		free(split[i + 1]);
		split[i] = ft_strdup(s.c_str());
		int j;
		for (j = i + 1; split[j+1]; j++)
			std::swap(split[j], split[j + 1]);
		std::swap(split[j], split[j + 1]);
	}
	if (!myfrees(split, l))
	{
		perror("fix_content_in_split()");
		exit(1);
	}
}
