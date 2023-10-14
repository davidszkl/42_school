/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:06:57 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/01 17:35:33 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

static void	*myfree(const void *ptr)
{
	free((void *)ptr);
	return (0);
}

static void	*free_spl(char **ptr)
{
	char **const	ptr2 = ptr;

	while (*ptr)
		free(*ptr++);
	free(ptr2);
	return (0);
}

static char	*get_path(char *envp[])
{
	envp--;
	while (*++envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5))
			continue ;
		return (ft_substr(*envp, 5, ft_strlen(*envp) - 5));
	}
	return (0);
}

char	*find_command(const char *command, char *envp[])
{
	char	**s;
	char	*p;
	char	*sub;
	size_t	i;

	command = ft_strjoin("/", command);
	if (!command || !envp)
		return (myfree(command));
	p = get_path(envp);
	s = ft_split(p, ':');
	free(p);
	if (!s)
		return (myfree(command));
	i = -1;
	while (s[++i])
	{
		sub = ft_strjoin(s[i], command);
		if (!sub)
			return (free_spl(s) + *(int*)myfree(command));
		if (!access(sub, F_OK))
			return (sub + *(int*)free_spl(s) + *(int*)myfree(command));
		free(sub);
	}
	return (free_spl(s) + *(int*)myfree(command));
}
