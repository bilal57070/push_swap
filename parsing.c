/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:28 by mirio             #+#    #+#             */
/*   Updated: 2023/12/04 16:49:34 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkmax(t_nbr *nbr, char **av)
{
	int	i;

	i = -1;
	while (nbr->tab[++i])
	{
		if (nbr->tab[i] <= INT_MIN || nbr->tab[i] >= INT_MAX)
		{
			ft_printf("Error max\n");
			exit(1);
		}
	}
	lenarg(nbr, av);
	return (0);
}

int	checkav(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j != 0 && av[i][j] == '-' && av[i][j - 1] != ' ')
			{
				ft_printf("error\n un - perdu");
				exit(1);
			}
			if (av[i][j] != '-' && av[i][j] != ' ' &&
			(!(av[i][j] >= '0' && av[i][j] <= '9')))
			{
				ft_printf("Error\n caractere perdu");
				exit(1);
			}
		}
	}
	return (0);
}

/*void    checker(t_nbr *nbr, char **av)
{
    if (nbr->lenstr == 1)
    {
        checkdoub1(nbr, av);
    }
    else
        checkdoub2(nbr, av);
}*/

int	checkdoub1(t_nbr *nbr)
{
	int	i;
	int	p;

	i = -1;
	p = 0;
	nbr->o = 0;
	nbr->len = lenr(nbr->r);
	nego(nbr, i, p);
	if (nbr->o > nbr->len)
	{
		ft_printf("error: doublon nombre r\n");
		exit(1);
	}
	return (0);
}

void	nego(t_nbr *nbr, int i, int p)
{
	int	res;
	int	j;

	while (nbr->r[++i])
	{
		j = -1;
		res = 0;
		while (nbr->r[i][++j] != '\0')
		{
			res = ft_strcmp(nbr->r[i], nbr->r[p]);
			if (nbr->r[p][j + 1] == '\0' && res == 0)
				nbr->o++;
		}
		if (nbr->r[i + 1] == NULL && nbr->r[p + 1] != NULL)
		{
			i = 0;
			p++;
		}
	}
}

/* if j = p av[i][j++] tant que != ' '*/

/*int	checkdoub2(t_nbr *nbr, char **av)
{
	int	i;
	int	j;
	int	p;
	int	res;
	int	o;

	i = 0;
	p = 1;
	o = 0;
	while (av[++i])
	{
		j = -1;
		res = 0;
		while (av[i][++j] != '\0')
		{
			res = ft_strcmp(av[i], av[p]);
			if (av[p][j + 1] == '\0' && res == 0)
				o++;
		}
		if (av[i + 1] == '\0' && av[p + 1] != '\0')
		{
			i = 0;
			p++;
		}
	}
	if (o > nbr->lenstr)
	{
		ft_printf("error: doublon nbr\n");
		return (1);
	}
	return (0);
}*/

void	lenarg(t_nbr *nbr, char **av)
{
	int	i;

	i = 0;
	nbr->lenstr = 0;
	while (av[++i])
		nbr->lenstr++;
}

/*void    stockarg(t_nbr *nbr, char **av)
{
    int i;
    int j;

    i = 0;
    while (av[++i])
    {
        nbr->sto = ft_split(av[i], ' ');
    }
    int k;
    k = -1;
    while (nbr->sto[++k])
    {
        ft_printf("nombre: %s\n", nbr->sto[k]);
    }
}*/
/*void     lenchar(t_nbr *nbr, char **av)
{
    int i;
    int j;

    i = 0;
    while (av[++i])
    {
        while (av[i][++j])
            nbr->lenchar++;
    }
    lenarg(nbr, av);
}*/

/*void    stock(t_nbr *nbr, char **av)
{
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    lenarg(nbr, av);
    nbr->tab = malloc(sizeof(int) * (nbr->lenstr));
    if (!nbr->tab)
        return (0);
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            while (av[i][j] != ' ' && av[i][j] != '\0')
            {
                nbr->tab[k] = atoi(av[i][j]);
                j++;
            }
        }
        k++;
    }
    while(nbr->tab[++k])
    {
        ft_printf("nbr : %d", nbr->tab[k]);
    }
}*/

/*int	count(char **av)
{
	size_t	i;
    size_t  j;
	size_t	w;

	i = 0;
	w = 0;
	while (av[++i])
	{
        j = -1;
        while (av[i][++j])
        {
            w++;
        }
	}
	return (w);
}

char	**ft_splite(t_nbr *nbr, char **av)
{
	int		i;
	int		j;
    int     k;

	i = 0;
    k = 0;
	if (!av)
		return (0);
	nbr->sto = malloc(sizeof(char *) * (count(av) + 1));
	if (!nbr->sto)
		return (0);
	while (av[++i])
	{
        j = -1;
        nbr->sto[k] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		while (av[i][++j])
        {
            nbr->sto[k][j] = av[i][j];
        }
        k++;
	}
	nbr->sto[k] = 0;
    int p;
    p = -1;
    while(nbr->sto[++p])
    {
        ft_printf("nbr : %s\n", nbr->sto[p]);
    }
	return (nbr->sto);
}*/

/*calculez taille arg pour malloc tab int ensuite stockez arg dans tab*/

/* list ou tab de int = atoi(r[k++])*/

/*void    checklet(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            if ((av[i][j] != '-' && (!(av[i][j] >= '0' && av[i][j] <= '9'))))
            {
                ft_printf("sale chien caractere inattendu");
                return(1);
            }
        }
    }
}*/

/* jsp pk mais le exit(1) ne fait pas son taff go essayer de trouver 
pk et comment installer le exit(failure)*/
