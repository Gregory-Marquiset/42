/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:25:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:39 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
