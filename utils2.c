
#include "push_swap.h"


char	**strjoin2(char **s1, char **s2)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
    while (s1[i])
        i++;
	if (!s2)
		return (s1);
    while (s2[j])
        j++;
	str = malloc(sizeof(char *) * (i + j + 1));
	if (!str)
		return (0);
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
	return (str);
}

void	putrav(t_nbr *nbr, char **av)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	nbr->r = ft_split(av[1], ' ');
	while (av[++i])
	{
		tmp = ft_split(av[i], ' ');
		//ft_printf("test\n");
		nbr->r = strjoin2(nbr->r, tmp);
	}
	//j = -1;
	//while (nbr->r[++j])
		//ft_printf(" oe : %s\n", nbr->r[j]);
}

void	free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}