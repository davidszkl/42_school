/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:29:57 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/09 12:29:59 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "cub3d.h"

static int	ft_atoi_loop2(t_main *main)
{
	size_t	count;
	int		n;
	int		j;

	count = 0;
	n = 0;
	j = 0;
	while (main->temp[n] && count < 3)
	{
		j = ft_atoi_mod(&main->temp[n], &main->ceilling.rgb1[count++]);
		if (j < 0)
			return (-1);
		n += j;
	}
	return (0);
}

int	ft_atoi_loop(t_main *main, int nbr)
{
	size_t	count;
	int		n;
	int		j;

	count = 0;
	n = 0;
	j = 0;
	if (nbr == 1)
	{
		while (main->temp[n] && count < 3)
		{
			j = ft_atoi_mod(&main->temp[n], &main->floor.rgb1[count++]);
			if (j < 0)
				return (-1);
			n += j;
		}
	}
	else if (nbr == 2)
		return (ft_atoi_loop2(main));
	return (0);
}
