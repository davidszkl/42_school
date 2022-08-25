/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:13:35 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/08 14:01:06 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
	int		w;
	int		h;
	char	*path;
	int		line;
}	t_img;

#endif
