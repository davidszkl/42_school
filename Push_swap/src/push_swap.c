/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:07:06 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/27 14:04:57 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_main	main;

	if (ft_checkarg(argc, argv) == -1)
		ft_exit(&main, 0);
	if (ft_init(&main, argc, argv) == -1)
		ft_exit(&main, 0);
	main.big.ind = (int *)malloc(sizeof(int) * main.count);
	if (!main.big.ind)
		ft_exit(&main, 1);
	ft_solve(&main);
	ft_exit(&main, 2);
	return (0);
}

int	ft_init(t_main *main, int argc, char *argv[])
{
	if (argc != 2)
		main->count = argc - 1;
	main->a = (int *)malloc(sizeof(int) * main->count);
	main->b = (int *)malloc(sizeof(int) * main->count);
	if (!main->a || !main->b)
		ft_exit(main, 1);
	main->blen = 0;
	main->zpos = -1;
	main->zstk = -1;
	if (ft_parse(main, argc, argv) == -1)
		return (-1);
	if (ft_dup(main) == -1)
		return (-1);
	main->alen = main->count;
	main->sorted = ft_sort(main->a, main->count);
	return (1);
}

int	*ft_sort(int *lst, int len)
{
	int	n;
	int	j;
	int	t;
	int	*new;

	new = ft_tabcpy(lst, len);
	n = 0;
	while (n < len)
	{
		j = n + 1;
		while (j < len)
		{
			if (new[n] > new[j])
			{
				t = new[n];
				new[n] = new[j];
				new[j] = t;
			}
			j++;
		}
		n++;
	}
	return (new);
}

int	ft_parse(t_main *main, int argc, char *argv[])
{
	int	n;

	n = 1;
	if (argc == 2)
	{
		if (ft_parse2(main, argv[1]) == -1)
			return (-1);
	}
	else
	{
		while (n < argc)
		{
			main->a[n - 1] = ft_atoi(argv[n]);
			if (main->a[n - 1] == 0)
			{
				main->zstk = 1;
				main->zpos = n - 1;
			}
			main->b[n - 1] = 0;
			n++;
		}
	}
	return (1);
}

int	ft_parse2(t_main *main, char *argv)
{
	int	n;
	int	j;
	int	index;

	n = 0;
	index = 0;
	while (argv[index] && index < ft_strlen(argv))
	{
		j = 0;
		while (argv[index] == ' ' && j++ >= 0)
			index++;
		if (j == 0 && index > 0)
			return (-1);
		j = 1;
		main->a[n++] = ft_atoi(&argv[index]);
		index += ft_nbrlen(&argv[index]);
	}
	main->count = n;
	return (1);
}
