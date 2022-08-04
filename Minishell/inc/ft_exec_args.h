/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_args.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:48:15 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 12:46:50 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_ARGS_H
# define FT_EXEC_ARGS_H

# include <stddef.h>

typedef struct s_exec_args
{
	size_t	n;
	int		status;
	int		fd_r;
	int		fd_w;
	size_t	i;
	int		*pipes;
}	t_exec_args;

#endif
