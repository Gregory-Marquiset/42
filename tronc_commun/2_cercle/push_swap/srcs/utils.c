/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:03:21 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 01:49:33 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_xav_the_stack(t_stack **stack)
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
		ft_xav_the_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_xav_the_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_get_index(t_stack *stack_a, int size)
{
	t_stack	*tempo_a;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		tempo_a = stack_a;
		highest = NULL;
		value = -2147483648;
		while (tempo_a)
		{
			if (tempo_a->value == -2147483648 && tempo_a->index == 0)
				tempo_a->index = 1;
			if (tempo_a->value > value && tempo_a->index == 0)
			{
				highest = tempo_a;
				value = tempo_a->value;
				tempo_a = stack_a;
			}
			else
				tempo_a = tempo_a->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int		ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	ft_absolute_nbr(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
