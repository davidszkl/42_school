/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_empty_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:36:22 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/23 11:39:02 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t	get_envp_size(char **envp);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(const char *s, int fd);
void	ft_freetab(char **tab);
int		check_and_free(char **tab, size_t l);
size_t	ft_strlen(const char *s);

static char	*my_strdup(const char *s)
{
	int				j;
	size_t			i;
	const size_t	l = ft_strlen(s) + 2;
	char			*r;

	r = malloc(l + 1);
	if (!r)
		return (0);
	r[l] = 0;
	r[l - 1] = '"';
	i = -1;
	j = 0;
	while (++i < l - 1)
	{
		if (s[i] == '=')
		{
			r[i] = '=';
			r[++i] = '"';
			j++;
			continue ;
		}
		r[i] = s[i - j];
	}
	return (r);
}

static void	str_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

static void	tab_sort(char **tab)
{
	const size_t	l = get_envp_size(tab);
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < l)
	{
		j = -1;
		while (++j < l - 1)
		{
			if (ft_strncmp(tab[j], tab[j + 1], -1) > 0)
				str_swap(&tab[j], &tab[j + 1]);
		}
	}
}

static char	**tab_dup_sort(char **tab)
{
	size_t			i;
	const size_t	l = get_envp_size(tab);
	char			**r;

	r = malloc((l + 1) * sizeof(char *));
	if (!r)
		return (0);
	i = -1;
	while (++i < l)
		r[i] = my_strdup(tab[i]);
	r[l] = 0;
	if (!check_and_free(r, l))
		return (0);
	tab_sort(r);
	return (r);
}

int	print_empty_export(char **envp, char **argv)
{
	size_t	i;
	char	**tab;

	if (argv[1])
		return (0);
	tab = tab_dup_sort(envp);
	if (!tab)
	{
		perror("minishell: malloc");
		return (0);
	}
	i = -1;
	while (tab[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
	}
	ft_freetab(tab);
	return (1);
}
