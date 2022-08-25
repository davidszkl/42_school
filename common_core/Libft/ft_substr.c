/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:38:47 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/15 16:18:11 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*str;
	char			*substr;
	int				n;

	n = 0;
	j = start;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!len || !s)
		return (ft_strdup(""));
	str = (char *)s;
	if (start > ft_strlen(str))
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (str[j++] && len-- > 0 )
		substr[n++] = str[start++];
	substr[n] = '\0';
	return (substr);
}
