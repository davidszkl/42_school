/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:56:22 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/08 15:40:54 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

t_map	ft_parser(char *file)
{
	t_map	map;

	map.height = 1;
	map.c = 0;
	map.e = 0;
	map.p = 0;
	ft_bercheck(file, &map);
	if (map.status < 0)
		ft_error(-1);
	ft_makemap(file, &map);
	ft_checkmap(&map);
	return (map);
}

void	ft_bercheck(char *file, t_map *map)
{
	int	n;

	n = 0;
	while (file[n] && file[n] != '.')
		n++;
	if (file[n] == '\0')
	{
		map->status = -1;
		return ;
	}
	else if (file[n] == '.')
	{
		if (ft_strcmp(".ber", &file[n]) == 0 && map->status != -1)
			map->status = 1;
		else
			map->status = -1;
	}
	return ;
}

void	ft_makemap(char *file, t_map *map)
{
	char	*mapstr;
	int		rd;
	int		n;

	rd = ft_getstrl(file);
	mapstr = ft_getstr(file, rd);
	n = 0;
	while (mapstr[n])
		if (mapstr[n++] == '\n')
			map->height++;
	map->width = ft_strnlen(mapstr);
	map->map = malloc(sizeof(char *) * map->height);
	if (!map->map)
		ft_error(-3);
	n = 0;
	rd = 0;
	while (n < map->height)
	{
		map->map[n] = malloc(sizeof(char) * map->width + 2);
		if (!map->map[n])
			ft_error(-3);
		ft_strncpy(map->map[n++], mapstr, map->width, rd);
		rd += (map->width + 1);
	}
	free(mapstr);
}

int	ft_getstrl(char *file)
{
	char	*buff;
	int		fd;
	int		rd;
	int		n;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(-2);
	n = 0;
	while (n++ >= 0)
	{
		buff = malloc(sizeof(char) * 2048 * n);
		if (!buff)
			ft_error(-3);
		rd = read(fd, buff, 2048);
		free(buff);
		if (rd == -1)
			ft_error(-2);
		else if (rd != 2048)
			break ;
	}
	rd = (n - 1) * 2048 + rd;
	close(fd);
	return (rd);
}

char	*ft_getstr(char *file, int size)
{
	int		fd;
	char	*mapstr;

	if (size == -1)
		ft_error(-2);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	mapstr = malloc(sizeof(char) * size + 1);
	if (!mapstr)
		ft_error(-3);
	if (read(fd, mapstr, size) == -1)
	{
		free(mapstr);
		ft_error(-2);
	}
	mapstr[size] = '\0';
	close(fd);
	return (mapstr);
}
