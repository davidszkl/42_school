/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:31:14 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/19 10:31:16 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_ra(t_main *main, int mod)
{
	int	n;
	int	t;

	n = main->count - main->alen;
	if (main->alen < 2)
		return ;
	if (main->count - main->alen == main->zpos && main->zstk == 1)
		main->zpos = main->count - 1;
	t = main->a[main->count - main->alen];
	while (n < main->count - 1)
	{
		if (n + 1 == main->zpos && main->zstk == 1)
			main->zpos = n;
		main->a[n] = main->a[n + 1];
		n++;
	}
	main->a[n] = t;
	if (mod == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_main *main, int mod)
{
	int	n;
	int	t;

	n = main->count - main->blen;
	if (main->blen < 2)
		return ;
	if (main->count - main->blen == main->zpos && main->zstk == 2)
		main->zpos = main->count - 1;
	t = main->b[main->count - main->blen];
	while (n < main->count - 1)
	{
		if (n + 1 == main->zpos && main->zstk == 2)
			main->zpos = n;
		main->b[n] = main->b[n + 1];
		n++;
	}
	main->b[n] = t;
	if (mod == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_main *main)
{
	ft_ra(main, 1);
	ft_rb(main, 1);
	write(1, "rr\n", 3);
}

void	ft_rra(t_main *main, int mod)
{
	int	n;
	int	t;

	n = main->count - 1 - 1;
	if (main->alen < 2)
		return ;
	if (main->count - 1 == main->zpos && main->zstk == 1)
		main->zpos = main->count - main->alen;
	t = main->a[main->count - 1];
	while (n >= main->count - main->alen)
	{
		if (n == main->zpos && main->zstk == 1)
			main->zpos = n + 1;
		main->a[n + 1] = main->a[n];
		n--;
	}
	main->a[main->count - main->alen] = t;
	if (mod == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_main *main, int mod)
{	
	int	n;
	int	t;

	n = main->count - 1 - 1;
	if (main->blen < 2)
		return ;
	if (main->count - 1 == main->zpos && main->zstk == 2)
		main->zpos = main->count - main->blen;
	t = main->b[main->count - 1];
	while (n >= main->count - main->blen)
	{
		if (n == main->zpos && main->zstk == 2)
			main->zpos = n + 1;
		main->b[n + 1] = main->b[n];
		n--;
	}
	main->b[main->count - main->blen] = t;
	if (mod == 0)
		write(1, "rrb\n", 4);
}
