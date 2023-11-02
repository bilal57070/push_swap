/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:55 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 18:34:13 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*ft_lstad_backb(t_liste *target, t_liste *take)
{
	t_liste	*last;

	if (target)
	{
		last = ft_lstlastb(target);
		last->next = take;
		last = last->next;
		return (last);
	}
	else
		target = take;
	return (target);
}

t_liste	*ft_lstadd_frontb(t_liste *lst, t_liste *new)
{
	new->next = lst;
	lst = new;
	return (lst);
}

t_liste	*ft_lstlastb(t_liste *iter)
{
	while (iter)
	{
		if (!iter->next)
			return (iter);
		iter = iter->next;
	}
	return (iter);
}

void	rrr(t_nbr *nbr)
{
	rra(nbr);
	rrb(nbr);
}
