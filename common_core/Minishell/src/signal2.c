/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:51:47 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/26 09:51:49 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

extern t_main	*g_glb;

void	ft_sigint_heredoc1(int signbr)
{
	free(g_glb->line);
	g_glb->line = ft_strdup("");
	g_glb->error = 1;
	(void)signbr;
}
