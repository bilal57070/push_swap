/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:50 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 18:33:25 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    tri(t_nbr *nbr, char **av)
{
    if (nbr->lenstr > 1)
    {
        nbr->tab = malloc(sizeof(int) * nbr->lenstr + 1);
        puttab(nbr, av);
    }
    else
    {
        nbr->tab = malloc(sizeof(int) * nbr->len + 1);
        puttab(nbr, nbr->r);
    }
}*/

void	puttab(t_nbr *nbr)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	nbr->tab = malloc(sizeof(int) * nbr->len + 1);
	while (nbr->r[++i])
	{
		nbr->tab[j] = ft_atoi(nbr->r[i]);
		j++;
	}
	nbr->tab[i] = 0;
}

/*void    sorttab1(t_nbr *nbr)
{
    if (nbr->lenstr > 1)
    {
        sorttab(nbr, nbr->lenstr);
    }
    else
    {
        sorttab(nbr, nbr->len);
    }
}*/

void	sorttab(t_nbr *nbr)
{
	int	i;
	int	tri;

	i = 0;
	while (i < nbr->len - 1)
	{
		if (nbr->tab[i] > nbr->tab[i + 1])
		{
			tri = nbr->tab[i];
			nbr->tab[i] = nbr->tab[i + 1];
			nbr->tab[i + 1] = tri;
			i = 0;
		}
		else
			i++;
	}
	indexing(nbr);
}

void	indexing(t_nbr *nbr)
{
	t_liste	*tmp;
	int		i;

	i = 0;
	tmp = nbr->lst;
	while (tmp)
	{
		if (tmp->num == nbr->tab[i])
		{
			tmp->index = i;
			tmp = tmp->next;
			i = -1;
		}
		i++;
	}
	tmp = nbr->lst;
}

void	sort(t_nbr *nbr)
{
	if (nbr->len == 3)
		small3(nbr);
	else if (nbr->len == 4)
		small4(nbr);
	else if (nbr->len == 5)
		small5(nbr);
	else
		radix(nbr);
}

//if 0 pb, remettre la liste au pointeur de depart, pa,