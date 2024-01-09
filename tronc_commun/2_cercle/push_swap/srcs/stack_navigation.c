/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_navigation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:52:06 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:32 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		stack_size(t_stack *stack_a)
{
	int	size;

	size = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		stack_a = stack_a->next;
		size++;
	}
	return (size);
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = new;
}
