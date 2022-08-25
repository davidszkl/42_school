/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:32:01 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/09 11:21:23 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "fcntl.h"
#include "free.h"
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s1)
{
	size_t	l;
	char	*s;

	l = ft_strlen(s1);
	s = malloc(l + 1);
	if (!s)
		return (0);
	while (*s1)
		*s++ = *s1++;
	*s = 0;
	return (s - l);
}

char	**ft_tabcpy(char **tab)
{
	char	**new;
	size_t	n;

	n = 0;
	while (tab[n])
		n++;
	new = (char **)malloc(sizeof(char *) * (n + 1));
	if (!new)
		return (NULL);
	n = 0;
	while (tab[n])
	{
		new[n] = ft_strdup(tab[n]);
		if (!new[n])
		{
			ft_freetab(new, 0);
			return (NULL);
		}
		n++;
	}
	new[n] = NULL;
	return (new);
}

int	ft_is_news(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (1);
	return (0);
}

int	ft_get_gnl_len(char *file)
{
	char	*tmp;
	int		count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (!ft_is_empty(tmp))
			count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	close(fd);
	return (count);
}
