/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:52:20 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/10 10:55:42 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (0);
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

char	*ft_strjoin(char *s1, char *s2)
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

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char		*d2;
	const unsigned char	*s2;

	s2 = src;
	d2 = dst;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d2++ = *s2++;
	return (dst);
}
