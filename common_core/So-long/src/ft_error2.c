/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:29:21 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/12 18:00:53 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	ft_check(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (-1);
	return (1);
}

int	ft_casecheck(char c, t_game *game)
{
	if (c == '0' || c == 'P')
		return (1);
	else if (c == '1')
		return (2);
	else if (c == 'E' && game->map.c > 0)
		return (3);
	else if (c == 'C')
		return (4);
	else if (c == 'E' && game->map.c == 0)
		return (5);
	return (0);
}

void	ft_move(t_game *game, int dir)
{
	mlx_put_image_to_window(game->mlx, game->win, game->back.ground.img,
		game->x * 50, game->y * 50);
	game->map.map[game->y][game->x] = '0';
	if (dir == 1)
		game->y--;
	else if (dir == 2)
		game->y++;
	else if (dir == 3)
		game->x--;
	else if (dir == 4)
		game->x++;
	mlx_put_image_to_window(game->mlx, game->win, game->hero.img,
		game->x * 50, game->y * 50);
	game->mvcount++;
}

void	ft_exit(t_game *game)
{
	ft_free_tab(game->map.map, game->map.height, game->map.width);
	if (game->back.ground.img)
		mlx_destroy_image(game->mlx, game->back.ground.img);
	if (game->back.wall.img)
		mlx_destroy_image(game->mlx, game->back.wall.img);
	if (game->back.wallin.img)
		mlx_destroy_image(game->mlx, game->back.wallin.img);
	if (game->back.cont.img)
		mlx_destroy_image(game->mlx, game->back.cont.img);
	if (game->back.exit.img)
		mlx_destroy_image(game->mlx, game->back.exit.img);
	if (game->hero.img)
		mlx_destroy_image(game->mlx, game->hero.img);
	mlx_destroy_window(game->mlx, game->win);
	printf("program exited correctly\n");
	exit(0);
}

void	ft_free_tab(char **tab, int height, int width)
{
	int	n;
	int	j;

	n = 0;
	while (n < height)
	{
		j = 0;
		while (j < width)
			tab[n][j++] = '\0';
		free(tab[n]);
		n++;
	}
	free(tab);
}
