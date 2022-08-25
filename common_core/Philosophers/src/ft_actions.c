/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:21:46 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/29 09:21:47 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/philo.h"

int	ft_routine(t_sim *sim, t_philo *philo)
{
	if (pthread_mutex_lock(&sim->fork[philo->rfork]))
		return (1);
	ft_msg(sim, philo->nbr, 1);
	if (pthread_mutex_lock(&sim->fork[philo->lfork]))
		return (1);
	ft_msg(sim, philo->nbr, 1);
	ft_msg(sim, philo->nbr, 2);
	philo->limit = ft_gettime() + sim->ttd + 3;
	if (pthread_mutex_lock(&philo->state))
		return (1);
	usleep(sim->tte * 1000);
	if (sim->status)
		return (1);
	philo->eatcount++;
	return (ft_routine2(sim, philo));
}

int	ft_routine2(t_sim *sim, t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->state))
		return (1);
	if (pthread_mutex_unlock(&sim->fork[philo->lfork]))
		return (1);
	if (pthread_mutex_unlock(&sim->fork[philo->rfork]))
		return (1);
	ft_msg(sim, philo->nbr, 3);
	usleep(sim->tts * 1000);
	if (sim->status)
		return (1);
	ft_msg(sim, philo->nbr, 4);
	return (0);
}

void	ft_monitoring(t_sim *sim, int n, int j)
{
	while (!sim->status)
	{
		n = 0;
		j = 0;
		while (!sim->status && n < sim->ficount)
		{
			if (ft_gettime() >= sim->philo[n].limit)
			{
				ft_msg(sim, n + 1, -1);
				sim->status = -1;
				pthread_mutex_lock(&sim->philo[n].state);
				return ;
			}
			if (ft_checkeat(sim, n))
				j++;
			n++;
		}
		if (j == sim->ficount)
		{
			ft_msg(sim, n, 5);
			sim->status = -1;
			pthread_mutex_lock(&sim->philo[n].state);
			return ;
		}
	}
}

void	ft_msg(t_sim *sim, int nbr, int msg)
{
	if (!sim || sim->status || msg == 5)
		return ;
	pthread_mutex_lock(&sim->log);
	if (sim->status)
		return ;
	ft_putnbr(ft_gettime() - sim->start);
	write (1, " ", 1);
	ft_putnbr(nbr);
	if (msg == -1)
		write(1, " died\n", 6);
	else if (msg == 1)
		write(1, " has taken a fork\n", 19);
	else if (msg == 2)
		write(1, " is eating\n", 12);
	else if (msg == 3)
		write(1, " is sleeping\n", 14);
	else if (msg == 4)
		write(1, " is thinking\n", 14);
	if (!sim->status)
		pthread_mutex_unlock(&sim->log);
}
