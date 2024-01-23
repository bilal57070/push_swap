/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:50 by mirio             #+#    #+#             */
/*   Updated: 2024/01/23 17:02:40 by mirio            ###   ########.fr       */
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

int	begin(t_nbr *nbr)
{
	t_liste	*tmp;
	t_liste	*tmp2;

	tmp2 = nbr->lst;
	while (tmp2)
	{
		tmp = tmp2->next;
		while (tmp)
		{
			if (tmp2->num > tmp->num)
				return (0);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	ft_lstfree(nbr);
	free(nbr->tab);
	free_tab(nbr->r);
	return (1);
}

void	puttab(t_nbr *nbr)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	lenr(nbr);
	nbr->tab = malloc(sizeof(long int) * nbr->len);
	while (nbr->r[++i])
	{
		nbr->tab[j] = ft_atoi(nbr->r[i]);
		j++;
	}
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

/*void	printab(t_nbr *nbr)
{
    int i;

    i = -1;
    while (nbr->tab[++i])
        ft_printf("TAB = %d\n", nbr->tab[i]);
}*/

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