/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:16:09 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 18:31:39 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_nbr *nbr)
{
	t_liste	*rotate;
	t_liste	*tmp;

	if (!nbr->lst)
		return (0);
	tmp = nbr->lst;
	rotate = ft_lstlastb(nbr->lst);
	rotate->next = tmp;
	tmp = tmp->next;
	nbr->lst = tmp;
	rotate = rotate->next;
	rotate->next = NULL;
	ft_printf("ra\n");
	return (0);
}

int	rb(t_nbr *nbr)
{
	t_liste	*rotate;
	t_liste	*tmp;

	if (!nbr->pileb)
		return (0);
	tmp = nbr->pileb;
	rotate = ft_lstlastb(nbr->pileb);
	rotate->next = tmp;
	tmp = tmp->next;
	nbr->pileb = tmp;
	rotate = rotate->next;
	rotate->next = NULL;
	ft_printf("rb\n");
	return (0);
}

void	rr(t_nbr *nbr)
{
	ra(nbr);
	rb(nbr);
}

int	rra(t_nbr *nbr)
{
	t_liste	*rotate;
	t_liste	*tmp;

	if (!nbr->lst)
		return (0);
	rotate = ft_lstlastb(nbr->lst);
	tmp = nbr->lst;
	while (tmp->next != rotate)
		tmp = tmp->next;
	tmp->next = NULL;
	rotate->next = nbr->lst;
	nbr->lst = rotate;
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_nbr *nbr)
{
	t_liste	*rotate;
	t_liste	*tmp;

	if (!nbr->pileb)
		return (0);
	rotate = ft_lstlastb(nbr->pileb);
	tmp = nbr->pileb;
	while (tmp->next != rotate)
		tmp = tmp->next;
	tmp->next = NULL;
	rotate->next = nbr->pileb;
	nbr->pileb = rotate;
	ft_printf("rrb\n");
	return (0);
}
