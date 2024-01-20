/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:55 by mirio             #+#    #+#             */
/*   Updated: 2024/01/16 00:30:58 by mirio            ###   ########.fr       */
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

void	ft_lstfree(t_nbr *nbr)
{
	t_liste	*tmp;

	while (nbr->lst)
	{
		tmp = nbr->lst;
		nbr->lst = nbr->lst->next;
		if (tmp)
			free(tmp);
	}
}

void	rrr(t_nbr *nbr)
{
	rra(nbr);
	rrb(nbr);
}
