
#include "push_swap.h"

int     small3(t_nbr *nbr)
{
    int first;
    int second;
    int third;

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
    return (0);
}

int     small4(t_nbr *nbr)
{
    int first;

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

int     small5(t_nbr *nbr)
{
    int first;

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

void    radix(t_nbr *nbr)
{
    int tmp;
    int mask;
    int lenbits;
    int i;
    int j;
    int a;

    lenbits = 0;
    while ((nbr->len - 1) >> lenbits != 0)
        lenbits++;
    i = -1;
    a = 0;
    /*tmp = nbr->lst->next->index;
    a = (tmp & mask);
    ft_printf("a = %d\n", a);*/
    while (++i < lenbits)
    {
        j = -1;
        while (++j < nbr->len)
        {
            mask = 1 << i;
            tmp = nbr->lst->index;
            ft_printf("tmp = %d\n", tmp);
            a = (tmp & mask);
            ft_printf("a = %d\n", a);
            if (a == 0)
                pb(nbr);
            else
                ra(nbr);
        }
        //ft_lstiiter(nbr->pileB);
        while (nbr->pileB)
            pa(nbr);
    }
    //ft_lstiiter(nbr->lst);
}

void    sort(t_nbr *nbr)
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