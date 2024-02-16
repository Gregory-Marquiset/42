/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:19:05 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 02:08:45 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (list[i])
	{
		add_bottom(&stack, ft_new_element(list[i]));
		i++;
	}
	ft_le_xav(list);
	return (stack);
}
