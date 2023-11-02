/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirio <mirio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:37:30 by mirio             #+#    #+#             */
/*   Updated: 2023/11/02 19:08:52 by mirio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/inc/get_next_line.h"
# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"

int			checkav(char **av);
void		checklet(char **av);

typedef struct list
{
	long		num;
	int			index;
	struct list	*next;
}				t_liste;

typedef struct s_nbr
{
	int		*tab;
	int		lenstr;
	char	**r;
	int		ar;
	int		len;
	int		o;
	int		a;
	int		lenbits;
	t_liste	*lst;
	t_liste	*pileb;
}			t_nbr;

int			checkmax(t_nbr *nbr, char **av);
void		lenarg(t_nbr *nbr, char **av);
int			ft_strcmp(const char *s1, const char *s2);
int			lenr(char **str);
int			checkdoub1(t_nbr *nbr);
void		nego(t_nbr *nbr, int i, int p);
void		ft_lstiiter(t_liste *lst);
t_liste		*ft_lstput2(t_nbr *nbr);
int			sa(t_liste *lst);
t_liste		*ft_lstad_backb(t_liste *target, t_liste *take);
t_liste		*ft_lstadd_frontb(t_liste *lst, t_liste *new);
int			pb(t_nbr *nbr);
t_liste		*ft_lstlastb(t_liste *iter);
int			ss(t_liste *lst, t_liste *pileB);
int			ra(t_nbr *nbr);
int			pa(t_nbr *nbr);
int			rb(t_nbr *nbr);
void		rr(t_nbr *nbr);
int			rra(t_nbr *nbr);
int			rrb(t_nbr *nbr);
void		rrr(t_nbr *nbr);
void		tri(t_nbr *nbr, char **av);
void		puttab(t_nbr *nbr);
void		sorttab1(t_nbr *nbr);
void		sorttab(t_nbr *nbr);
char		**strjoin2(char **s1, char **s2);
void		temp(char **s1, char **s2, char **str);
void		putrav(t_nbr *nbr, char **av);
void		free_tab(char **str);
void		indexing(t_nbr *nbr);
void		small3(t_nbr *nbr);
void		small4(t_nbr *nbr);
void		sort(t_nbr *nbr);
void		radix(t_nbr *nbr);
void		ned(t_nbr *nbr);
void		small5(t_nbr *nbr);

#endif