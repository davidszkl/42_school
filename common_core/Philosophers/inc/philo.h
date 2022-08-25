/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:18:34 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/25 14:42:22 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

/*includes*/

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

/*structures*/

typedef struct s_philo {
	pthread_mutex_t	state;
	pthread_t		id;
	uint64_t		limit;
	uint64_t		last_eat;
	int				eatcount;
	int				status;
	int				rfork;
	int				lfork;
	int				nbr;
	int				n;
}	t_philo;

typedef struct s_sim {
	pthread_mutex_t	*fork;
	pthread_mutex_t	log;
	pthread_t		thread;
	pthread_t		m_thread;
	pthread_t		mc_thread;
	t_philo			*philo;
	uint64_t		start;
	uint64_t		ttd;
	uint64_t		tte;
	uint64_t		tts;
	int				eatcount;
	int				ficount;
	int				status;
	int				n;
	int				argc;
}	t_sim;

/*functions*/

void		*ft_start(void *smths);
void		ft_msg(t_sim *sim, int nbr, int msg);
int			ft_init(int argc, char *argv[], t_sim *sim);
int			ft_philo_init(t_sim *sim, int n);
int			ft_exit_thread(t_sim *sim);
int			ft_fork_init(t_sim *sim);

/*actions*/

int			ft_routine(t_sim *sim, t_philo *philo);
int			ft_routine2(t_sim *sim, t_philo *philo);

/*utils*/

uint64_t	ft_gettime(void);
void		ft_putnbr(uint64_t n);
int			ft_isnum(char *str);
int			ft_atoi(char *str);

/*error*/

void		*ft_monitor_count(void *param);
void		*ft_monitor(void *param);
void		ft_monitoring(t_sim *sim, int n, int j);
int			ft_check(int argc, char *argv[], t_sim *sim);
int			ft_checkeat(t_sim *sim, int nbr);
int			ft_free(t_sim *sim);
int			ft_error(int nbr);

#endif
