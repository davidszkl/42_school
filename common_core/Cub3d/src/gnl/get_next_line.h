/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:52:15 by mlefevre          #+#    #+#             */
/*   Updated: 2021/12/10 10:54:45 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 128

# include <stddef.h>
# include <unistd.h>

typedef struct s_loc
{
	ssize_t	n;
	char	*r;
}	t_loc;
typedef struct s_locs
{
	char	buf[BUFFER_SIZE];
	size_t	filled;
}	t_locs;
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
