/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:54:18 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 10:54:20 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "utils.h"
#include "free.h"
#include "get_next_line.h"

//get map from main->file

static char	**ft_get_map(char **file)
{
	char	**new;
	int		count;
	int		n;

	count = 0;
	n = 0;
	new = (char **)malloc(sizeof(char *) * (ft_tablen(file) - 6 + 1));
	if (!new)
		return (NULL);
	while (file[n] && count++ < 6)
		n++;
	if (!file[n] && ft_freetab(new, 1))
		return (NULL);
	count = n;
	n = 0;
	while (file[count])
	{
		new[n] = ft_strdup(file[count++]);
		if (!new[n++] && ft_freetab(new, 1))
			return (NULL);
	}
	new[n] = NULL;
	return (new);
}

//get_params from main->file into params

static char	**ft_get_params(char **file)
{
	char	**new;
	size_t	n;
	size_t	j;

	n = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * 7);
	if (!new)
		return (NULL);
	while (file[n] && j < 6)
	{
		new[j] = ft_strdup(file[n++]);
		if (!new[j++] && ft_freetab(new, 1))
			return (NULL);
	}
	if (j < 6)
	{
		ft_freetab(new, 1);
		ft_putstr_fd(ID_ERR, 2);
		return (NULL);
	}
	new[j] = NULL;
	return (new);
}

// read file to main->file

static char	**ft_read_file(t_main *main, char *file_name)
{
	char	**new;
	int		count;
	int		fd;

	count = ft_get_gnl_len(file_name);
	if (count == -1)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new)
	{
		close(fd);
		return (NULL);
	}
	new = ft_read_nospace_file(main->temp, new, count, fd);
	if (!new)
		return (NULL);
	if (ft_tablen(new) < 6 && ft_freetab(new, 1))
		return (NULL);
	close(fd);
	return (new);
}

// second part for norm

static int	ft_file_struct1(t_main *main)
{
	main->map = ft_get_map(main->file);
	if (!main->map)
	{
		ft_putstr_fd(MAP_ERR, 2);
		ft_freetab(main->params, 1);
		ft_free_paths(main, 1);
		return (ft_freetab(main->file, 1));
	}
	if (ft_check_map(main))
	{
		ft_freetab(main->params, 1);
		ft_freetab(main->map, 0);
		ft_free_paths(main, 1);
		return (ft_freetab(main->file, 1));
	}
	return (0);
}

// read file to main->file, get param, check param, get map, check map

int	ft_file_struct(t_main *main, char *file)
{
	main->file = ft_read_file(main, file);
	if (!main->file)
		return (ft_putstr_fd(ID_ERR, 2));
	main->params = ft_get_params(main->file);
	if (!main->params)
		return (ft_freetab(main->file, 1));
	main->a = ft_check_params(main, main->params);
	if (main->a)
	{
		if (main->a == 1)
			ft_putstr_fd(ID_ERR, 2);
		if (main->a == 3)
			ft_putstr_fd(RGB_ERR, 2);
		ft_free_paths(main, 1);
		ft_freetab(main->params, 1);
		return (ft_freetab(main->file, 1));
	}
	if (ft_file_struct1(main))
		return (1);
	return (0);
}
