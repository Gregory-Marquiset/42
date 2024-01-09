/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:02 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:24 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	top = (*stack)->next;
	bottom = get_bottom(*stack);
	bottom->next = *stack;
	bottom->next->next = NULL;
	*stack = top;
}

void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
