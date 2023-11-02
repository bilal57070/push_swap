/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:31:40 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 18:32:29 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_liste *lst)
{
	t_liste	*first;
	t_liste	*second;
	int		tmp;

	first = lst;
	second = first->next;
	tmp = second->num;
	second->num = first->num;
	first->num = tmp;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_liste *pileb)
{
	t_liste	*first;
	t_liste	*second;
	int		tmp;

	first = pileb;
	second = first->next;
	tmp = second->num;
	second->num = first->num;
	first->num = tmp;
	ft_printf("sb\n");
	return (0);
}

int	ss(t_liste *lst, t_liste *pileb)
{
	sa(lst);
	sb(pileb);
	return (0);
}

int	pb(t_nbr *nbr)
{
	t_liste		*push;

	if (!nbr->lst)
		return (0);
	push = nbr->lst;
	nbr->lst = nbr->lst->next;
	nbr->pileb = ft_lstadd_frontb(nbr->pileb, push);
	push = NULL;
	ft_printf("pb\n");
	return (0);
}

int	pa(t_nbr *nbr)
{
	t_liste		*push;

	if (!nbr->pileb)
		return (0);
	push = nbr->pileb;
	nbr->pileb = nbr->pileb->next;
	nbr->lst = ft_lstadd_frontb(nbr->lst, push);
	push = NULL;
	ft_printf("pa\n");
	return (0);
}
