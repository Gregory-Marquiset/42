/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:21:04 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:57:31 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tempo1;
	t_stack	*tempo2;

	tempo1 = (*stack)->next;
	tempo2 = *stack;
	tempo2->next = tempo1->next;
	tempo1->next = tempo2;
	*stack = tempo1;
}

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*bottom;

	top = (*stack)->next;
	bottom = ft_get_bottom(*stack);
	bottom->next = *stack;
	bottom->next->next = NULL;
	*stack = top;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	bottom = ft_get_bottom(*stack);
	before_bottom = ft_get_one_before_bottom(*stack);
	bottom->next = *stack;
	before_bottom->next = NULL;
	*stack = bottom;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}
