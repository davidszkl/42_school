/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:53:31 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/14 09:53:33 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minitalk.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_putuint(unsigned long int n)
{
	unsigned long int	nbr;
	int					j;

	nbr = n;
	j = 1;
	while (nbr > 9)
	{
		nbr /= 10 ;
		j++;
	}
	while (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	return (j);
}

int	ft_isnum(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (str[n] < '0' || str[n] > '9')
			return (-1);
		n++;
	}
	return (1);
}

int	ft_check(int argc, char *argv[])
{
	if (argc != 3)
		return (-1);
	else if (ft_isnum(argv[1]) == -1)
		return (-1);
	else if (ft_atoi(argv[1]) <= 0)
		return (-1);
	else if (!argv[2])
		return (-1);
	return (1);
}

int	ft_atoi(char *str)
{
	int	n;
	int	nbr;

	n = 0;
	nbr = 0;
	while (str[n])
		nbr = nbr * 10 + str[n++] - '0';
	return (nbr);
}
