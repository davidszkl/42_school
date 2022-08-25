/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:46:03 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/09 10:52:24 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raytrace_return.h"
#include "cub3d.h"
#include "vector.h"

t_raytrace_return	get_x_dist(t_vec2 pos, t_vec2 dir,
	const char **map, t_vec2i map_dim)
{
	t_vec2				tmp;
	t_raytrace_return	r;
	float				ypos;
	int					i;

	dir.y /= fabsf(dir.x);
	r.d = -1;
	i = 0;
	while (++i < map_dim.x)
	{
		if (dir.x * (i - pos.x) <= 0)
			continue ;
		ypos = pos.y + (dir.y * fabsf(i - pos.x));
		ypos = (float [2]){ypos, map_dim.y - 1.f}[(int)ypos >= map_dim.y];
		ypos = (float [2]){ypos, 0.f}[(int)ypos < 0];
		if (map[(int)ypos][i - (i < pos.x)] == '1')
		{
			tmp = (t_vec2){fabsf(i - pos.x), fabsf(ypos - pos.y)};
			if (r.d < 0 || r.d > tmp.x * tmp.x + tmp.y * tmp.y)
				r.d = tmp.x * tmp.x + tmp.y * tmp.y;
		}
	}
	r.wall_dir = ((int [2]){EAST, WEST})[dir.x > 0];
	r.d = sqrtf(r.d);
	return (r);
}

t_raytrace_return	get_y_dist(t_vec2 pos, t_vec2 dir,
	const char **map, t_vec2i map_dim)
{
	t_vec2				tmp;
	t_raytrace_return	r;
	float				xpos;
	int					i;

	dir.x /= fabsf(dir.y);
	r.d = -1;
	i = 0;
	while (++i < map_dim.y)
	{
		if (dir.y * (i - pos.y) <= 0)
			continue ;
		xpos = pos.x + (dir.x * fabsf(i - pos.y));
		xpos = (float [2]){xpos, map_dim.x - 1.f}[(int)xpos >= map_dim.x];
		xpos = (float [2]){xpos, 0.f}[(int)xpos < 0];
		if (map[i - (i < pos.y)][(int)xpos] == '1')
		{
			tmp = (t_vec2){fabsf(i - pos.y), fabsf(xpos - pos.x)};
			if (r.d < 0 || r.d > tmp.x * tmp.x + tmp.y * tmp.y)
				r.d = tmp.x * tmp.x + tmp.y * tmp.y;
		}
	}
	r.wall_dir = ((int [2]){SOUTH, NORTH})[dir.y > 0];
	r.d = sqrtf(r.d);
	return (r);
}

//dir MUST be a unit vector (unit_v2)
t_raytrace_return	raytrace(t_vec2 pos,
	t_vec2 dir, const char **map, t_vec2i map_dim)
{
	t_raytrace_return	r;
	t_raytrace_return	r_tmp;

	r.d = 0;
	r.wall_dir = NORTH;
	if (dir.x != 0)
	{
		r_tmp = get_x_dist(pos, dir, map, map_dim);
		if ((r.d == 0 || r.d > r_tmp.d) && r_tmp.d >= 0)
			r = r_tmp;
	}
	if (dir.y != 0)
	{
		r_tmp = get_y_dist(pos, dir, map, map_dim);
		if ((r.d == 0 || r.d > r_tmp.d) && r_tmp.d >= 0)
			r = r_tmp;
	}
	return (r);
}
