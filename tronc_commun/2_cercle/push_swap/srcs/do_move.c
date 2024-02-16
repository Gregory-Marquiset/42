/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:19:31 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 00:38:19 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack_a, stack_b);
	}
}

static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

static void	do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(stack_a);
			(*cost_a)++;
		}
	}
}

static void	do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(stack_b);
			(*cost_b)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
