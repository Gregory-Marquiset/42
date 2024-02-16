/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:03 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:08:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

//		cost.c				//
void				ft_calculates_cost(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//		do_move.c			//
void				do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

//		initialisation.c	//
t_stack				*ft_make_stack_a(char **list);

//		position.c			//
int					get_lowest_index_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);

//		main.c				//
int					ft_stack_a_is_sorted(t_stack *stack_a);
void				push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int					main(int argc, char **argv);

//		push.c				//
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);

//		reverse_rotate.c	//
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);

//		sorting.c			//
void				do_sorting(t_stack **stack_a, t_stack **stack_b, int size);

//		rotate.c			//
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);

//		stack_navigation.c	//
t_stack				*get_bottom(t_stack *stack);
t_stack				*get_before_bottom(t_stack *stack);
void				add_bottom(t_stack **stack, t_stack *new);

//		swap.c				//
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);

//		triad_sorting.c		//
void				do_triad_sorting(t_stack **stack_a);

//		utils.c				//
void				ft_xav_the_stack(t_stack **stack);
void				ft_error(t_stack **stack_a, t_stack **stack_b);
void				ft_get_index(t_stack *stack_a, int size);
int					ft_stack_size(t_stack *stack);
int					ft_absolute_nbr(int nbr);

//		verif_input_utils.c	//
void				ft_le_xav(char **clean_input);
long				ft_atol(char *clean_input);
int					ft_count(char **input);
char				*ft_join(char **input, char set);

//		verif_input.c		//
char				**ft_check_input(char **input);

#endif
