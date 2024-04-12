/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:42:14 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 09:22:36 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && !ft_stack_a_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_triad_sorting(stack_a);
	else if (size > 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_sorting(stack_a, stack_b, size);
	return ;
}

static void	ft_give_index(t_stack *stack_a, int size)
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

int	main(int argc, char **argv)
{
	int		size;
	char	**list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	list = ft_check_input(argv);
	if (list == NULL)
		ft_error(NULL, NULL, NULL);
	stack_a = ft_make_stack_a(list);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	ft_give_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	ft_free_stack(&stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
