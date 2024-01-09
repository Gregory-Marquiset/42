/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:20 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = get_bottom(*stack);
	before_bottom = get_before_bottom(*stack);
	bottom->next = *stack;
	before_bottom->next = NULL;
	*stack = bottom;
}

void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
