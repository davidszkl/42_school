/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:17:40 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/08 14:24:21 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"
#include "free.h"

void	ft_exit(t_main *main)
{
	ft_free_all(main, 0);
	exit(0);
}

static void	ft_init_struct(t_main *main, int argc)
{
	(void)argc;
	main->north.path = 0;
	main->north.img = 0;
	main->north.line = -1;
	main->south.path = 0;
	main->south.img = 0;
	main->south.line = -1;
	main->east.path = 0;
	main->east.img = 0;
	main->east.line = -1;
	main->west.path = 0;
	main->west.img = 0;
	main->west.line = -1;
}

static int	ft_simple_checks(int argc, char *argv)
{
	int	n;

	if (argc != 2)
		return (ft_putstr_fd(ARG_ERR, 2));
	n = ft_strlen(argv);
	if (open(argv, O_RDONLY) < 0)
		return (ft_putstr_fd("Error\nCould not open file\n", 2));
	while (n && argv[n] != '.')
		n--;
	if (!n)
		return (ft_putstr_fd(EXT_ERR, 2));
	if (ft_strncmp(&argv[n], ".cub", -1))
		return (ft_putstr_fd(EXT_ERR, 2));
	return (0);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_simple_checks(argc, argv[1]))
		return (1);
	ft_init_struct(&main, argc);
	if (ft_file_struct(&main, argv[1]))
		return (1);
	ft_init_player(&main);
	if (ft_mlx_init(&main))
		return (ft_free_all(&main, 1));
	return (0);
}
