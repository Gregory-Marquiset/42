/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:40:17 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/11 23:26:43 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_calculates_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tempo_a;
	t_stack	*tempo_b;
	int		size_a;
	int		size_b;

	tempo_a = *stack_a;
	tempo_b = *stack_b;
	size_a = ft_stack_size(tempo_a);
	size_b = ft_stack_size(tempo_b);
	while (tempo_b)
	{
		tempo_b->cost_b = tempo_b->position;
		if (tempo_b->position > size_b / 2)
			tempo_b->cost_b = (size_b - tempo_b->position) * -1;
		tempo_b->cost_a = tempo_b->target_position;
		if (tempo_b->target_position > size_a / 2)
			tempo_b->cost_a = (size_a - tempo_b->target_position) * -1;
		tempo_b = tempo_b->next;
	}
}

static int	ft_absolute_nbr(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tempo_b;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tempo_b = *stack_b;
	cheapest = 2147483647;
	while (tempo_b)
	{
		if (ft_absolute_nbr(tempo_b->cost_a)
			+ ft_absolute_nbr(tempo_b->cost_b) < ft_absolute_nbr(cheapest))
		{
			cheapest = ft_absolute_nbr(tempo_b->cost_b)
				+ ft_absolute_nbr(tempo_b->cost_a);
			cost_a = tempo_b->cost_a;
			cost_b = tempo_b->cost_b;
		}
		tempo_b = tempo_b->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}
