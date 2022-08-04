#include "../inc/ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	n;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	n = ft_strlen(str);
	write(1, str, n);
	return (n);
}

int	ft_putnbr(long int n)
{
	long int	nbr;
	int			j;

	nbr = n;
	j = 1;
	if (nbr < 0)
	{
		j += ft_putchar('-');
		nbr *= -1;
	}
	n = nbr;
	while (nbr > 9)
	{
		nbr /= 10 ;
		j++;
	}
	while (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	return (j);
}

int	ft_puthex(unsigned long int n, char *str)
{
	unsigned long int	nbr;
	int					j;

	j = 1;
	nbr = n;
	while (nbr > 15)
	{
		j++;
		nbr /= 16;
	}
	while (n > 15)
	{
		ft_puthex(n / 16, str);
		n %= 16;
	}
	ft_putchar(str[n]);
	return (j);
}

int	ft_putpointer(unsigned long int n, char *str)
{
	unsigned long int	nbr;
	int					j;

	j = 1;
	nbr = n;
	j += ft_putstr("0x");
	while (nbr > 15)
	{
		j++;
		nbr /= 16;
	}
	while (n > 15)
	{
		ft_puthex(n / 16, str);
		n %= 16;
	}
	ft_putchar(str[n]);
	return (j);
}
