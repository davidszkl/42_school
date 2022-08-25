/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_return.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:23:38 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/02 15:27:56 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACE_RETURN_H
# define RAYTRACE_RETURN_H

typedef struct s_raytrace_return
{
	float	d;
	int		wall_dir;
}	t_raytrace_return;

#endif
