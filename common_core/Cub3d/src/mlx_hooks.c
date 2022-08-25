/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:40:16 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/07 16:07:46 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

#define ESC 53
#define W 13
#define A 0
#define S 1
#define D 2
#define LEFT 123
#define RIGHT 124

int	ft_keyhook(int keycode, t_main *main)
{
	if (keycode == 53)
		ft_exit(main);
	if (keycode == LEFT)
		main->left_held = 1;
	if (keycode == RIGHT)
		main->right_held = 1;
	if (keycode == W)
		main->w_held = 1;
	if (keycode == S)
		main->s_held = 1;
	if (keycode == A)
		main->a_held = 1;
	if (keycode == D)
		main->d_held = 1;
	return (0);
}

int	ft_release_hook(int keycode, t_main *main)
{
	if (keycode == LEFT)
		main->left_held = 0;
	if (keycode == RIGHT)
		main->right_held = 0;
	if (keycode == W)
		main->w_held = 0;
	if (keycode == S)
		main->s_held = 0;
	if (keycode == A)
		main->a_held = 0;
	if (keycode == D)
		main->d_held = 0;
	return (0);
}

int	ft_exithook(t_main *main)
{
	ft_exit(main);
	return (0);
}
