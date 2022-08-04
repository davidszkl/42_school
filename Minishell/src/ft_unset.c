/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:58:35 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/15 17:14:04 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int		del_in_envp(const char *name, char ***envp);
int		is_in_envp(const char *name, char **envp);
int		ft_isalpha(int c);
int		ft_isalnum(int c);

static int	my_putstr_fd(const char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	return (1);
}

static int	put_invalid_id(const char *s)
{
	my_putstr_fd("unset: `", 2);
	my_putstr_fd(s, 2);
	my_putstr_fd("': not a valid identifier\n", 2);
	return (1);
}

static int	is_valid_identifier(const char *str)
{
	if (!(ft_isalpha(*str) || *str == '_'))
		return (0);
	while (*++str)
		if (!(ft_isalnum(*str) || *str == '_'))
			return (0);
	return (1);
}

int	ft_unset(char ***envp, char ***locals, char **argv)
{
	int		r;
	size_t	i;

	r = 0;
	i = 0;
	while (argv[++i])
	{
		if (!is_valid_identifier(argv[i]))
		{
			put_invalid_id(argv[i]);
			r = 1;
			continue ;
		}
		if (is_in_envp(argv[i], *locals) && !del_in_envp(argv[i], locals))
			return (-1);
		if (is_in_envp(argv[i], *envp) && !del_in_envp(argv[i], envp))
			return (-1);
	}
	return (r);
}
