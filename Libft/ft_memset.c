/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:49:02 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/13 17:00:02 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void	*b, int	c, size_t	len)
{
	unsigned char	*ptr;

	if (!b)
		return (NULL);
	ptr = b;
	while (len-- > 0)
		*ptr++ = c;
	return (b);
}
