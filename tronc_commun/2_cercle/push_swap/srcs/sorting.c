/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:29:57 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:04:30 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_b_keep_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed;
	int	i;

	pushed =0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}

}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_position;
	int	size;

	size = ft_stack_size(*stack_a);
	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > size / 2)
	{
		while (lowest_position < size)
		{
			do_rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			do_ra(stack_a);
			lowest_position--;
		}
	}
}

void	do_sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_b_keep_three(stack_a, stack_b, size);
	do_triad_sorting(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		ft_calculates_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!ft_stack_a_is_sorted(*stack_a))
		shift_stack(stack_a);
}
