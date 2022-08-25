/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:53:26 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/14 09:53:28 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minitalk.h"

int	main(int argc, char *argv[])
{
	if (argc > 1)
		return (-1);
	(void)argv;
	g_msg.pid = getpid();
	g_msg.ind = 8;
	g_msg.msg = 0;
	ft_printf("pid is %d\n", g_msg.pid);
	signal(30, ft_handler);
	signal(31, ft_handler);
	while (1)
	{
		if (g_msg.ind == 0)
		{
			write(1, &g_msg.msg, 1);
			g_msg.msg = 0;
			g_msg.ind = 8;
		}
		pause();
	}
	return (1);
}

void	ft_handler(int n)
{
	if (g_msg.ind > 0)
	{
		if (n % 30)
			g_msg.msg += ft_2power(g_msg.ind - 1);
		g_msg.ind--;
	}
}

int	ft_2power(int index)
{
	int	nbr;

	nbr = 1;
	while (index-- > 0)
		nbr *= 2;
	return (nbr);
}
