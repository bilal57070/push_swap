/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:32:59 by mirio             #+#    #+#             */
/*   Updated: 2024/01/22 23:10:54 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**strjoin2(char **s1, char **s2)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (s1);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char *) * (i + j + 1));
	if (!str)
		return (0);
	temp(s1, s2, str);
	return (str);
}

void	temp(char **s1, char **s2, char **str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = ft_strdup(s1[i]);
	i = -1;
	while (s2[++i])
		str[j++] = ft_strdup(s2[i]);
	str[j] = 0;
	free_tab(s1);
	free_tab(s2);
}

void	putrav(t_nbr *nbr, char **av)
{
	int		i;
	char	**tmp;

	i = 1;
	nbr->r = ft_split(av[1], ' ');
	while (av[++i])
	{
		tmp = ft_split(av[i], ' ');
		nbr->r = strjoin2(nbr->r, tmp);
	}
}

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
