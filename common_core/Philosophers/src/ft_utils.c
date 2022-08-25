/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:05:05 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/25 13:05:07 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	ft_isnum(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (n == 0 && (str[n] == '-' || str[n] == '+'))
			n++;
		if (str[n] < '0' || str[n] > '9')
			return (-1);
		n++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int			n;
	long int	nbr;
	int			sign;
	int			j;

	n = 0;
	nbr = 0;
	sign = 1;
	j = 0;
	if (str[n] == '-')
	{
		sign = -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	if (ft_isnum(str) == -1)
		return (0);
	while (str[n])
		nbr = nbr * 10 + str[n++] - '0';
	if ((nbr > INT_MAX && sign == 1) || (nbr * sign < INT_MIN))
		return (0);
	return (nbr * sign);
}

uint64_t	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (uint64_t)1000 + (time.tv_usec / 1000));
}

void	ft_putnbr(uint64_t n)
{
	unsigned int	nbr;

	nbr = (unsigned int) n;
	while (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr %= 10;
	}
	nbr += '0';
	write(1, &nbr, 1);
}
