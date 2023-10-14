/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:58:35 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 15:25:27 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "../inc/expand_variables_args.h"

int		is_in_dquotes(const char *str, size_t i);
char	*ft_itoa(int n);

/*
Returns value of environment
variable name in envp NULL in
case of error.
*/
char	*get_envp_val(const char *name, char **envp)
{
	int	l;

	if (!envp || !name)
		return (0);
	l = ft_strlen(name);
	while (*envp)
	{
		if (!ft_strncmp(name, *envp, l) && (*envp)[l] == '=')
			return (ft_substr(*envp, l + 1, ft_strlen(*envp + l + 1)));
		envp++;
	}
	return (0);
}

static char	*replace_str(const char *s, size_t start, size_t n, const char *sub)
{
	size_t			i;
	const size_t	sl = ft_strlen(sub);
	const size_t	l = ft_strlen(s) - n + sl;
	char *const		tmp = malloc(l + 1);

	if (!tmp)
		return (0);
	i = -1;
	while (++i < start)
		tmp[i] = s[i];
	i--;
	while (++i < start + sl)
		tmp[i] = sub[i - start];
	i--;
	while (++i < l)
		tmp[i] = s[i - sl + n];
	tmp[i] = 0;
	return (tmp);
}

static int	expand_variables_2(char **s, size_t *i, char **envp, char **locals)
{
	t_expand_variables_2_args	args;

	args.tmp1 = ft_substr(*s, *i + 1, var_len(&(*s)[*i + 1]));
	if (!args.tmp1)
		return ((int)free_4(s, 0, 0, 0));
	args.tmp2 = get_envp_val(args.tmp1, envp);
	if (!args.tmp2 && locals)
		args.tmp2 = get_envp_val(args.tmp1, locals);
	free(args.tmp1);
	if (!args.tmp2)
	{
		args.t = replace_str(*s, *i, var_len(&(*s)[*i + 1]) + 1, "");
		free(*s);
		*s = args.t;
		if (!*s)
			return (0);
		return (1);
	}
	args.t = replace_str(*s, *i, var_len(&(*s)[*i + 1]) + 1, args.tmp2);
	free(*s);
	*s = args.t;
	if (!*s)
		return ((int)free_4(args.tmp2, 0, 0, 0));
	return ((int)free_4(args.tmp2, 0, 0, 0) + 1);
}

static int	expand_variables_3(char **s, size_t *i, int ret)
{
	char	*n;
	char	*t;

	n = ft_itoa(ret);
	if ((*s)[*i + 1] == '?')
	{
		if (!n)
		{
			free(*s);
			return (0);
		}
		t = replace_str(*s, *i, 2, n);
	}
	else
		t = replace_str(*s, *i, 2, "");
	free(*s);
	free(n);
	*s = t;
	if (!*s)
		return (0);
	return (1);
}

/*
Returns new string with all variables
in s expanded. NULL in case of error.
(envp for exported variables, locals for the rest)
*/
char	*expand_variables(const char *str, char **envp, char **locals, int ret)
{
	t_expand_variables_args	args;

	if (!str)
		return (0);
	args = init_args(str);
	if (!args.s)
		return (free_4(args.s, 0, 0, 0));
	while (++args.i < ft_strlen(args.s))
	{
		if (args.s[args.i] == '\'' && !is_in_dquotes(args.s, args.i))
			args.is_in_quote = !args.is_in_quote;
		if (args.is_in_quote)
			continue ;
		if (args.s[args.i] == '$' && (args.s[args.i + 1] == '?'
				|| ft_isdigit(args.s[args.i + 1])))
		{
			if (!expand_variables_3(&args.s, &args.i, ret))
				return (0);
		}
		else if (args.s[args.i] == '$' && (args.s[args.i + 1] == '_'
				|| ft_isalpha(args.s[args.i + 1])))
			if (!expand_variables_2(&args.s, &args.i, envp, locals))
				return (0);
	}
	return (args.s);
}
