/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:50:47 by mlefevre          #+#    #+#             */
/*   Updated: 2021/10/08 11:12:33 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static size_t	getnl(char *buf, size_t filled)
{
	size_t	i;

	i = 0;
	while (i < filled && buf[i] != '\n')
		i++;
	return (i);
}

static int	getnewr(char **r, char *buf, size_t *filled)
{
	char			*r2;
	const size_t	nl = getnl(buf, *filled);
	char *const		sub = ft_substr(buf, 0, nl + (nl != *filled));

	if (!sub)
	{
		free(*r);
		return (0);
	}
	r2 = ft_strjoin(((char *[2]){"", *r})[*r != 0], sub);
	free(sub);
	free(*r);
	*r = r2;
	if (nl == *filled)
		*filled = 0;
	else
	{
		ft_memcpy(buf, buf + nl + 1, *filled - 1 - nl);
		*filled = *filled - 1 - nl;
	}
	return (*r != 0);
}

static int	checkbuf(void)
{
	return (BUFFER_SIZE > 0 && BUFFER_SIZE <= (size_t)-1);
}

char	*get_next_line(int fd)
{
	static t_locs	lcs;
	t_loc			lc;

	if (fd < 0 || !checkbuf())
		return (0);
	lc.r = 0;
	while (1)
	{
		lc.n = read(fd, lcs.buf + lcs.filled, BUFFER_SIZE - lcs.filled);
		lcs.filled += lc.n;
		if (!lc.n && lcs.filled == 0)
		{
			lcs.filled = 0;
			return (lc.r);
		}
		if (lc.n == -1 || !getnewr(&lc.r, lcs.buf, &lcs.filled))
		{
			if (lc.n == -1)
				free(lc.r);
			lcs.filled = 0;
			return (0);
		}
		if (lc.r[ft_strlen(lc.r) - 1] == '\n')
			return (lc.r);
	}
}
