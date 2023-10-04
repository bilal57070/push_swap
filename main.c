
#include "push_swap.h"

int main(int ac, char **av)
 {
    t_nbr nbr;
    t_liste *lst;

    if (ac == 1)
        return (1);
    nbr.pileB = NULL;
    checkav(av);
    checkmax(&nbr, av);
    //stockarg(&nbr, av);
    //ft_splite(&nbr, av);
    putrav(&nbr, av);
    checkdoub1(&nbr);
    ft_lstput2(&nbr);
    puttab(&nbr);
    sorttab(&nbr);
    sort(&nbr);
    ft_lstiiter(nbr.lst);
    //systemleaks("push_swap");
 }