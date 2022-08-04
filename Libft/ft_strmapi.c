#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*nstr;

	if (!s || !f)
		return (NULL);
	n = 0;
	nstr = ft_strdup(s);
	if (!nstr)
		return (NULL);
	while (s[n])
	{
		nstr[n] = f(n, s[n]);
		n++;
	}
	return (nstr);
}
