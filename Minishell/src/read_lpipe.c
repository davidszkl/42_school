/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lpipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:09:06 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/10 14:09:09 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	ft_read_lpipe(t_main *main)
{
	char	*temp;

	main->temp = readline("> ");
	temp = ft_replace_str(main->line, ft_strlen(main->line), 0, main->temp);
	free(main->line);
	main->line = temp;
	free(main->temp);
	if (!main->line)
		return (1);
	return (0);
}
