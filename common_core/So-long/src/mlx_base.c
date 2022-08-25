/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:53:53 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/12 18:00:35 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

static void	ft_textureput(t_map *map, t_game *game, int n, int j);

void	my_mlx_init(t_game *game)
{
	t_back	back;
	t_img	hero;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_mlx_error(game, 0);
	if (game->map.height > 57 || game->map.width > 102)
		ft_map_error(&game->map, -1);
	game->win = mlx_new_window(game->mlx, game->map.width * 50,
			game->map.height * 50, "1");
	ft_img(game, &back.ground, "rsrc/ground.xpm");
	ft_img(game, &back.wall, "rsrc/wall.xpm");
	ft_img(game, &back.wallin, "rsrc/wallin.xpm");
	ft_img(game, &back.cont, "rsrc/cont.xpm");
	ft_img(game, &back.exit, "rsrc/exit.xpm");
	ft_img(game, &hero, "rsrc/hero.xpm");
	game->back = back;
	game->hero = hero;
	ft_load(&game->map, game);
}

void	ft_img(t_game *game, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(game->mlx, file,
			&img->w, &img->h);
	if (!img->img)
		ft_mlx_error(game, -1);
	if (img->w != 50 || img->h != 50)
		ft_mlx_error(game, -2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		ft_mlx_error(game, -1);
}

void	ft_load(t_map *map, t_game *game)
{
	int	n;
	int	j;

	n = 0;
	while (n < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_textureput(map, game, n, j);
			j++;
		}
		n++;
	}
}

static void	ft_textureput(t_map *map, t_game *game, int n, int j)
{
	if (map->map[n][j] == '1' && ((n == 0 || n == map->height - 1) ||
	((n > 0 && n < map->height) && (j == 0 || j == map->width - 1))))
		mlx_put_image_to_window(game->mlx, game->win,
			game->back.wall.img, j * 50, n * 50);
	else if (map->map[n][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->back.wallin.img, j * 50, n * 50);
	else if (map->map[n][j] == 'P' && map->p)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->hero.img, j * 50, n * 50);
		game->x = j;
		game->y = n;
		map->p = 0;
	}
	else if (map->map[n][j] == '0' || (map->map[n][j] == 'P' && map->p == 0))
		mlx_put_image_to_window(game->mlx, game->win,
			game->back.ground.img, j * 50, n * 50);
	else if (map->map[n][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->back.cont.img, j * 50, n * 50);
	else if (map->map[n][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->back.exit.img, j * 50, n * 50);
}
