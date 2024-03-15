/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:03 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 10:01:04 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void				ft_calcul_cost(t_stack **stack_a, t_stack **stack_b);
void				ft_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//		main.c				//
void				push_swap(t_stack **stack_a, t_stack **stack_b, int size);

//		move.c				//
void				ft_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
						int cost_b);

//		position.c			//
int					ft_get_lowest_index_position(t_stack **stack);
void				ft_get_target_position(t_stack **stack_a,
						t_stack **stack_b);

//		push.c				//
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

//		reverse_rotate.c	//
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

//		rotate.c			//
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

//		sorting.c			//
void				ft_sorting(t_stack **stack_a, t_stack **stack_b, int size);
void				ft_triad_sorting(t_stack **stack_a);

//		swap.c				//
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

//		utils				//

//		move.c				//
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				push(t_stack **src, t_stack **dst);

//		stack_utils.c		//
int					ft_stack_a_is_sorted(t_stack *stack_a);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_get_bottom(t_stack *stack);
t_stack				*ft_get_one_before_bottom(t_stack *stack);
void				ft_add_bottom(t_stack **stack, t_stack *new);

//		utils.c				//
void				ft_free_stack(t_stack **stack);
void				ft_error(t_stack **stack_a, t_stack **stack_b,
						char *command);
t_stack				*ft_make_stack_a(char **list);

//		verif_input.c		//
char				**ft_check_input(char **input);

#endif
