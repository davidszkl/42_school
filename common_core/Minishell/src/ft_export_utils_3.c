/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:44:56 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/15 15:49:28 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_name(const char *str);
char	*get_value(const char *str);

char	*assign_name(char **name_value, char **argv)
{
	name_value[0] = get_name(*argv);
	return (name_value[0]);
}

char	*assign_value(char **name_value, char **argv)
{
	name_value[1] = get_value(*argv);
	return (name_value[1]);
}
