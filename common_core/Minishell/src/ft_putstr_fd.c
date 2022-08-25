/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 08:49:31 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 13:20:21 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *s);

int	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (1);
	write(fd, s, ft_strlen(s));
	return (1);
}
