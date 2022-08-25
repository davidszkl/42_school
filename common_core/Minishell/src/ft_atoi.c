/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:55:38 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 11:55:50 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:57:30 by mlefevre          #+#    #+#             */
/*   Updated: 2021/10/25 17:54:41 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	myisspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

static int	check_n(unsigned long long n, char s, char c)
{
	if (s == 1 && (9223372036854775807ULL - (c - '0')) / 10 < n)
		return (-1);
	if (s == -1 && (9223372036854775808ULL - (c - '0')) / 10 < n)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long	n;
	char				s;

	n = 0;
	while (myisspace(*str))
		str++;
	s = -(*str == '-') * 2 + 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (check_n(n, s, *str) == 0 || check_n(n, s, *str) == -1)
			return (check_n(n, s, *str));
		n = n * 10 + (*str++ - '0');
	}
	return (n * s);
}
