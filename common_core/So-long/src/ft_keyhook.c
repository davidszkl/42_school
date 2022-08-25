/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:20:26 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/12 18:00:12 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit(game);
	if (keycode == 13)
	{
		move_up(game, game->x, game->y);
		printf("Current number of moves : %d\n", game->mvcount);
	}
	else if (keycode == 1)
	{
		move_down(game, game->x, game->y);
		printf("Current number of moves : %d\n", game->mvcount);
	}
	else if (keycode == 0)
	{
		move_left(game, game->x, game->y);
		printf("Current number of moves : %d\n", game->mvcount);
	}
	else if (keycode == 2)
	{
		move_right(game, game->x, game->y);
		printf("Current number of moves : %d\n", game->mvcount);
	}
	return (1);
}

void	move_up(t_game *game, int x, int y)
{	
	if (ft_casecheck(game->map.map[y - 1][x], game) == 1)
		ft_move(game, 1);
	else if (ft_casecheck(game->map.map[y - 1][x], game) == 2)
		return ;
	else if (ft_casecheck(game->map.map[y - 1][x], game) == 3)
	{
		mlx_string_put(game->mlx, game->win, 5, 0, 0x00FFFFFF,
			"You didn't collect all of the collectibles yet !");
		return ;
	}
	else if (ft_casecheck(game->map.map[y - 1][x], game) == 4)
	{
		ft_move(game, 1);
		game->map.c--;
	}
	else if (ft_casecheck(game->map.map[y - 1][x], game) == 5)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->back.ground.img,
			game->x * 50, game->y * 50);
		printf("You finished the level in %d moves !\n", game->mvcount);
		ft_exit(game);
	}
}

void	move_down(t_game *game, int x, int y)
{	
	if (ft_casecheck(game->map.map[y + 1][x], game) == 1)
		ft_move(game, 2);
	else if (ft_casecheck(game->map.map[y + 1][x], game) == 2)
		return ;
	else if (ft_casecheck(game->map.map[y + 1][x], game) == 3)
	{
		mlx_string_put(game->mlx, game->win, 5, 0, 0x00FFFFFF,
			"You didn't collect all of the collectibles yet !");
		return ;
	}
	else if (ft_casecheck(game->map.map[y + 1][x], game) == 4)
	{
		ft_move(game, 2);
		game->map.c--;
	}
	else if (ft_casecheck(game->map.map[y + 1][x], game) == 5)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->back.ground.img,
			game->x * 50, game->y * 50);
		printf("You finished the level in %d moves !\n", game->mvcount);
		ft_exit(game);
	}
}

void	move_left(t_game *game, int x, int y)
{
	if (ft_casecheck(game->map.map[y][x - 1], game) == 1)
		ft_move(game, 3);
	else if (ft_casecheck(game->map.map[y][x - 1], game) == 2)
		return ;
	else if (ft_casecheck(game->map.map[y][x - 1], game) == 3)
	{
		mlx_string_put(game->mlx, game->win, 5, 0, 0x00FFFFFF,
			"You didn't collect all of the collectibles yet !");
		return ;
	}
	else if (ft_casecheck(game->map.map[y][x - 1], game) == 4)
	{
		ft_move(game, 3);
		game->map.c--;
	}
	else if (ft_casecheck(game->map.map[y][x - 1], game) == 5)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->back.ground.img,
			game->x * 50, game->y * 50);
		printf("You finished the level in %d moves !\n", game->mvcount);
		ft_exit(game);
	}
}

void	move_right(t_game *game, int x, int y)
{
	if (ft_casecheck(game->map.map[y][x + 1], game) == 1)
		ft_move(game, 4);
	else if (ft_casecheck(game->map.map[y][x + 1], game) == 2)
		return ;
	else if (ft_casecheck(game->map.map[y][x + 1], game) == 3)
	{
		mlx_string_put(game->mlx, game->win, 5, 0, 0x00FFFFFF,
			"You didn't collect all of the collectibles yet !");
		return ;
	}
	else if (ft_casecheck(game->map.map[y][x + 1], game) == 4)
	{
		ft_move(game, 4);
		game->map.c--;
	}
	else if (ft_casecheck(game->map.map[y][x + 1], game) == 5)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->back.ground.img,
			game->x * 50, game->y * 50);
		printf("You finished the level in %d moves !\n", game->mvcount);
		ft_exit(game);
	}
}
