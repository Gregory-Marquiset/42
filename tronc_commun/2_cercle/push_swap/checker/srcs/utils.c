/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:08:04 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/06 05:31:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static t_stack	*ft_new_element(char *value)
{
	int		nbr;
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (0);
	nbr = ft_atoi(value);
	new->value = nbr;
	new->next = NULL;
	return (new);
}

static t_stack	*ft_bikini_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static void	ft_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = ft_bikini_bottom(*stack);
	bottom->next = new;
}

t_stack	*ft_make_stack_a(char **list)
{
	t_stack	*stack;
	int		i;

	if (!list || !list[0])
		return (0);
	i = 0;
	stack = ft_new_element(list[i++]);
	while (list[i] && ft_input_is_digit(list[i]))
	{
		ft_add_bottom(&stack, ft_new_element(list[i]));
		i++;
	}
	return (stack);
}
