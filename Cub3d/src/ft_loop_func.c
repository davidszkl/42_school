/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:52:19 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/20 13:26:17 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "cub3d.h"
#include "raytrace_return.h"

int					get_img_pixel_uv(t_img *img, float x, float y);
t_raytrace_return	raytrace(t_vec2 pos,
						t_vec2 dir, const char **map, t_vec2i map_dim);
void				apply_movement(t_main *main);
int					get_texture_color(float yoffset,
						t_main *main, t_raytrace_return r, t_vec2 dir);

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->ll + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	arr_to_int(int *arr)
{
	return ((arr[0] << 16) + (arr[1] << 8) + (arr[2]));
}

static void	draw_wall(t_vec2 dir,
		t_main *main, const int x, t_raytrace_return r)
{
	const float	a = atan2f(dir.y, dir.x)
		- atan2f(main->player_dir.y, main->player_dir.x);
	int			wall_len;
	int			wall_len2;
	int			y2;
	int			y;

	wall_len = SIZE_Y / (cosf(a) * r.d);
	wall_len2 = wall_len;
	if (wall_len > SIZE_Y)
		wall_len2 = SIZE_Y;
	y = -1;
	while (++y < (SIZE_Y - wall_len2) / 2)
		my_mlx_pixel_put(&main->img, x, y, arr_to_int(main->ceilling.rgb1));
	y2 = y;
	y--;
	while (++y - y2 < wall_len2)
		my_mlx_pixel_put(&main->img, x, y, get_texture_color((float)(y
					- y2 + (wall_len - wall_len2) / 2)
				/ (float)wall_len, main, r, dir));
	y2 = y;
	y--;
	while (++y - y2 < (SIZE_Y - wall_len2) / 2)
		my_mlx_pixel_put(&main->img, x, y, arr_to_int(main->floor.rgb1));
}

int	ft_loop_func(t_main *main)
{
	t_vec2				p;
	t_raytrace_return	r;
	t_vec2				dir;
	int					x;

	apply_movement(main);
	p = rotate(main->player_dir, PI / 2);
	x = -1;
	while (++x < SIZE_X)
	{
		dir.x = main->player_dir.x
			/ 2. + p.x * (x - SIZE_X / 2.) / (float)SIZE_X;
		dir.y = main->player_dir.y
			/ 2. + p.y * (x - SIZE_X / 2.) / (float)SIZE_X;
		dir = unit(dir);
		r = raytrace(main->player_pos,
				dir, (const char **)main->map, main->map_dim);
		draw_wall(dir, main, x, r);
	}
	mlx_put_image_to_window(main->mlx, main->win, main->img.img, 0, 0);
	return (0);
}
