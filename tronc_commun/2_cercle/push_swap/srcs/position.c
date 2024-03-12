/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:49:39 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/11 23:27:03 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_give_position(t_stack **stack)
{
	t_stack	*tempo;
	int		i;

	tempo = *stack;
	i = 0;
	while (tempo)
	{
		tempo->position = i;
		tempo = tempo->next;
		i++;
	}
}

int	ft_get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_position;

	tmp = *stack;
	lowest_index = INT_MAX;
	ft_give_position(stack);
	lowest_position = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_position);
}

static int	ft_give_target(t_stack **stack_a, int index_b, int target_index,
		int target_position)
{
	t_stack	*tempo_a;

	tempo_a = *stack_a;
	while (tempo_a)
	{
		if (tempo_a->index > index_b && tempo_a->index < target_index)
		{
			target_index = tempo_a->index;
			target_position = tempo_a->position;
		}
		tempo_a = tempo_a->next;
	}
	if (target_index != 2147483647)
		return (target_position);
	tempo_a = *stack_a;
	while (tempo_a)
	{
		if (tempo_a->index < target_index)
		{
			target_index = tempo_a->index;
			target_position = tempo_a->position;
		}
		tempo_a = tempo_a->next;
	}
	return (target_position);
}

void	ft_get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tempo_b;
	int		target_position;
	int		target_index;

	ft_give_position(stack_a);
	ft_give_position(stack_b);
	tempo_b = *stack_b;
	target_position = 0;
	target_index = 2147483647;
	while (tempo_b)
	{
		target_position = ft_give_target(stack_a, tempo_b->index, target_index,
				target_position);
		tempo_b->target_position = target_position;
		tempo_b = tempo_b->next;
	}
}
