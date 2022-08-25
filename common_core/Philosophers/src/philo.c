/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:05:11 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/25 13:05:14 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_sim	sim;
	int		n;
	int		j;

	n = 0;
	j = 0;
	if (ft_check(argc, argv, &sim) == -1)
		return (1);
	if (ft_init(argc, argv, &sim) == 1)
		return (ft_free(&sim));
	ft_monitoring(&sim, n, j);
	if (ft_exit_thread(&sim))
		return (ft_free(&sim));
	usleep(150);
	ft_free(&sim);
	return (0);
}

void	*ft_start(void *param)
{
	t_sim	*sim;
	t_philo	*philo;

	sim = param;
	philo = &sim->philo[sim->n];
	philo->limit = ft_gettime() + sim->ttd;
	philo->eatcount = 0;
	if (pthread_mutex_init(&philo->state, NULL))
		return ((void *) 1);
	while (!sim->status)
	{
		if (ft_routine(sim, philo) == 1)
		{
			sim->status = -1;
			break ;
		}
	}
	pthread_mutex_destroy(&philo->state);
	return ((void *) 0);
}

int	ft_init(int argc, char *argv[], t_sim *sim)
{
	sim->ficount = ft_atoi(argv[1]);
	sim->ttd = ft_atoi(argv[2]);
	sim->tte = ft_atoi(argv[3]);
	sim->tts = ft_atoi(argv[4]);
	sim->n = 0;
	if (argc == 6)
		sim->eatcount = ft_atoi(argv[5]);
	else
		sim->eatcount = -1;
	sim->philo = malloc(sizeof(t_philo) * sim->ficount);
	if (!sim->philo)
		return (1);
	if (pthread_mutex_init(&sim->log, NULL))
		return (ft_free(sim));
	if (ft_fork_init(sim) == 1)
		return (1);
	while (sim->n < sim->ficount)
	{
		if (ft_philo_init(sim, sim->n) == 1)
			return (1);
		sim->n++;
	}
	return (0);
}

int	ft_fork_init(t_sim *sim)
{
	int	n;

	n = 0;
	sim->fork = malloc(sizeof(pthread_mutex_t) * sim->ficount);
	if (!sim->fork)
		return (1);
	while (n < sim->ficount)
	{
		if (pthread_mutex_init(&sim->fork[n], NULL))
			return (1);
		sim->philo[n].rfork = n;
		if (n == sim->ficount - 1)
			sim->philo[n].lfork = 0;
		else
			sim->philo[n].lfork = n + 1;
		n++;
	}
	return (0);
}

int	ft_philo_init(t_sim *sim, int n)
{
	sim->philo[n].nbr = n + 1;
	sim->philo[n].status = 0;
	sim->philo[n].n = n;
	if (pthread_create(&sim->philo[sim->n].id, NULL, ft_start, sim))
		return (1);
	usleep(150);
	return (0);
}
