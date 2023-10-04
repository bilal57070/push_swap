
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

/*t_liste     *ft_lstput(t_nbr *nbr, char **av)
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

t_liste *ft_lstput(t_nbr *nbr, char **av)
{
    int i;
    //t_liste *lst;
    t_liste *new;
    t_liste *current;

    i = 0;
    //nbr->pileB = malloc(sizeof(t_liste));
    nbr->pileB = NULL;
    nbr->lst = NULL;
    if (nbr->lenstr > 1)
    {
        //nbr->lst = malloc(sizeof(t_liste));
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
            //ft_printf("Element de la liste = %d\n", new->num);
        }
        //pb(nbr);
        //pb(nbr);
        //rra(nbr);
        //sa(nbr->lst);
        //rb(nbr);
    }
    else
        nbr->lst = ft_lstput2(nbr);
    //ft_printf("index : %d\n", nbr->lst->index);
    //ft_lstiiter(nbr->lst);
    return (nbr->lst);
}

t_liste *ft_lstput2(t_nbr *nbr)
{
    int i;
    //t_liste *lst;
    t_liste *new;
    t_liste *current;

    i = -1;
    //lst = malloc(sizeof(t_liste));
    //if (!lst)
    //    return (0);
    while (nbr->r[++i])
    {
        new = malloc(sizeof(t_liste));
        if (!new)
            return (0);
        new->num = ft_atoi(nbr->r[i]);
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
        //ft_printf("Element de la liste = %d\n", new->num);
    }
    //pb(nbr);
    //pb(nbr);
    //pa(nbr);
    //pa(nbr);
    //ft_lstiiter(nbr->pileB);
    //rra(nbr);
    //ft_lstiiter(nbr->lst);
    return (nbr->lst);
}

void	ft_lstiiter(t_liste *lst)
{
	while (lst)
	{
		ft_printf("lst : %d\n", lst->num);
		lst = lst->next;
	}
}
