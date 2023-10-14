/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:49:20 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/17 13:52:07 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_cd(char ***envp, char **argv);
char	**init_envp(char **envp);
void	*exec_perror(const char *str);
void	ft_freetab(char **tab);

int	main(int argc, char **argv, char **envp)
{
	int	r;

	(void)argc;
	envp = init_envp(envp);
	if (!envp)
		return ((int)exec_perror("init_envp") + 1);
	r = ft_cd(&envp, argv);
	ft_freetab(envp);
	return (r);
}
