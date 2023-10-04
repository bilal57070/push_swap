
#include "push_swap.h"

int     sa(t_liste *lst)
{
    t_liste *first;
    t_liste *second;
    int     tmp;

    first = lst;
    second = first->next;
    tmp = second->num;
    second->num = first->num;
    first->num = tmp;

    ft_lstiiter(lst);
    ft_printf("sa\n");
    //ft_printf("la pile B : %d\n", pileB->num);
    return (0);
}

int     sb(t_liste *pileB)
{
    t_liste *first;
    t_liste *second;
    int     tmp;

    first = pileB;
    second = first->next;
    tmp = second->num;
    second->num = first->num;
    first->num = tmp;

    return (0);
}

int     ss(t_liste *lst, t_liste *pileB)
{
    sa(lst);
    sb(pileB);
    return (0);
}

int     pb(t_nbr *nbr)
{
    t_liste     *push;

    if (!nbr->lst)
        return (0);
    /*if (!nbr->pileB)
    {
        nbr->pileB = malloc(sizeof(t_liste));
        push = nbr->lst;
        nbr->lst = nbr->lst->next;
        nbr->pileB = push;
        return (0);
    }*/
    push = nbr->lst;
    nbr->lst = nbr->lst->next;
    //push->next = nbr->pileB;
    //nbr->pileB = push;
    nbr->pileB = ft_lstadd_frontB(nbr->pileB, push);
    push = NULL;
    ft_printf("pb\n");
    //ft_printf("la pile B : %d\n", nbr->pileB->num);
    //ft_lstiiter(nbr->pileB);
    return (0);
}

int     pa(t_nbr *nbr)
{
    t_liste    *push;

    if (!nbr->pileB)
        return (0);
    push = nbr->pileB;
    nbr->pileB = nbr->pileB->next;
    nbr->lst = ft_lstadd_frontB(nbr->lst, push);
    push = NULL;
    //ft_printf("la pile A : %d\n", nbr->lst->num);
    //ft_lstiiter(nbr->lst);
    ft_printf("pa\n");
    return (0);
}

int    ra(t_nbr *nbr)
{
    t_liste *rotate;
    t_liste *tmp;

    if (!nbr->lst)
        return (0);
    tmp = nbr->lst;
    rotate = ft_lstlastB(nbr->lst);
    rotate->next = tmp;
    tmp = tmp->next;
    nbr->lst = tmp;
    rotate = rotate->next;
    rotate->next = NULL;
    ft_printf("ra\n");
    //ft_printf("rotate\n");
    //ft_lstiiter(nbr->lst);
    return (0);
}

int    rb(t_nbr *nbr)
{
    t_liste *rotate;
    t_liste *tmp;

    if (!nbr->pileB)
        return (0);
    tmp = nbr->pileB;
    rotate = ft_lstlastB(nbr->pileB);
    rotate->next = tmp;
    tmp = tmp->next;
    nbr->pileB = tmp;
    rotate = rotate->next;
    rotate->next = NULL;
    ft_lstiiter(nbr->pileB);
    ft_printf("rb\n");
    return (0);
}

void    rr(t_nbr *nbr)
{
    ra(nbr);
    rb(nbr);
}

int     rra(t_nbr *nbr)
{
    t_liste *rotate;
    t_liste *tmp;

    if (!nbr->lst)
        return (0);
    rotate = ft_lstlastB(nbr->lst);
    tmp = nbr->lst;
    while (tmp->next != rotate)
        tmp = tmp->next;
    tmp->next = NULL;
    rotate->next = nbr->lst;
    nbr->lst = rotate;
    //ft_printf("tmp = %d\n", tmp->num);
    ft_printf("rra\n");
}

int     rrb(t_nbr *nbr)
{
    t_liste *rotate;
    t_liste *tmp;
    t_liste *two;

    if (!nbr->pileB)
        return (0);
    rotate = ft_lstlastB(nbr->pileB);
    tmp = nbr->pileB;
    while (tmp->next != rotate)
        tmp = tmp->next;
    tmp->next = NULL;
    rotate->next = nbr->pileB;
    nbr->pileB = rotate;
    ft_printf("tmp = %d\n", tmp->num);
    ft_printf("\n");
    ft_lstiiter(nbr->pileB);
}

void    rrr(t_nbr *nbr)
{
    rra(nbr);
    rrb(nbr);
}