/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/07 00:34:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = ft_bikini_bottom(*stack);
	before_bottom = ft_one_before_bikini_bottom(*stack);
	bottom->next = *stack;
	before_bottom->next = NULL;
	*stack = bottom;
}

void	ft_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	ft_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
