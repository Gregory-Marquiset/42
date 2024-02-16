/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:49:39 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:02:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_pos(t_stack **stack)
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

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_pos(stack);
	lowest_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element can
*	be placed somewhere in between elements in stack A, by checking whether
*	there is an element in stack A with a bigger index. If not, it finds the
*	element with the smallest index in A and assigns that as the target position.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 3
*		A contains indexes: 9 4 2 1 0
*		9 > 3 && 9 < INT_MAX 	: target_pos updated to 9
*		4 > 3 && 4 < 9 			: target pos updated to 4
*		2 < 3 && 2 < 4			: no update!
*	So target_pos needs to be the position of index 4, since it is
*	the closest index.
*	--- Example:
*		target_pos starts at INT_MAX
*		B index: 20
*		A contains indexes: 16 4 3
*		16 < 20					: no update! target_pos = INT_MAX
*		4  < 20					: no update! target_pos = INT_MAX
*		3  < 20					: no update! target_pos = INT_MAX
*	... target_pos stays at INT MAX, need to switch strategies.
*		16 < 20					: target_pos updated to 20
*		4  < 20					: target_pos updated to 4
*		3  < 20					: target_pos updated to 3
*	So target_pos needs to be the position of index 3, since that is
*	the "end" of the stack.*/

static int	get_target(t_stack **stack_a, int index_b, int target_index, int target_position)
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

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tempo_b;
	int		target_position;
	int		target_index;

	get_pos(stack_a);
	get_pos(stack_b);
	tempo_b = *stack_b;
	target_position = 0;
	target_index = 2147483647;
	while (tempo_b)
	{
		target_position = get_target(stack_a, tempo_b->index, target_index, target_position);
		tempo_b->target_position = target_position;
		tempo_b = tempo_b->next;
	}
}
