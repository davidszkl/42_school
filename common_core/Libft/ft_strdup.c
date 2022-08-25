/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:32:20 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/13 16:41:25 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		str_len;
	int		i;
	char	*buffer;

	if (!s1)
		return (NULL);
	str_len = 0;
	i = 0;
	if (s1)
		while (s1[str_len])
			str_len++;
	else
		str_len = 0;
	buffer = (char *)malloc(sizeof(*buffer) * (str_len + 1));
	if (!buffer)
		return (0);
	while (i < str_len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
