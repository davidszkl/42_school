/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:04:02 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 14:04:03 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isprint(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_is_empty(char *line)
{
	int	n;

	n = 0;
	while (line[n] && ft_isspace(line[n]))
		n++;
	if (!line[n])
		return (1);
	return (0);
}

char	*ft_getword_simple(char *str, int n)
{
	char	*new;
	int		t;

	while (str[n] && (str[n] == ' ' || str[n] == 9))
		n++;
	t = n;
	while (str[n] && ft_isprint(str[n]) && str[n] != ' ')
		n++;
	new = malloc(sizeof(char) * (n - t + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (str[t] && ft_isprint(str[t]) && str[t] != ' ')
		new[n++] = str[t++];
	new[n] = 0;
	return (new);
}
