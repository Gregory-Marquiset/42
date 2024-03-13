/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 04:08:04 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 15:43:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static t_stack	*ft_new_element(char *value)
{
	int		nbr;
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	nbr = ft_atoi(value);
	new->value = nbr;
	new->next = NULL;
	return (new);
}

t_stack	*ft_bikini_bottom(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_one_before_bikini_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	ft_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

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
	if (!stack)
		return (0);
	while (list[i] && ft_input_is_digit(list[i]))
	{
		ft_add_bottom(&stack, ft_new_element(list[i]));
		i++;
	}
	ft_le_xav(list);
	return (stack);
}
