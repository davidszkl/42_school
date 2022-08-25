#include <stdlib.h>
#include "libft.h"
static int	num_of_char(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	num;
	char			*buffer;

	buffer = (char *)malloc(num_of_char(n) + 1);
	if (buffer == NULL)
		return (0);
	i = num_of_char(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		buffer[0] = '-';
	}
	buffer[i] = 0;
	buffer[i - 1] = '0';
	while (num > 0)
	{
		i--;
		buffer[i] = num % 10 + 48;
		num /= 10;
	}
	return (buffer);
}
