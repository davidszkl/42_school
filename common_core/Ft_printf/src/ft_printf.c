#include "../inc/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		n;

	va_start(list, str);
	n = ft_read(str, list);
	va_end(list);
	return (n);
}

int	ft_read(const char *str, va_list list)
{
	int	n;
	int	j;

	n = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '%')
		{
			n += ft_put(str[j + 1], list);
			j++;
		}
		else
			n += ft_putchar(str[j]);
		j++;
	}
	return (n);
}

int	ft_put(char c, va_list list)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_putchar(va_arg(list, int));
	else if (c == '%')
		n = ft_putchar('%');
	else if (c == 's')
		n = ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		n = ft_putnbr(va_arg(list, int));
	else if (c == 'u')
		n = ft_putuint(va_arg(list, unsigned int));
	else if (c == 'x')
		n = ft_puthex(va_arg(list, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		n = ft_puthex(va_arg(list, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		n = ft_putpointer(va_arg(list, unsigned long int), "0123456789abcdef");
	return (n);
}
