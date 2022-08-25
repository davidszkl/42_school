/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:14:29 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/14 17:14:30 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*Includes*/

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

/*Functions*/

int	ft_printf(const char *str, ...);
int	ft_read(const char *str, va_list list);
int	ft_put(char c, va_list list);

/*Put-functions*/

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long int n);
int	ft_putuint(unsigned long int n);
int	ft_puthex(unsigned long int n, char *str);
int	ft_putpointer(unsigned long int n, char *str);

/*Utils*/

int	ft_strlen(char *str);

#endif
