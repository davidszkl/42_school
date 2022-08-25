/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:11:51 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/20 13:20:32 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static int	sq_ci_coll(t_vec2 sq, t_vec2 ci)
{
	const float	rad = 0.4;
	const float	dx = fabsf(sq.x - ci.x);
	const float	dy = fabsf(sq.y - ci.y);
	const float	d = sqrtf(dx * dx + dy * dy);

	return (d <= fminf(rad, fmaxf(dx, dy)) + rad);
}

static int	is_collision(t_main *main, t_vec2 pos)
{
	t_vec2i	i;

	i.y = -1;
	while (++i.y < main->map_dim.y)
	{
		i.x = -1;
		while (++i.x < main->map_dim.x)
			if (main->map[i.y][i.x] == '1'
					&& sq_ci_coll((t_vec2){i.x + .5, i.y + .5}, pos))
				return (1);
	}
	return (0);
}

void	apply_movement(t_main *main)
{
	t_vec2			tmp;
	const t_vec2	player_dir01
		= (t_vec2){main->player_dir.x * 0.05, main->player_dir.y * 0.05};

	tmp = main->player_pos;
	if (main->left_held)
		main->player_dir = rotate(main->player_dir, -PI / 70.);
	if (main->right_held)
		main->player_dir = rotate(main->player_dir, PI / 70.);
	if (main->w_held)
		tmp = add(tmp, player_dir01);
	if (main->s_held)
		tmp = sub(tmp, player_dir01);
	if (main->a_held)
		tmp = add(tmp, rotate(player_dir01, -PI / 2.));
	if (main->d_held)
		tmp = sub(tmp, rotate(player_dir01, -PI / 2.));
	if (!is_collision(main, tmp))
		main->player_pos = tmp;
}
