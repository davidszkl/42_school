/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:30:12 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/11 13:08:36 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!argv[1] || argc != 2)
		ft_error(0);
	game.map = ft_parser(argv[1]);
	if (game.map.status < 0)
		ft_map_error(&game.map, 0);
	my_mlx_init(&game);
	game.mvcount = 0;
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 2, mouse_hook, &game);
	mlx_loop(game.mlx);
	return (1);
}
