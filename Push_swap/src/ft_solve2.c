/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:34:23 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/21 16:34:25 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_solvebig(t_main *main)
{
	int	n;
	int	j;
	int	t;

	ft_fillbig(main);
	free(main->a);
	main->a = ft_tabcpy(main->big.ind, main->alen);
	n = 0;
	t = main->alen;
	j = 0;
	while (n < main->big.maxbit)
	{
		j = t;
		while (j > 0)
		{
			if (((main->a[main->count - main->alen] >> n) & 1) == 1)
				ft_ra(main, 0);
			else
				ft_pb(main);
			j--;
		}
		while (main->blen)
			ft_pa(main);
		n++;
	}
}

void	ft_fillbig(t_main *main)
{
	int	n;
	int	j;
	int	t;

	n = 0;
	while (n < main->alen)
	{
		j = 0;
		t = 0;
		while (j < main->alen)
		{
			if (main->a[n] > main->a[j])
				t++;
			j++;
		}
		main->big.ind[n] = t;
		if (t == main->alen - 1)
			main->big.max = main->big.ind[n];
		n++;
	}
	j = 1;
	while (main->big.max >> j)
		j++;
	main->big.maxbit = j;
}

void	ft_solve4(t_main *main)
{
	ft_pb(main);
	ft_solve3(main);
	if (main->b[3] < main->a[1])
		ft_pa(main);
	else if (main->b[3] > main->a[3])
	{
		ft_pa(main);
		ft_ra(main, 0);
	}
	else if (main->b[3] > main->a[2])
	{
		ft_rra(main, 0);
		ft_pa(main);
		ft_rra(main, 0);
		ft_rra(main, 0);
	}
	else
	{
		ft_ra(main, 0);
		ft_pa(main);
		ft_rra(main, 0);
	}
}

int	ft_nbrlen(char *str)
{
	long int	nbr;
	int			n;
	int			j;

	n = 0;
	j = 1;
	nbr = ft_atoi(str);
	if (str[n] == '-')
	{
		nbr *= -1;
		j++;
	}
	else if (str[n] == '+')
		j++;
	while (nbr > 9)
	{
		j++;
		nbr /= 10;
	}
	return (j);
}
