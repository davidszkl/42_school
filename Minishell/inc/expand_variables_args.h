/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables_args.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:17:36 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 15:25:11 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_VARIABLES_ARGS_H
# define EXPAND_VARIABLES_ARGS_H

typedef struct s_expand_variables_2_args {
	char	*tmp1;
	char	*tmp2;
	char	*t;

}	t_expand_variables_2_args;

typedef struct s_expand_variables_args {
	size_t	i;
	char	*s;
	int		is_in_quote;

}	t_expand_variables_args;

t_expand_variables_args	init_args(const char *str);
size_t					ft_strlen(const char *s);
size_t					var_len(const char *s);
void					*free_4(void *a, void *b, void *c, void *d);
char					*ft_strdup(const char *s);

#endif
