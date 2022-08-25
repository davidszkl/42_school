/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:12:36 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 15:04:15 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*get_name(const char *str);
char	*get_value(const char *str);
int		is_in_envp(const char *name, char **envp);
int		envp_assign(char *name, char *value, char ***envp);

int	ft_assign(const char *s, char ***envp, char ***locals)
{
	char	*name;
	char	*value;
	int		r;

	name = get_name(s);
	if (!name)
	{
		perror("malloc");
		return (1);
	}
	value = get_value(s);
	if (!value)
	{
		perror("malloc");
		free(name);
		return (1);
	}
	if (is_in_envp(name, *envp))
		r = !envp_assign(name, value, envp);
	r = !envp_assign(name, value, locals);
	free(name);
	free(value);
	return (r);
}
