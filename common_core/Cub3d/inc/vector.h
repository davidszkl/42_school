/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:50:35 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/08 14:02:55 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2i
{
	int	x;
	int	y;
}	t_vec2i;

typedef struct s_vec3i
{
	int	x;
	int	y;
	int	z;
}	t_vec3i;

t_vec2	unit(const t_vec2 v);
t_vec2	rotate(const t_vec2 v, float alpha);
t_vec2	add(const t_vec2 v1, const t_vec2 v2);
t_vec2	sub(const t_vec2 v1, const t_vec2 v2);

#endif
