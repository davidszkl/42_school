/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:51:08 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/24 11:17:43 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/minishell.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

int		envp_assign(char *name, char *value, char ***envp_p);
int		is_in_envp(const char *name, char **envp);
char	*get_envp_val(const char *name, char **envp);

static void	*exec_perror_cd(const char *s)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(": cd: ", 2);
	perror(s);
	return (0);
}

static int	cd_error_m(void)
{
	ft_putstr_fd(ERROR, 2);
	ft_putstr_fd(": cd: HOME not set\n", 2);
	return (1);
}

static int	handle_home(char **envp)
{
	int		r;
	char	*tmp;

	tmp = get_envp_val("HOME", envp);
	if (!tmp)
		return (-1);
	r = chdir(tmp);
	free(tmp);
	return (r);
}

static int	perror_invalid_home(char **envp)
{
	char	*tmp;

	tmp = get_envp_val("HOME", envp);
	if (!tmp)
		return (1);
	exec_perror_cd(tmp);
	free(tmp);
	return (1);
}

int	ft_cd(char ***envp, char **argv)
{
	char	pwd[MAXPATHLEN + 1];
	char	old_pwd[MAXPATHLEN + 1];
	int		r;

	getcwd(old_pwd, MAXPATHLEN + 1);
	if (argv[1])
		r = chdir(argv[1]);
	else if (is_in_envp("HOME", *envp))
		r = handle_home(*envp);
	else
		return (cd_error_m());
	if (r == -1 && argv[1])
		return (*(int*)exec_perror_cd(argv[1]) + 1);
	else if (r == -1)
		return (perror_invalid_home(*envp));
	getcwd(pwd, MAXPATHLEN + 1);
	if (!envp_assign("OLD_PWD", old_pwd, envp))
		return (*(int*)exec_perror_cd("envp_assign") + 1);
	if (!envp_assign("PWD", pwd, envp))
		return (*(int*)exec_perror_cd("envp_assign") + 1);
	return (0);
}
