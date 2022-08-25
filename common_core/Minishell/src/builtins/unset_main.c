/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:12:54 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/15 17:12:30 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_unset(char ***envp, char ***locals, char **argv);
void	ft_freetab(char **tab);
char	**init_envp(char **envp);
char	**init_locals(void);

static int	myperror(const char *s)
{
	perror(s);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	**locals;
	int		r;

	(void)argc;
	envp = init_envp(envp);
	if (!envp)
		return (myperror("unset: "));
	locals = init_locals();
	if (!locals)
	{
		ft_freetab(envp);
		return (myperror("unset: "));
	}
	r = ft_unset(&envp, &locals, argv);
	if (r == -1)
	{
		ft_freetab(envp);
		ft_freetab(locals);
		return (myperror("unset: "));
	}
	ft_freetab(envp);
	ft_freetab(locals);
	return (r);
}
