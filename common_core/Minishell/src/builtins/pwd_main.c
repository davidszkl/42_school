/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:31:33 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 13:46:50 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/param.h>

void	ft_putstr_fd(const char *s, int fd);

int	main(void)
{
	char	s[MAXPATHLEN + 1];

	getcwd(s, MAXPATHLEN + 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
