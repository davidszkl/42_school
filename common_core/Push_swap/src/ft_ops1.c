/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:10:41 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/18 13:10:45 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

void	ft_sa(t_main *main, int mod)
{
	int	temp;

	if (main->alen < 2)
		return ;
	if (main->count - main->alen == main->zpos && main->zstk == 1)
		main->zpos = main->count - main->alen + 1;
	else if (main->count - main->alen + 1 == main->zpos && main->zstk == 1)
		main->zpos = main->a[main->count - main->alen];
	temp = main->a[main->count - main->alen];
	main->a[main->count - main->alen] = main->a[main->count - main->alen + 1];
	main->a[main->count - main->alen + 1] = temp;
	if (mod == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_main *main, int mod)
{
	int	temp;

	if (main->blen < 2)
		return ;
	if (main->count - main->blen == main->zpos && main->zstk == 2)
		main->zpos = main->count - main->blen + 1;
	else if (main->count - main->blen + 1 == main->zpos && main->zstk == 2)
		main->zpos = main->b[main->count - main->blen];
	temp = main->b[main->count - main->blen];
	main->b[main->count - main->blen] = main->b[main->count - main->blen + 1];
	main->b[main->count - main->blen + 1] = temp;
	if (mod == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_main *main)
{
	ft_sa(main, 1);
	ft_sb(main, 1);
	write(1, "ss\n", 3);
}

void	ft_pa(t_main *main)
{
	if (main->blen < 1)
		return ;
	if (main->count - main->blen == main->zpos && main->zstk == 2)
	{
		main->zstk = 1;
		main->zpos = main->count - main->alen - 1;
	}
	main->a[main->count - main->alen - 1] = main->b[main->count - main->blen];
	main->b[main->count - main->blen] = 0;
	main->blen--;
	main->alen++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_main *main)
{
	if (main->alen < 1)
		return ;
	if (main->count - main->alen == main->zpos && main->zstk == 1)
	{
		main->zstk = 2;
		main->zpos = main->count - main->blen - 1;
	}
	main->b[main->count - main->blen - 1] = main->a[main->count - main->alen];
	main->a[main->count - main->alen] = 0;
	main->alen--;
	main->blen++;
	write(1, "pb\n", 3);
}
