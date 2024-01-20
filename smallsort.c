/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:44 by mirio             #+#    #+#             */
/*   Updated: 2024/01/19 18:35:29 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small3(t_nbr *nbr)
{
	int	first;
	int	second;
	int	third;

	first = nbr->lst->index;
	second = nbr->lst->next->index;
	third = nbr->lst->next->next->index;
	if (second < first && first < third)
		sa(nbr->lst);
	else if (first < second && third < first)
		rra(nbr);
	else if (first > second && second > third)
	{
		sa(nbr->lst);
		rra(nbr);
	}
	else if (first < second && second > third)
	{
		rra(nbr);
		sa(nbr->lst);
	}
	else if (first > second && second < third)
		ra(nbr);
}

void	small4(t_nbr *nbr)
{
	int	first;

	first = nbr->lst->index;
	while (first != 0)
	{
		ra(nbr);
		first = nbr->lst->index;
	}
	pb(nbr);
	small3(nbr);
	pa(nbr);
}

void	small5(t_nbr *nbr)
{
	int	first;

	first = nbr->lst->index;
	while (first != 0)
	{
		ra(nbr);
		first = nbr->lst->index;
	}
	pb(nbr);
	first = nbr->lst->index;
	while (first != 1)
	{
		ra(nbr);
		first = nbr->lst->index;
	}
	pb(nbr);
	small3(nbr);
	pa(nbr);
	pa(nbr);
}

void	radix(t_nbr *nbr)
{
	int	tmp;
	int	mask;
	int	i;
	int	j;

	i = -1;
	nbr->a = 0;
	ned(nbr);
	while (++i < nbr->lenbits)
	{
		j = -1;
		while (++j < nbr->len)
		{
			mask = 1 << i;
			tmp = nbr->lst->index;
			nbr->a = (tmp & mask);
			if (nbr->a == 0)
				pb(nbr);
			else
				ra(nbr);
		}
		while (nbr->pileb)
			pa(nbr);
	}
}

void	ned(t_nbr *nbr)
{
	nbr->lenbits = 0;
	while ((nbr->len - 1) >> nbr->lenbits != 0)
		nbr->lenbits++;
}
