#include "libft.h"
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{	
	unsigned int	n;

	n = 0;
	if (!s || !f)
		return ;
	while (s[n])
	{
		f(n, &s[n]);
		n++;
	}
}
