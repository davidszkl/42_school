/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_export_args_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefevre <mlefevre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:54:35 by mlefevre          #+#    #+#             */
/*   Updated: 2021/11/22 15:02:42 by mlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_export_arg(const char *s);

static int	has_c(const char *str, char c)
{
	str--;
	while (*++str)
		if (*str == c)
			return (1);
	return (0);
}

int	is_valid_export_args_2(const char *s)
{
	return (is_valid_export_arg(s) && has_c(s, '='));
}
