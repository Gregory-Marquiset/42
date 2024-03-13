/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:03:21 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 15:44:37 by gmarquis         ###   ########.fr       */
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
	exit(1);
}

int	ft_stack_size(t_stack *stack)
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

static t_stack	*ft_new_element(char *value)
{
	int		nbr;
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (0);
	nbr = ft_atoi(value);
	new->value = nbr;
	new->index = 0;
	new->position = -1;
	new->target_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_make_stack_a(char **list)
{
	t_stack	*stack;
	int		i;

	if (!list || !list[0])
		return (0);
	i = 0;
	stack = ft_new_element(list[i++]);
	if (!stack)
		return (0);
	while (list[i])
	{
		ft_add_bottom(&stack, ft_new_element(list[i]));
		i++;
	}
	ft_le_xav(list);
	return (stack);
}
