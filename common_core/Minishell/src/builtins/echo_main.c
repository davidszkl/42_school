/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:34:04 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 16:54:04 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_putstr_fd(const char *s, int fd);

static int	is_nl_param(const char *s)
{
	if (!s || !*s)
		return (0);
	if (*s != '-')
		return (0);
	while (*++s)
		if (*s != 'n')
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		nl;
	int		b;

	(void)argc;
	i = 0;
	nl = 1;
	while (is_nl_param(argv[++i]))
		nl = 0;
	i--;
	b = 1;
	while (argv[++i])
	{
		if (!b)
			ft_putstr_fd(" ", 1);
		b = 0;
		ft_putstr_fd(argv[i], 1);
	}
	if (nl)
		ft_putstr_fd("\n", 1);
	return (0);
}
