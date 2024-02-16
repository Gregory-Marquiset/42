/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:03 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 04:42:56 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft/includes/libft.h"
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
void				ft_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//		move.c				//
void				ft_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

//		position.c			//
int					ft_get_lowest_index_position(t_stack **stack);
void				ft_get_target_position(t_stack **stack_a, t_stack **stack_b);

//		main.c				//
int					ft_stack_a_is_sorted(t_stack *stack_a);
void				push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int					main(int argc, char **argv);

//		push.c				//
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

//		reverse_rotate.c	//
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

//		sorting.c			//
void				ft_sorting(t_stack **stack_a, t_stack **stack_b, int size);

//		rotate.c			//
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

//		stack_navigation.c	//
t_stack				*ft_bikini_bottom(t_stack *stack);
t_stack				*ft_one_before_bikini_bottom(t_stack *stack);
void				ft_add_bottom(t_stack **stack, t_stack *new);

//		swap.c				//
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

//		triad_sorting.c		//
void				ft_triad_sorting(t_stack **stack_a);

//		utils.c				//
void				ft_xav_the_stack(t_stack **stack);
void				ft_error(t_stack **stack_a, t_stack **stack_b);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_make_stack_a(char **list);

//		verif_input_utils.c	//
void				ft_le_xav(char **clean_input);
long				ft_atol(char *clean_input);
int					ft_count(char **input);
char				*ft_join(char **input, char set);

//		verif_input.c		//
char				**ft_check_input(char **input);

#endif
