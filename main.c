/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:31:48 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 19:11:36 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nbr	nbr;

	if (ac == 1)
		return (1);
	nbr.pileb = NULL;
	checkav(av);
	putrav(&nbr, av);
	checkdoub1(&nbr);
	ft_lstput2(&nbr);
	puttab(&nbr);
	checkmax(&nbr, av);
	sorttab(&nbr);
	sort(&nbr);
}
