/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:31:29 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/08 14:02:51 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_dir(char c)
{
	return (c == 'N'
		|| c == 'S'
		|| c == 'E'
		|| c == 'W');
}

static t_vec2	set_dir(char c)
{
	t_vec2	r;

	if (c == 'N')
		r = (t_vec2){0, -1};
	if (c == 'S')
		r = (t_vec2){0, 1};
	if (c == 'E')
		r = (t_vec2){1, 0};
	if (c == 'W')
		r = (t_vec2){-1, 0};
	return (r);
}

void	ft_init_player(t_main *main)
{
	t_vec2i	i;

	main->left_held = 0;
	main->right_held = 0;
	main->w_held = 0;
	main->a_held = 0;
	main->s_held = 0;
	main->d_held = 0;
	i.y = 0;
	while (i.y < main->map_dim.y)
	{
		i.x = 0;
		while (i.x < main->map_dim.x)
		{
			if (is_dir(main->map[i.y][i.x]))
			{
				main->player_dir = set_dir(main->map[i.y][i.x]);
				main->player_pos = (t_vec2){i.x + .5, i.y + .5};
				return ;
			}
			i.x++;
		}
		i.y++;
	}
}
