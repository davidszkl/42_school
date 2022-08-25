/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:25:58 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/25 11:26:00 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

void	ft_freefiles(t_main *main, int n)
{
	int	j;

	j = 0;
	while (j < main->cline[n].rin)
		free(main->cline[n].file_in[j++].name);
	j = 0;
	while (j < main->cline[n].rout)
		free(main->cline[n].file_out[j++].name);
}
