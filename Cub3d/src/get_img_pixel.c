/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:38:38 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/20 12:53:00 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

int	get_img_pixel(t_img *img, int x, int y)
{
	char	*ptr;

	ptr = img->addr + (y * img->ll + x * (img->bpp / 8));
	return (*((int *)ptr));
}

int	get_img_pixel_uv(t_img *img, float x, float y)
{
	return (get_img_pixel(img, x * (img->w - 1), y * (img->h - 1)));
}
