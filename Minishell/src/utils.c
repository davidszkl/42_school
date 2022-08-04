/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:51:41 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/23 11:39:18 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	ft_strcpy(char *dst, char *src)
{
	int	n;

	n = 0;
	while (src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
}

char	*ft_strdup(const char *s1)
{
	const size_t	l = ft_strlen(s1);
	char			*s;

	s = malloc(l + 1);
	if (!s)
		return (0);
	while (*s1)
		*s++ = *s1++;
	*s = 0;
	return (s - l);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	r = malloc(len + 1);
	if (!r)
		return (0);
	i = -1;
	while (++i < len)
		r[i] = s[start + i];
	r[i] = 0;
	return (r);
}
