/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dszklarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:34:11 by dszklarz          #+#    #+#             */
/*   Updated: 2021/10/18 11:10:38 by dszklarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*includes*/

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

/*structures*/

typedef struct s_3 {
	int	a;
	int	b;
	int	c;
}	t_3;

typedef struct s_big {
	int	*ind;
	int	max;
	int	maxbit;	
}	t_big;

typedef struct s_main {
	t_big	big;
	int		*a;
	int		*b;
	int		*sorted;
	int		count;
	int		alen;
	int		blen;
	int		zstk;
	int		zpos;
	int		status;
}	t_main;

/*functions*/

int		ft_init(t_main *main, int argc, char *argv[]);
int		*ft_sort(int *lst, int len);

/*utils*/

int		ft_isnum(char *str);
int		ft_strlen(char *str);
int		ft_nbrlen(char *str);
int		ft_atoi(char *str);
int		ft_dup(t_main *main);
int		*ft_tabcpy(int *tab, int size);
int		ft_parse(t_main *main, int argc, char *argv[]);
int		ft_parse2(t_main *main, char *argv);

/*error*/

void	ft_exit(t_main *main, int error);
int		ft_checkarg(int argc, char *argv[]);

/*operations*/

void	ft_sa(t_main *main, int mod);
void	ft_sb(t_main *main, int mod);
void	ft_ss(t_main *main);
void	ft_pa(t_main *main);
void	ft_pb(t_main *main);
void	ft_ra(t_main *main, int mod);
void	ft_rb(t_main *main, int mod);
void	ft_rr(t_main *main);
void	ft_rra(t_main *main, int mod);
void	ft_rrb(t_main *main, int mod);
void	ft_rrr(t_main *main);

/*solver*/

int		ft_is_solved(t_main *main);
void	ft_solve(t_main *main);
void	ft_solve2(t_main *main);
void	ft_solve3(t_main *main);
void	ft_solve4(t_main *main);
void	ft_solve5(t_main *main);
void	ft_put1st(t_main *main);
void	ft_put2nd(t_main *main);
void	ft_putlst(t_main *main);
void	ft_putworst(t_main *main);
void	ft_putlst2(t_main *main);
void	ft_fillbig(t_main *main);
void	ft_solvebig(t_main *main);

void	ft_showstate(t_main *main);
#endif