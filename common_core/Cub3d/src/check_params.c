/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:09 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 14:44:11 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "cub3d.h"
#include "free.h"

static char	*ft_get_rgb(char *str, int n)
{
	char	*new;
	int		t;

	while (str[n] && (str[n] == ' ' || str[n] == 9))
		n++;
	t = n;
	while (str[n] && ft_isprint(str[n]))
		n++;
	new = malloc(sizeof(char) * (n - t + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (str[t] && ft_isprint(str[t]))
		new[n++] = str[t++];
	new[n] = 0;
	return (new);
}

static int	ft_check_rgb(t_main *main, char *line, int index)
{
	size_t	count;
	int		n;

	count = 0;
	n = ft_get_2nd_word_index(line);
	main->temp = ft_get_rgb(line, n);
	if (!main->temp)
		return (1);
	if (main->floor.line == index)
	{
		if (ft_atoi_loop(main, 1))
			return (ft_myfree(main->temp, 1));
	}
	else if (main->ceilling.line == index)
	{
		if (ft_atoi_loop(main, 2))
			return (ft_myfree(main->temp, 1));
	}
	return (ft_myfree(main->temp, 0));
}

static int	ft_check_path(t_main *main, char *line, int index)
{
	size_t	n;
	char	*tmp;
	int		fd;

	n = ft_get_2nd_word_index(line);
	tmp = ft_getword_simple(line, n);
	if (!tmp)
		return (1);
	fd = open(tmp, O_RDONLY);
	if (fd < 0)
	{
		my_perror(tmp);
		return (ft_myfree(tmp, 1));
	}
	close(fd);
	if (main->north.line == index)
		main->north.path = tmp;
	else if (main->south.line == index)
		main->south.path = tmp;
	else if (main->east.line == index)
		main->east.path = tmp;
	else if (main->west.line == index)
		main->west.path = tmp;
	return (0);
}

static int	ft_check_id(t_main *main, char *tmp, int *check, int index)
{
	int		condition;
	int		n;

	condition = 0;
	n = 0;
	if (!ft_strncmp(tmp, "NO", 3) && ++condition && check[0]++ >= 0)
		main->north.line = index;
	else if (!ft_strncmp(tmp, "SO", 3) && ++condition && check[1]++ >= 0)
		main->south.line = index;
	else if (!ft_strncmp(tmp, "EA", 3) && ++condition && check[2]++ >= 0)
		main->east.line = index;
	else if (!ft_strncmp(tmp, "WE", 3) && ++condition && check[3]++ >= 0)
		main->west.line = index;
	else if (!ft_strncmp(tmp, "F", 2) && ++condition && check[4]++ >= 0)
		main->floor.line = index;
	else if (!ft_strncmp(tmp, "C", 2) && ++condition && check[5]++ >= 0)
		main->ceilling.line = index;
	while (n < 6)
		if (check[n++] > 1)
			return (1);
	if (!condition)
		return (1);
	return (0);
}

int	ft_check_params(t_main *main, char **tab)
{
	char	*tmp;
	int		check[6];
	int		n;

	n = 0;
	while (n < 6)
		check[n++] = 0;
	n = -1;
	while (tab[++n])
	{
		tmp = ft_getword_simple(tab[n], 0);
		if (!tmp)
			return (4);
		if (ft_check_id(main, tmp, check, n))
			return (ft_myfree(tmp, 1));
		if ((!ft_strncmp(tmp, "NO", 3) || !ft_strncmp(tmp, "SO", 3)
				|| !ft_strncmp(tmp, "EA", 3) || !ft_strncmp(tmp, "WE", 3))
			&& ft_check_path(main, tab[n], n))
			return (ft_myfree(tmp, 2));
		else if ((!ft_strncmp(tmp, "F", 2) || !ft_strncmp(tmp, "C", 2))
			&& ft_check_rgb(main, tab[n], n))
			return (ft_myfree(tmp, 3));
		free(tmp);
	}
	return (0);
}

