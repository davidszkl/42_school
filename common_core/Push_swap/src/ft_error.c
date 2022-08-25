/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:07:20 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/17 13:07:23 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	ft_checkarg(int argc, char *argv[])
{
	int	n;

	n = 1;
	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		if (ft_isnum(argv[1]) == -1)
			return (-1);
		return (1);
	}
	while (n < argc)
	{
		if (ft_isnum(argv[n]) == -1
			|| (ft_atoi(argv[n]) == 0 && argv[n][0] != '0'))
			return (-1);
		n++;
	}
	return (1);
}

int	ft_dup(t_main *main)
{
	int	n;
	int	j;

	n = 0;
	while (n < main->count)
	{
		j = n + 1;
		while (j < main->count)
			if (main->a[j++] == main->a[n])
				return (-1);
		n++;
	}
	return (1);
}

void	ft_exit(t_main *main, int error)
{
	if (error == 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	free(main->big.ind);
	free(main->a);
	free(main->b);
	free(main->sorted);
	if (error == 2)
		exit(0);
	exit(1);
}
