/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:52:08 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/11 16:28:24 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_substr(const char *str, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int	my_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	return (1);
}

int	is_valid_export_arg(const char *s)
{
	if (!(ft_isalpha(*s) || *s == '_'))
		return (0);
	while (*++s && *s != '=')
		if (!(*s == '_' || ft_isalpha(*s) || ft_isdigit(*s)))
			return (0);
	return (1);
}

char	*get_name(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_substr(str, 0, i));
}

char	*get_value(const char *str)
{
	while (*str && *str != '=')
		str++;
	if (*str != '=')
		return (0);
	str += (*str == '=');
	return (ft_substr(str, 0, ft_strlen(str)));
}

int	is_in_envp(const char *name, char **envp)
{
	const size_t	l = ft_strlen(name);

	envp--;
	while (*++envp)
		if (!ft_strncmp(name, *envp, l) && (*envp)[l] == '=')
			return (1);
	return (0);
}
