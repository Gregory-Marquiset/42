/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triad_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:41:41 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 01:24:14 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_find_highest_index(t_stack *stack)
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

	if (ft_stack_a_is_sorted(*stack_a))
		return ;
	highest = ft_find_highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		do_ra(stack_a);
	else if ((*stack_a)->next->index == highest)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}
