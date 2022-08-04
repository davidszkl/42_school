/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:35:07 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/10 17:30:24 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

/*includes*/

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>

/*Structures*/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_back {
	t_img	ground;
	t_img	wall;
	t_img	wallin;
	t_img	cont;
	t_img	exit;
}	t_back;

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
	int		c;
	int		e;
	int		p;
	int		status;
}	t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_map	map;
	t_back	back;
	t_img	hero;
	int		mvcount;
	int		x;
	int		y;
}	t_game;

/*Parser*/

t_map	ft_parser(char *file);
void	ft_bercheck(char *file, t_map *map);
void	ft_makemap(char *file, t_map *map);
int		ft_getstrl(char *file);
char	*ft_getstr(char *file, int size);
void	ft_strncpy(char *map, char *mapstr, int size, int j);

/*Strings*/

void	ft_strcpyn(char *str, char *dst);
int		ft_strcmp(char *s1, char *s2);
int		ft_strnlen(char *str);
int		ft_strchr(char *s, char c);

/*Checks & Error*/

void	ft_error(int n);
void	ft_map_error(t_map *map, int n);
void	ft_mlx_error(t_game *game, int n);
void	ft_checkmap(t_map *map);
int		ft_check(char c);
void	ft_increment(t_map *map, char c);
int		ft_casecheck(char c, t_game *game);
void	ft_exit(t_game *game);
void	ft_free_tab(char **tab, int height, int size);

/*Mlx*/

void	my_mlx_init(t_game *game);
void	ft_img(t_game *game, t_img *img, char *file);
void	ft_load(t_map *map, t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);
void	ft_move(t_game *game, int dir);
int		key_hook(int keycode, t_game *game);
int		mouse_hook(t_game *game);

#endif
