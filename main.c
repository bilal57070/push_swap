/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:31:48 by mirio             #+#    #+#             */
/*   Updated: 2024/01/23 16:36:20 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nbr	nbr;

	if (ac == 1)
	{
		ft_printf("error\n");
		return (1);
	}
	nbr.pileb = NULL;
	checkav(av);
	putrav(&nbr, av);
	puttab(&nbr);
	checkdoub(&nbr);
	ft_lstput2(&nbr);
	checkmax(&nbr, av);
	if (begin(&nbr))
		return (0);
	else if (nbr.lenstr == 2)
		sa(nbr.lst);
	else
	{
		sorttab(&nbr);
		sort(&nbr);
	}
	free_all(&nbr);
}
