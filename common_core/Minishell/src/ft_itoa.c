/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:06:29 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 10:53:42 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static unsigned int	myabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	getn(int n)
{
	size_t	i;

	i = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	wr(size_t i, int n, char *r)
{
	if (n < 10 && n > -10)
		return ((void)(r[i] = '0' + myabs(n)));
	wr(i - 1, n / 10, r);
	r[i] = '0' + myabs(n % 10);
}

char	*ft_itoa(int n)
{
	const size_t	s = getn(n) + (n < 0);
	char			*r;

	r = malloc(s + 1);
	if (!r)
		return (0);
	r[s] = 0;
	if (n < 0)
		(r++)[0] = '-';
	wr(getn(n) - 1, n, r);
	return (r - (n < 0));
}
