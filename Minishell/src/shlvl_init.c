/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:39:04 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/24 11:01:38 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/minishell.h"

int		is_in_envp(const char *name, char **envp);
char	*get_envp_val(const char *name, char **envp);
char	*envp_assign(const char *name, const char *val, char ***envp);
char	*ft_itoa(int n);
int		ft_atoi(const char *s);

static int	ft_freetab2(char **tab1, char **tab2, char *str)
{
	ft_freetab(tab1);
	ft_freetab(tab2);
	free(str);
	return (1);
}

int	shlvl_init(t_main *main)
{
	char	*tmp;
	char	*tmp2;

	if (!is_in_envp("SHLVL", main->envp))
	{
		if (!envp_assign("SHLVL", "1", &(main->envp)))
			return (0 * ft_freetab2(main->envp, main->locals, 0));
		return (1);
	}
	tmp = get_envp_val("SHLVL", main->envp);
	if (!tmp)
		return (0 * ft_freetab2(main->envp, main->locals, 0));
	tmp2 = ft_itoa(ft_atoi(tmp) + 1);
	free(tmp);
	if (!tmp2)
		return (0 * ft_freetab2(main->envp, main->locals, 0));
	if (!envp_assign("SHLVL", tmp2, &(main->envp)))
		return (0 * ft_freetab2(main->envp, main->locals, tmp2));
	free(tmp2);
	return (1);
}
