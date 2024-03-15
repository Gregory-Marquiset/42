/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:20:14 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:42:57 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../../includes/push_swap.h"

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

//		swap.c				//
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

#endif
