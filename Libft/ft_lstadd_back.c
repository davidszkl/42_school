#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = *alst;
	while(last && last->next)
		last = last->next;
	if (last)
		last->next = new;
	else
		*alst = new;
}