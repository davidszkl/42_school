/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:08:51 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 13:41:12 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_exit(char **argv);

int	main(int argc, char **argv)
{
	int	r;

	(void)argc;
	r = ft_exit(argv);
	if (r == -1)
		return (1);
	exit(r);
}
