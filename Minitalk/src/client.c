/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:54:54 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/14 17:14:23 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minitalk.h"

int	main(int argc, char *argv[])
{
	if (ft_check(argc, argv) == -1)
	{
		write(1, "incorrect form or message\ncorrect form is : pid, message\n",
			57);
		return (-1);
	}
	else if (ft_atoi(argv[1]) < 0)
	{
		write(1, "pid non-existent\n", 17);
		return (-1);
	}
	ft_signal(argv[1], argv[2]);
	return (1);
}

void	ft_signal(char *pidd, char *str)
{
	int		*msg;
	int		n;
	int		pid;

	pid = ft_atoi(pidd);
	n = 0;
	while (str[n])
	{
		msg = ft_itob(str[n++]);
		if (ft_send(msg, pid) == -1)
		{
			write(1, "signal problem\nexiting ...", 26);
			free(msg);
			exit(0);
		}
		free(msg);
	}
}

int	*ft_itob(int c)
{
	int	*bin;
	int	n;

	n = 0;
	if (c < 0)
		c = 255 - c;
	bin = malloc(sizeof(int) * 8);
	if (!bin)
		return (NULL);
	while (n < 8)
	{
		bin[7 - n++] = c % 2;
		c /= 2;
	}
	return (bin);
}

int	ft_send(int	*msg, int pid)
{
	int	n;

	n = 0;
	while (n < 8)
	{
		if (msg[n] == 0)
		{
			if (kill(pid, 30) > 0)
				return (-1);
		}
		else if (msg[n] == 1)
		{			
			if (kill(pid, 31) > 0)
				return (-1);
		}
		n++;
		usleep(100);
	}
	return (1);
}
