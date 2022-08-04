/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:12:40 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/17 13:12:56 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	ft_isnum(char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (str[n] != '-' && str[n] != ' ' && str[n] != '+'
			&& (str[n] < '0' || str[n] > '9'))
			return (-1);
		n++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
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
	while (str[n] && (str[n] >= '0' && str[n] <= '9'))
		nbr = nbr * 10 + str[n++] - '0';
	if ((nbr > INT_MAX && sign == 1) || (nbr * sign < INT_MIN))
		return (0);
	return (nbr * sign);
}

int	*ft_tabcpy(int *tab, int size)
{
	int	*new;
	int	n;

	new = (int *)malloc(sizeof(int) * size);
	n = -1;
	if (!new)
		return (NULL);
	while (++n < size)
		new[n] = tab[n];
	return (new);
}

void	ft_rrr(t_main *main)
{
	ft_rra(main, 1);
	ft_rrb(main, 1);
	write(1, "rrr\n", 4);
}
