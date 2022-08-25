/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:23:03 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/21 13:25:01 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	while (s[n] != (char) c && n > 0)
		n--;
	if (s[n] == (char) c)
		return ((char *)s + n);
	return (0);
}
