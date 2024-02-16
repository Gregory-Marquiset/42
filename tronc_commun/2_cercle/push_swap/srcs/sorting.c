/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:29:57 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:58:22 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_b_keep_three(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pushed;
	int	i;

	pushed =0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}

}

static void	ft_rotate_stack(t_stack **stack_a)
{
	int	lowest_position;
	int	size;

	size = ft_stack_size(*stack_a);
	lowest_position = ft_get_lowest_index_position(stack_a);
	if (lowest_position > size / 2)
	{
		while (lowest_position < size)
		{
			ft_rra(stack_a);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			ft_ra(stack_a);
			lowest_position--;
		}
	}
}

void	ft_sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	ft_push_b_keep_three(stack_a, stack_b, size);
	ft_triad_sorting(stack_a);
	while (*stack_b)
	{
		ft_get_target_position(stack_a, stack_b);
		ft_calculates_cost(stack_a, stack_b);
		ft_cheapest_move(stack_a, stack_b);
	}
	if (!ft_stack_a_is_sorted(*stack_a))
		ft_rotate_stack(stack_a);
}
