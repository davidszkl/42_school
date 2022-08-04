/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:47:37 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/12 18:00:48 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		printf("Error\nArgument error\n");
		exit(0);
	}
	if (n == -1)
	{
		printf("Error\nWrong file format, correct one is .ber\n");
		exit(0);
	}
	if (n == -2)
	{
		printf("Error\nRead error: wrong file name or permissions\n");
		exit(0);
	}
	else if (n == -3)
	{
		printf("Error\nMalloc error\n");
		exit(0);
	}
}

void	ft_map_error(t_map *map, int n)
{
	if (n == 0)
	{
		printf("Error\nMap error\n");
		ft_free_tab(map->map, map->height, map->width);
		exit(0);
	}
	if (n == -1)
	{
		printf("Error\nMap parsed correctly but is too big to display\n");
		ft_free_tab(map->map, map->height, map->width);
		exit(0);
	}
}

void	ft_mlx_error(t_game *game, int n)
{
	if (n == 0)
	{
		printf("Error\nMlx error\n");
		ft_exit(game);
	}
	else if (n == -1)
	{
		printf("Error\nMlx image error\n");
		ft_exit(game);
	}
	else if (n == -2)
	{
		printf("Error\nTexture size not 50x50 pixels\n");
		ft_exit(game);
	}
}

void	ft_checkmap(t_map *map)
{
	int	n;
	int	j;

	n = -1;
	while (++n < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strnlen(map->map[n]) != map->width
				|| (n == 0 && map->map[n][j] != '1'))
				ft_map_error(map, 0);
			else if (ft_check(map->map[n][j]) == -1 || ((j == 0
				|| j == map->width - 1) && map->map[n][j] != '1'))
				ft_map_error(map, 0);
			else if ((n == 0 || n == map->height - 1) && map->map[n][j] != '1')
				ft_map_error(map, 0);
			else if (map->map[n][j] == 'C' || map->map[n][j] == 'E'
						|| map->map[n][j] == 'P')
				ft_increment(map, map->map[n][j]);
			j++;
		}
	}
	if (map->c < 1 || map->e < 1 || map->p < 1)
		ft_map_error(map, 0);
}

void	ft_increment(t_map *map, char c)
{
	if (c == 'C')
		map->c++;
	else if (c == 'P')
		map->p++;
	else if (c == 'E')
		map->e++;
}
