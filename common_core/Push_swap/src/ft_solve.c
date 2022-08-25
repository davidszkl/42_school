/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:24:37 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/19 11:24:39 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_solve(t_main *main)
{
	if (ft_is_solved(main) == 1)
		return ;
	if (main->alen == 2)
		ft_solve2(main);
	else if (main->alen == 3)
		ft_solve3(main);
	else if (main->alen == 4)
		ft_solve4(main);
	else if (main->alen == 5)
		ft_solve5(main);
	else if (main->alen > 5)
		ft_solvebig(main);
}

void	ft_solve2(t_main *main)
{
	if (main->a[0] > main->a[1])
		ft_ra(main, 0);
}

void	ft_solve3(t_main *main)
{
	t_3	s;

	s.a = main->a[main->count - main->alen];
	s.b = main->a[main->count - main->alen + 1];
	s.c = main->a[main->count - main->alen + 2];
	if (s.a < s.b && s.b < s.c)
		return ;
	if (s.a > s.b && s.b < s.c && s.c > s.a)
		ft_sa(main, 0);
	else if (s.a > s.b && s.b > s.c && s.c < s.a)
	{
		ft_sa(main, 0);
		ft_rra(main, 0);
	}
	else if (s.a > s.b && s.b < s.c && s.c < s.a)
		ft_ra(main, 0);
	else if (s.a < s.b && s.b > s.c && s.c > s.a)
	{
		ft_sa(main, 0);
		ft_ra(main, 0);
	}
	else if (s.a < s.b && s.a > s.c && s.c < s.a)
		ft_rra(main, 0);
}

void	ft_solve5(t_main *main)
{	
	int	n;
	int	t;
	int	j;

	n = 1;
	t = 0;
	j = 2;
	while (j-- > 0)
	{
		n = 2 - j;
		t = 1 - j;
		while (n < 5)
			if (main->a[n++] < main->a[t])
				t = n - 1;
		if (t <= 2)
			while (t-- > 1 - j)
				ft_ra(main, 0);
		else
			while (t++ < 5)
				ft_rra(main, 0);
		ft_pb(main);
	}
	ft_solve3(main);
	ft_pa(main);
	ft_pa(main);
}

int	ft_is_solved(t_main *main)
{
	int	n;

	n = 0;
	while (n < main->count)
	{
		if (main->a[n] != main->sorted[n])
			return (-1);
		n++;
	}
	return (1);
}
