#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list **new_lst;
	t_list *temp;

	new_lst = malloc(sizeof(t_list *));
	if (!new_lst)
		return NULL;
	while (lst)
	{
		(*new_lst)->content = f(lst->content);
		if (del)
			del(lst->content);
		(*new_lst)->next = lst->next;
		lst = lst->next;
		temp = (*new_lst)->next;
	}
	return (*new_lst);
}