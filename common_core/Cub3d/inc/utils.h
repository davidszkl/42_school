/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:56:08 by dszklarz          #+#    #+#             */
/*   Updated: 2021/12/01 10:56:09 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

/*includes*/

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*utils*/

size_t	ft_strlen(char *str);
void	my_perror(char *tmp);
char	**ft_tabcpy(char **tab);
char	*ft_getword_simple(char *str, int n);
char	*ft_strdup_fill(char *str, size_t l, char fill);
char	*ft_strdup(char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi_mod(char *str, int *modify);
int		ft_get_2nd_word_index(char *line);
int		ft_putstr_fd(char *s, int fd);
int		ft_get_gnl_len(char *file);
int		ft_is_empty(char *line);
int		ft_tablen(char **tab);
int		ft_is_news(char c);
int		ft_isspace(char c);
int		ft_isprint(char c);
int		ft_isdigit(char c);

#endif