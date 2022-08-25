/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:31:27 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 14:41:27 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_freetab(char **tab);
int		ft_export(char ***envp, char ***locals, char **argv);
char	**init_envp(char **envp);
char	**init_locals(void);
void	ft_showtab(char **tab);
int		ft_assign(const char *s, char **envp, char **locals);

static int	myperror(const char *str)
{
	perror(str);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	**locals;
	int		r;

	(void)argc;
	locals = init_locals();
	if (!locals)
		return (myperror(argv[0]));
	envp = init_envp(envp);
	if (!envp)
	{
		ft_freetab(locals);
		return (myperror(argv[0]));
	}
	r = ft_assign(argv[0], &envp, &locals);
	ft_freetab(envp);
	ft_freetab(locals);
	return (r);
}
