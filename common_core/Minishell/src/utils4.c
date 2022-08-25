/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:13:23 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/10 15:39:32 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

// 1 -> "<<"
// 2 -> ">>"
// 3 -> "<"
// 4 -> ">"

int	ft_is_chev(char *str, int n)
{
	if (n == 0 && str[n] == '<' && str[n + 1] == '<')
		return (1);
	else if (n == 0 && str[n] == '>' && str[n + 1] == '>')
		return (2);
	else if (n == 0 && str[n] == '<' && str[n + 1] != '<')
		return (3);
	else if (n == 0 && str[n] == '>' && str[n + 1] != '>')
		return (4);
	if (n > 0 && str[n - 1] != '<' && str[n] == '<' && str[n + 1] == '<')
		return (1);
	else if (n > 0 && str[n - 1] != '>' && str[n] == '>' && str[n + 1] == '>')
		return (2);
	else if (n > 0 && str[n - 1] != '<' && str[n] == '<' && str[n + 1] != '<')
		return (3);
	else if (n > 0 && str[n - 1] != '>' && str[n] == '>' && str[n + 1] != '>')
		return (4);
	return (0);
}

void	ft_putendl_fd(char	*str, int fd)
{
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}

int	ft_check_chevpipe(char	*str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		if (ft_is_chev(str, n) == 1 && !ft_isinquote_now(str, n))
			return (1);
		n++;
	}
	while (ft_isspace(str[n]) == 1)
		n--;
	if (!str[n] && ft_strlen(str))
		n--;
	if (str[n] == '|')
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d2;
	const unsigned char	*s2;

	s2 = src;
	d2 = dst;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d2++ = *s2++;
	return (dst);
}

int	ft_myfreemain(t_main *main)
{
	ft_freetab(main->envp);
	ft_freetab(main->locals);
	free(main->line);
	return (1);
}
