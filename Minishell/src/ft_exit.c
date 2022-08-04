/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:08 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/18 09:27:45 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>
#include <limits.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

static int	not_overflow(const char *str)
{
	int	n;
	int	s;

	n = 0;
	s = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			s = -1;
	str--;
	while (*++str)
	{
		if ((s == -1 && (INT_MIN + (*str - '0')) / 10 > n)
			|| (s == 1 && (INT_MAX - (*str - '0')) / 10 < n))
			return (0);
		n = n * 10 + (*str - '0') * s;
	}
	return (1);
}

static int	exit_valid_arg(const char *s)
{
	const char	*s2;

	s2 = s;
	if (*s == '-' || *s == '+')
		s++;
	s--;
	while (*++s)
		if (!ft_isdigit(*s) && not_overflow(s2))
			return (0);
	return (not_overflow(s2));
}

/*returns exit status. -1 if invalid argument count.*/
int	ft_exit(char **argv)
{
	if (!argv[1])
		return (0);
	while (*(argv[1]) == ' ')
		argv[1]++;
	if (!exit_valid_arg(argv[1]))
	{
		ft_putstr_fd(ERROR, 2);
		ft_putstr_fd(": exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	if (argv[2])
	{
		ft_putstr_fd(ERROR, 2);
		ft_putstr_fd(": exit: too many arguments\n", 2);
		return (-1);
	}
	return ((unsigned char)ft_atoi(argv[1]));
}
