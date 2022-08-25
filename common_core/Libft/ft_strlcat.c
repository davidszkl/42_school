/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:18:48 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/13 17:18:00 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	if (!dst || !src)
		return (0);
	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len > dstsize)
		return (src_len + dstsize);
	return (src_len + dst_len);
}
