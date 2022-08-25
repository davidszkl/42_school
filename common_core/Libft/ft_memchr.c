/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:35:47 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/13 16:33:56 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t	n)
{
	unsigned char	a;
	unsigned char	*str;

	if (!s)
		return (NULL);
	a = c;
	str = (unsigned char *)s;
	while (n-- > 0)
		if (*str++ == a)
			return (str - 1);
	return (0);
}
