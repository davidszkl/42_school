/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:49:30 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/10 17:26:08 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n] && s1[n] && s2[n])
		n++;
	return (s1[n] - s2[n]);
}

int	ft_strnlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	return (n);
}

int	ft_strchr(char *s, char c)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		if (s[n++] == c)
			return (1);
	return (0);
}

void	ft_strncpy(char *map, char *mapstr, int size, int j)
{
	int	n;

	n = 0;
	while (n < size)
		map[n++] = mapstr[j++];
	if (mapstr[j] == '\0')
		map[n] = '\0';
	else if (mapstr[j] == '\n')
		map[n++] = mapstr[j++];
	map[n] = '\0';
}
