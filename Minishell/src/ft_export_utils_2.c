/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:43 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/11 16:37:00 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		get_envp_size(char **envp);
char		*ft_strdup(const char *s1);
void		ft_freetab(char **tab);
char		*ft_replace_str(const char *s, size_t start,
				size_t n, const char *sub);
int			envp_append(char *name, char *value, char ***envp);
int			is_in_envp(const char *name, char **envp);

int	envp_assign(char *name, char *value, char ***envp_p)
{
	char			**envp;
	char			*tmp;
	const size_t	l = ft_strlen(name);
	const int		b = is_in_envp(name, *envp_p);

	if (!b)
		return (envp_append(name, value, envp_p));
	envp = *envp_p;
	envp--;
	while (*++envp)
		if (!ft_strncmp(name, *envp, l) && (*envp)[l] == '=')
			break ;
	tmp = ft_replace_str(*envp, l + 1, ft_strlen(*envp) - l - 1, value);
	if (!tmp)
		return (0);
	free(*envp);
	*envp = tmp;
	return (1);
}

int	check_and_free(char **tab, size_t l)
{
	int		b;
	size_t	i;

	b = 1;
	i = -1;
	while (++i < l)
		b *= tab[i] != 0;
	if (b)
		return (1);
	i = -1;
	while (++i < l)
		free(tab[i]);
	free(tab);
	return (0);
}

int	copy_to_envp(const char *name, char **locals, char ***envp_p)
{
	size_t			i;
	char			**envp;
	const size_t	l = ft_strlen(name);

	locals--;
	while (*++locals)
		if (!ft_strncmp(name, *locals, l) && (*locals)[l] == '=')
			break ;
	if (!*locals)
		return (0);
	envp = malloc(sizeof(char *) * (get_envp_size(*envp_p) + 2));
	if (!envp)
		return (0);
	i = -1;
	while ((*envp_p)[++i])
		envp[i] = ft_strdup((*envp_p)[i]);
	envp[i] = ft_strdup(*locals);
	envp[i + 1] = 0;
	if (!check_and_free(envp, get_envp_size(*envp_p) + 1))
		return (0);
	ft_freetab(*envp_p);
	*envp_p = envp;
	return (1);
}

int	del_in_envp(const char *name, char ***envp)
{
	char			**tmp;
	size_t			i;
	int				j;
	const size_t	l = get_envp_size(*envp);
	const size_t	l2 = ft_strlen(name);

	tmp = malloc(sizeof(char *) * l);
	if (!tmp)
		return (0);
	i = -1;
	j = 0;
	while (++i < l)
	{
		if (!(!ft_strncmp(name, (*envp)[i], l2) && (*envp)[i][l2] == '='))
			tmp[i + j] = ft_strdup((*envp)[i]);
		else
			j = -1;
	}
	tmp[i + j] = 0;
	if (!check_and_free(tmp, l - 1))
		return (0);
	ft_freetab(*envp);
	*envp = tmp;
	return (1);
}
