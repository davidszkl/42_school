/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:16:15 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/04 15:16:17 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_tablen(char **tab)
{
	int	n;

	n = 0;
	while (tab[n])
		n++;
	return (n);
}

int	ft_atoi_mod(char *str, int *modify)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (str[j] == ' ' || str[j] == ',' || str[j] == 9)
		j++;
	if (!ft_isdigit(str[j]))
		return (-1);
	while (ft_isdigit(str[j]))
	{
		if (n < 0 || n > 255)
			return (-1);
		n = n * 10 + (str[j++] - '0');
	}
	if (n < 0 || n > 255)
		return (-1);
	*modify = n;
	return (j);
}

void	my_perror(char *tmp)
{
	if (!tmp[0])
		perror("<no file>");
	else
		perror(tmp);
}
