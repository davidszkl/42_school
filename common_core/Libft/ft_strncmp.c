/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:26:33 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/15 12:00:20 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (n);
	while (*str1 && *str2 && *str1 == *str2 && n > 1)
	{
		str1++;
		str2++;
		n--;
	}
	return (*str1 - *str2);
}
