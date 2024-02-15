/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:03:21 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/14 10:18:27 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_le_xav_stack(t_stack **stack)
{
	t_stack	*swap;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		swap = (*stack)->next;
		free(*stack);
		*stack = swap;
	}
	*stack = NULL;
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_le_xav_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_le_xav_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	get_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		highest = NULL;
		value = -2147483648;
		while (ptr)
		{
			if (ptr->value == -2147483648 && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				highest = ptr;
				value = ptr->value;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	nb_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
