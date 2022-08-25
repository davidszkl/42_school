/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_chev2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:31:20 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/26 10:31:22 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

void	ft_child_doc(t_main *main, char *str)
{
	int	fd;

	signal(SIGINT, ft_sigint_heredoc2);
	fd = open(main->chev.path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		exit((ft_myfree(str)));
	main->temp = readline("> ");
	while (ft_strncmp(main->temp, str, ft_strlen(main->temp) + 1))
	{	
		ft_putendl_fd(main->temp, fd);
		free(main->temp);
		main->temp = readline("> ");
	}
	close(fd);
	free(main->temp);
	free(str);
	exit(0);
}
