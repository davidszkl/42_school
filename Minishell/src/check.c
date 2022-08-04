/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:06:32 by dszklarz          #+#    #+#             */
/*   Updated: 2021/11/08 09:06:35 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	ft_check_cmd(char *str)
{
	if (ft_strncmp(ft_tolower(str), "echo", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(ft_tolower(str), "cd", ft_strlen(str)) == 0)
		return (2);
	else if (ft_strncmp(ft_tolower(str), "pwd", ft_strlen(str)) == 0)
		return (3);
	else if (ft_strncmp(ft_tolower(str), "export", ft_strlen(str)) == 0)
		return (4);
	else if (ft_strncmp(ft_tolower(str), "unset", ft_strlen(str)) == 0)
		return (5);
	else if (ft_strncmp(ft_tolower(str), "env", ft_strlen(str)) == 0)
		return (6);
	else if (ft_strncmp(ft_tolower(str), "exit", ft_strlen(str)) == 0)
		return (7);
	else
		return (0);
}

int	ft_check_echo(char *str)
{
	if (ft_strncmp(str, "-n", ft_strlen(str)) == 0)
		return (1);
	else
		return (0);
}
