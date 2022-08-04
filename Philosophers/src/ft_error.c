/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:05:00 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/25 13:05:01 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	ft_check(int argc, char *argv[], t_sim *sim)
{
	int	n;

	n = 2;
	if (argc < 5 || argc > 6)
	{
		write(1, "Arg error\n", 10);
		return (-1);
	}
	while (n < argc - 1)
	{
		if (ft_atoi(argv[n]) < 60 || ft_atoi(argv[1]) < 1 || (argc == 6
				&& ft_atoi(argv[5]) < 0))
		{
			write(1, "Arg error\n", 10);
			return (-1);
		}
		n++;
	}
	if (argc == 7 && ft_atoi(argv[6]) == 0)
		return (-1);
	sim->start = ft_gettime();
	sim->status = 0;
	sim->argc = argc;
	return (1);
}

int	ft_free(t_sim *sim)
{
	int	n;

	n = 0;
	while (n < sim->ficount)
		if (&sim->fork[n])
			if (pthread_mutex_destroy(&sim->fork[n++]))
				return (1);
	if (pthread_mutex_destroy(&sim->log))
		return (1);
	free(sim->philo);
	free(sim->fork);
	return (1);
}

int	ft_error(int nbr)
{
	if (nbr == 1)
		write(1, "thread error\n", 13);
	return (nbr);
}

int	ft_checkeat(t_sim *sim, int nbr)
{
	if (sim->eatcount == -1)
		return (0);
	if (sim->philo[nbr].eatcount >= sim->eatcount)
		return (1);
	return (0);
}

int	ft_exit_thread(t_sim *sim)
{
	int	n;

	n = 0;
	while (n < sim->ficount)
		if (pthread_detach(sim->philo[n++].id))
			return (1);
	return (0);
}
