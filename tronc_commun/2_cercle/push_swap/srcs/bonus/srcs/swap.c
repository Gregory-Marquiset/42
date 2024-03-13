/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:25:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/07 00:31:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	swap(t_stack **stack)
{
	t_stack	*tempo1;
	t_stack	*tempo2;

	tempo1 = (*stack)->next;
	tempo2 = *stack;
	tempo2->next = tempo1->next;
	tempo1->next = tempo2;
	*stack = tempo1;
}

void	ft_sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	ft_sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
