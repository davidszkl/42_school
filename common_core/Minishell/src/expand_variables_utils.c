/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:17:19 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 15:25:25 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "../inc/expand_variables_args.h"

size_t	var_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || ft_isalpha(s[i]) || s[i] == '_'))
		i++;
	return (i);
}

void	*free_4(void *a, void *b, void *c, void *d)
{
	free(a);
	free(b);
	free(c);
	free(d);
	return (0);
}

t_expand_variables_args	init_args(const char *str)
{
	t_expand_variables_args	args;

	args.s = ft_strdup(str);
	free((void *)str);
	args.i = -1;
	args.is_in_quote = 0;
	return (args);
}

int	is_in_dquotes(const char *str, size_t i)
{
	int		b;
	int		b2;
	size_t	j;

	b2 = 0;
	b = 0;
	j = -1;
	while (++j < i)
	{
		if (str[j] == '"' && b2 == 0)
			b = !b;
		if (str[j] == '\'' && b == 0)
			b2 = !b2;
	}
	return (b);
}
