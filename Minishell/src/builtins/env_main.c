/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:28:34 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 13:40:06 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_showtab(char **tab);

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	ft_showtab(envp);
	return (0);
}
