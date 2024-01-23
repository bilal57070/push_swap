/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:38 by mirio             #+#    #+#             */
/*   Updated: 2024/01/23 16:35:59 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_lstput(t_liste **lst, t_nbr *nbr, char **av)
{
    int i;
    t_liste *new;
    t_liste *prm;

    i = 0;
    if (nbr->lenstr > 1)
    {
        while (av[++i])
        {
            new = malloc(sizeof(t_liste));
            new->num = ft_atoi(av[i]);
            new->next = NULL;
            //lst = malloc(sizeof(int) * nbr->lenstr);
            //lst->num = ft_atoi(av[i]);
            if (i == 1)
            {
                prm = new;
            }
            ft_lstadd_back(lst, new);
            ft_printf("liste : %d\n", new->num);
        }
    }
    else
    {
        while (nbr->r[i])
        {
            lst = malloc(sizeof(int) * nbr->len);
            lst->num = ft_atoi(nbr->r[i]);
            ft_printf("liste : %d\n", lst->num);
            lst = lst->next;
            i++;
        }
    }
    ft_lstiiter(*lst);
}

t_liste     *ft_lstput(t_nbr *nbr, char **av)
{
    int i;
    t_liste *lst;
    t_liste *new;

    i = 0;
    lst = NULL;
    lst = malloc(sizeof(t_liste));
    if (nbr->lenstr > 1)
    {
        while (av[++i])
        {
            new = malloc(sizeof(t_liste));
            if (!new)
                return (0);
            new->num = ft_atoi(av[i]);
            ft_lstlast(lst);
            lst->next = new;
            new->next = NULL;
            ft_printf("lister = %d\n", lst->num);
        }
    }
    return (lst);
}*/

/*t_liste	*ft_lstput(t_nbr *nbr, char **av)
{
	t_liste	*new;
	t_liste	*current;

	new = NULL;
	current = NULL;
	nbr->pileb = NULL;
	nbr->lst = NULL;
	if (nbr->lenstr > 1)
		pls(nbr, av, new, current);
	else
		ft_lstput2(nbr);
	return (nbr->lst);
}

int	pls(t_nbr *nbr, char **av, t_liste *new, t_liste *current)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		new = malloc(sizeof(t_liste));
		if (!new)
			return (0);
		new->num = ft_atoi(av[i]);
		new->next = NULL;
		if (i == 1)
		{
			nbr->lst = new;
			current = new;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
	}
	return (0);
}*/

t_liste	*ft_lstput2(t_nbr *nbr)
{
	int		i;
	t_liste	*new;
	t_liste	*current;

	i = -1;
	while (nbr->r[++i])
	{
		new = malloc(sizeof(t_liste));
		if (!new)
			return (0);
		new->num = nbr->tab[i];
		new->next = NULL;
		if (i == 0)
		{
			nbr->lst = new;
			current = new;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
	}
	return (nbr->lst);
}

/*void	ft_lstiiter(t_liste *lst)
{
	while (lst)
	{
		ft_printf("lst : %d\n", lst->num);
		lst = lst->next;
	}
}*/

void	free_all(t_nbr *nbr)
{
	free(nbr->tab);
	free_tab(nbr->r);
	ft_lstfree(nbr);
}

void	lenr(t_nbr *nbr)
{
	int	i;

	i = -1;
	nbr->len = 0;
	while (nbr->r[++i])
		nbr->len++;
}

// RESOUDRE LEAK OU JSP VALGRIND SA GRAND MERE