/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:05:55 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/23 10:44:12 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	get_envp_size(char **envp);
char	*ft_strdup(const char *s1);
void	ft_freetab(char **tab);
char	*ft_strjoin(const char *s1, const char *s2);
int		envp_assign(char *name, char *value, char ***envp_p);
int		del_in_envp(const char *name, char ***envp);
int		is_in_envp(const char *name, char **envp);
int		copy_to_envp(const char *name, char **locals, char ***envp_p);
int		is_valid_export_arg(const char *s);
int		my_putstr_fd(const char *s, int fd);
int		check_and_free(char **tab, size_t l);
char	*get_name(const char *str);
char	*get_value(const char *str);
char	*assign_name(char **name_value, char **argv);
char	*assign_value(char **name_value, char **argv);
int		print_empty_export(char **tab, char **argv);

int	envp_append(char *name, char *value, char ***envp)
{
	char			**tmp;
	char *const		str = ft_strjoin(name, "=");
	char			*str2;
	size_t			i;
	const size_t	l = get_envp_size(*envp);

	if (!str)
		return (0);
	str2 = ft_strjoin(str, value);
	free(str);
	if (!str2)
		return (0);
	tmp = malloc(sizeof(char *) * (l + 2));
	if (!tmp)
		return (0);
	i = -1;
	while (++i < l)
		tmp[i] = ft_strdup((*envp)[i]);
	tmp[i] = str2;
	tmp[i + 1] = 0;
	if (!check_and_free(tmp, l + 1))
		return (0);
	ft_freetab(*envp);
	*envp = tmp;
	return (1);
}

static int	free_2(void *a, void *b)
{
	free(a);
	free(b);
	return (1);
}

static int	my_putstr_fd_3(char *s1, char *s2, char *s3, int fd)
{
	my_putstr_fd(s1, fd);
	my_putstr_fd(s2, fd);
	my_putstr_fd(s3, fd);
	return (1);
}

int	ft_export(char ***envp, char ***locals, char **argv)
{
	char	*name_value[2];
	int		r;

	r = print_empty_export(*envp, argv) * 0;
	while (*++argv)
	{
		if (!is_valid_export_arg(*argv))
		{
			r = my_putstr_fd_3("export: `",
					*argv, "': not a valid identifier\n", 2);
			continue ;
		}
		if (!assign_name(name_value, argv))
			return (-1);
		if (!assign_value(name_value, argv) && !is_in_envp
			(name_value[0], *locals) && free_2(name_value[0], 0))
			continue ;
		if (is_in_envp(name_value[0], *locals) && (!copy_to_envp(name_value
					[0], *locals, envp) || !del_in_envp(name_value[0], locals)))
			return (-free_2(name_value[0], name_value[1]));
		if (name_value[1] && !envp_assign(name_value[0], name_value[1], envp))
			return (-free_2(name_value[0], name_value[1]));
		free_2(name_value[0], name_value[1]);
	}
	return (r);
}
