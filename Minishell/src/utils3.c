/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:39:00 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/08 14:39:02 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_isalnumx(char *str, int n)
{
	if (!str[n])
		return (0);
	if ((str[n] == '|' || str[n] == '<' || str[n] == '>' || str[n] == 0)
		&& !ft_isinquote_now(str, n))
		return (0);
	else if ((str[n] >= 0 && str[n] <= 32) || str[n] == 127)
		return (0);
	return (1);
}

int	ft_spwordcount(char *str, int n)
{
	int	count;

	count = 0;
	while (ft_isspace(str[n]) == 1)
	{
		n++;
		count++;
	}
	while (ft_isalnumx(str, n) == 1)
	{
		n++;
		count++;
	}
	return (count);
}
