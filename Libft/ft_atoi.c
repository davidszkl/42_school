/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 08:26:18 by dszklarz          #+#    #+#             */
/*   Updated: 2021/09/21 16:59:02 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	ft_sign(char *str)
{
	size_t	i;
	size_t	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[n] < '0' || str[n] > '9')
	{
		if (str[n] == '-' || str[n] == '+')
		{
			i++;
		}
		n++;
	}
	if (i > 1)
		return (0);
	else if (i == 0)
		return (1);
	else if (i == 1)
		if (str[n - 1] == '-')
			sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	char			*s;
	unsigned long	nbr;
	int				sign;
	int				n;

	s = (char *)str;
	nbr = 0;
	n = 0;
	sign = ft_sign(s);
	if (sign == 0)
		return (0);
	while ((s[n] >= 9 && s[n] <= 13) || str[n] == ' ')
		n++;
	while (s[n] == '-' || s[n] == '+')
		n++;
	while (s[n] >= '0' && s[n] <= '9')
	{
		nbr = nbr * 10 + s[n] - '0';
		n++;
	}
	if (nbr > 2147483647 && sign == 1)
		return (-1);
	if (nbr > 2147483648 && sign == -1)
		return (0);
	return (nbr * sign);
}
