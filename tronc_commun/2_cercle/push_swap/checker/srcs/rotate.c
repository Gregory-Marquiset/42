/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:02 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/07 00:36:03 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	top = (*stack)->next;
	bottom = ft_bikini_bottom(*stack);
	bottom->next = *stack;
	bottom->next->next = NULL;
	*stack = top;
}

void	ft_ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	rotate(stack_b);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
