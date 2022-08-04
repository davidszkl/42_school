#include "../inc/ft_printf.h"

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_putuint(unsigned long int n)
{
	unsigned long int	nbr;
	int				j;

	nbr = n;
	j = 1;
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
