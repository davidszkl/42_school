/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:58:21 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/08 14:32:36 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raytrace_return.h"

int					get_img_pixel_uv(t_img *img, float x, float y);

t_img	*get_texture(t_main *main, int wdir)
{
	if (wdir == NORTH)
		return (&main->north);
	if (wdir == SOUTH)
		return (&main->south);
	if (wdir == EAST)
		return (&main->east);
	return (&main->west);
}

int	get_texture_color(float yoffset,
		t_main *main, t_raytrace_return r, t_vec2 dir)
{
	const t_vec2	rpos = (t_vec2){main->player_pos.x
		+ dir.x * r.d, main->player_pos.y + dir.y * r.d};
	float			xoffset;
	t_img			*text;

	text = get_texture(main, r.wall_dir);
	if (r.wall_dir == NORTH || r.wall_dir == SOUTH)
		xoffset = rpos.x - (int)rpos.x;
	if (r.wall_dir == EAST || r.wall_dir == WEST)
		xoffset = rpos.y - (int)rpos.y;
	return (get_img_pixel_uv(text, xoffset, yoffset));
}
