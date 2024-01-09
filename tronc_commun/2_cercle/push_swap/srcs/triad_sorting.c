/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triad_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:41:41 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:43 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	do_triad_sorting(t_stack **stack_a)
{
	int		highest;

	if (sorted_stack(*stack_a))
		return ;
	highest = highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		do_ra(stack_a);
	else if ((*stack_a)->next->index == highest)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}
