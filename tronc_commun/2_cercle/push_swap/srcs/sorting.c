/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:29:57 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:11:28 by greg             ###   ########.fr       */
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

void	do_sorting(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_b_keep_three(stack_a, stack_b, size);
	do_triad_sorting(stack_a);
}
