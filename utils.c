
#include "push_swap.h"

t_liste	*ft_lstad_backB(t_liste *target, t_liste *take)
{
	t_liste	*last;

	if (target)
	{
		last = ft_lstlastB(target);
		last->next = take;
		last = last->next;
		return (last);
	}
	else
		target = take;
	ft_printf("take2 : %d\n", take->num);
	ft_printf("pileb : %d\n", target->num);
	return (target);
}

t_liste	*ft_lstadd_frontB(t_liste *lst, t_liste *new)
{
	new->next = lst;
	lst = new;
	return (lst);
}

t_liste	*ft_lstlastB(t_liste *iter)
{
	while (iter)
	{
		if (!iter->next)
			return (iter);
		iter = iter->next;
	}
	return (iter);
}
