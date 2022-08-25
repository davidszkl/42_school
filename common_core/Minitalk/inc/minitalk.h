/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:14:35 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/14 17:14:40 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

/*includes*/

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

/*structures*/

typedef struct s_msg {
	pid_t	pid;
	int		msg;
	int		ind;
}	t_msg;

/*global*/

t_msg	g_msg;

/*functions*/

int		ft_check(int argc, char *argv[]);
int		ft_isnum(char *str);
void	ft_signal(char *pidd, char *str);
int		*ft_itob(int c);
int		ft_atoi(char *str);
int		ft_send(int *msg, int pid);
void	ft_handler(int n);
int		ft_2power(int index);

#endif
