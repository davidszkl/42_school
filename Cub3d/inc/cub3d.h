/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <dszklarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:07:54 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/20 13:24:44 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

/*settings*/

# define SIZE_X 1280
# define SIZE_Y 900

/*errors*/

# define ARG_ERR "Error\nargument error: should be 1\n"
# define EXT_ERR "Error\nextension error: should be .cub\n"
# define ID_ERR "Error\nid error: missing / wrong / duplicate id\n"
# define RGB_ERR "Error\nrgb error: wrong rgb values (range 0-255)\n"
# define MAP_ERR "Error\nmap error: missing map\n"
# define MAP1_ERR "Error\nmap error: wrong characters in map\n"
# define MAP3_ERR "Error\nmap error: space not enclosed\n"
# define MAP2_ERR "Error\nmap error: duplicate character token\n"

/*sides convention*/

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

/*constants*/

# define PI 3.141592654

/*includes*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "vector.h"
# include "img.h"

/*structures*/

typedef struct s_fill {
	int		line;
	int		rgb1[3];
}	t_fill;

typedef struct s_main {
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	img;
	t_fill	floor;
	t_fill	ceilling;
	t_vec2i	map_dim;
	t_vec2	player_dir;
	t_vec2	player_pos;
	void	*mlx;
	void	*win;
	char	**file;
	char	**params;
	char	**map;
	char	*temp;
	int		a;
	int		left_held;
	int		right_held;
	int		w_held;
	int		a_held;
	int		s_held;
	int		d_held;
}	t_main;

/*parser*/

char	**ft_read_nospace_file(char *tmp, char **new, int count, int fd);
int		ft_file_struct(t_main *main, char *file);
int		ft_check_params(t_main *main, char **tab);
int		ft_atoi_loop(t_main *main, int nbr);
int		ft_check_map(t_main *main);

/*mlx*/

int		ft_mlx_init(t_main *main);
int		ft_keyhook(int keycode, t_main *main);
int		ft_release_hook(int keycode, t_main *main);
int		ft_exithook(t_main *main);
int		ft_loop_func(t_main *main);

/*free*/

void	ft_exit(t_main *main);
int		ft_free_paths(t_main *main, int rval);
int		ft_free_all(t_main *main, int rval);

/*player dir*/

void	ft_init_player(t_main *main);

#endif
