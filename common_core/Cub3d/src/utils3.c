/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:19:45 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/04 14:19:46 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "utils.h"
#include "free.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return (1);
	write(fd, s, ft_strlen(s));
	return (1);
}

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_get_2nd_word_index(char *line)
{
	int	n;

	n = 0;
	while (line[n] && (line[n] == ' ' || line[n] == 9))
		n++;
	while (line[n] && ft_isprint(line[n]) && line[n] != ' ')
		n++;
	return (n);
}

char	*ft_strdup_fill(char *str, size_t l, char fill)
{
	size_t	count;
	char	*s;
	int		n;

	count = 0;
	n = 0;
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
		return (0);
	while (str[n] && count++ < l && str[n] != '\n')
	{
		s[n] = str[n];
		n++;
	}
	if (str[n] == '\n' && count < l)
		s[n++] = fill;
	while (count++ < l - 1)
		s[n++] = fill;
	s[n++] = '\n';
	s[n] = 0;
	return (s);
}

// should be in read_file as static but no space there
char	**ft_read_nospace_file(char *tmp, char **new, int count, int fd)
{
	count = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		if (!ft_is_empty(tmp))
		{
			new[count] = ft_strdup(tmp);
			if (!new[count++] && ft_freetab(new, 1) && ft_myfree(tmp, 1))
			{
				close(fd);
				return (NULL);
			}
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	new[count] = NULL;
	free(tmp);
	if (count < 6 && ft_freetab(new, 1))
	{
		close(fd);
		return (NULL);
	}
	return (new);
}
