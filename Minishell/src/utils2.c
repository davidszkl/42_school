/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:09:45 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/10 15:40:37 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (!s1 || !s2)
		return (0);
	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (0);
	ft_memcpy(r, s1, ft_strlen(s1));
	ft_memcpy(r + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (r);
}

char	*ft_replace_str(const char *s, size_t start, size_t n, const char *sub)
{
	size_t	i;
	size_t	sl;
	size_t	l;
	char	*tmp;

	sl = ft_strlen(sub);
	l = ft_strlen(s) - n + sl;
	tmp = malloc(sizeof(char) * (l + 2));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < start)
		tmp[i] = s[i];
	i--;
	while (++i < start + sl)
		tmp[i] = sub[i - start];
	i--;
	while (++i < l)
		tmp[i] = s[i - sl + n];
	tmp[i] = 0;
	return (tmp);
}

char	*ft_tolower(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (str[n] >= 'A' && str[n] <= 'Z')
			str[n] += 32;
		n++;
	}
	return (str);
}

char	*ft_getword(char *str, int n)
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
	new = malloc(sizeof(char) * (n + 3));
	if (!new)
		return (NULL);
	n = t;
	j = 1;
	while (str[n] && ft_isalnumx(str, n) == 1)
		new[j++] = str[n++];
	new[j++] = '\'';
	new[j] = 0;
	new[0] = '\'';
	return (new);
}

char	*ft_itoas(int nbr)
{
	char	*new;
	int		n;
	int		j;

	if (nbr < 0)
		return (NULL);
	n = nbr;
	j = 1;
	while (n > 9 && j++ >= 0)
		n /= 10;
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (nbr > 9)
	{
		new[j - n - 1] = nbr % 10 + '0';
		nbr /= 10;
		n++;
	}
	new[j - n - 1] = nbr % 10 + '0';
	new[j] = 0;
	return (new);
}
