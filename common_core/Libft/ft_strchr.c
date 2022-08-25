/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:11:56 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/13 16:40:36 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	n;

	if (!s)
		return (NULL);
	n = 0;
	while (s[n])
	{
		if (s[n] == (char)c)
			return ((char *)s + n);
		n++;
	}
	if (s[n] == (char)c)
		return ((char *)s + n);
	return (0);
}
