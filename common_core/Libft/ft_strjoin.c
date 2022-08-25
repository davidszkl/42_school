/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:51:41 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/15 16:20:55 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static size_t	ft_strlen(char	*s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*strjoin;
	int		n;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	strjoin = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!strjoin)
		return (0);
	n = -1;
	j = 0;
	while (str1[++n])
		strjoin[n] = str1[n];
	while (str2[j])
		strjoin[n++] = str2[j++];
	strjoin[n] = '\0';
	return (strjoin);
}
