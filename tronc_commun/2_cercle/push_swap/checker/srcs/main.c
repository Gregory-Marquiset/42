/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/06 05:32:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_stack_a_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	for_tests(t_stack *stack_a, t_stack *stack_b, int size)
{
	int (i) = 1;
	t_stack	*(tempo_a) = stack_a;
	t_stack *(tempo_b) = stack_b;

	ft_printf("\033[35;01m| Stack_a valid !  size %2d |\033[00m\n", size);
	while (i < size)
	{
		if (tempo_a)
		{
			ft_printf("\033[34;01m| stack_a %2d =\033[00m %11d \033[34;01m|\033[00m \033[36;01midx = %2d\033[00m", i, tempo_a->value, tempo_a->index);
			tempo_a = tempo_a->next;
		}
		else if (!tempo_a)
			ft_printf("%37c", ' ');
		if (tempo_b)
		{
			ft_printf("\033[32;01m\t| stack_b %2d =\033[00m %11d \033[32;01m|\033[00m \033[33;01midx = %2d\033[00m\n", i, tempo_b->value, tempo_b->index);
			tempo_b = tempo_b->next;
		}
		else if (!tempo_b)
			ft_printf("\n");
		i++;
	}
	ft_printf("\033[34;01m| stack_a %2d =\033[00m %11d \033[34;01m|\033[00m \033[36;01midx = %2d\033[00m", i, tempo_a->value, tempo_a->index);
	if(tempo_b)
		ft_printf("\033[32;01m\t| stack_b %2d =\033[00m %11d \033[32;01m|\033[00m \033[33;01midx = %2d\033[00m\n", i, tempo_b->value, tempo_b->index);
	else if (!tempo_b)
		ft_printf("\n");
	if (!ft_stack_a_is_sorted(stack_a))
		ft_printf("\033[31;01m|  Stack_a not sorted  !!  |\033[00m\n");
	else
		ft_printf("\033[32;01m|    Stack_a sorted  !!    |\033[00m\n");
	return ;
}

static int		ft_stack_size(t_stack *stack)
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

void	do_move(t_stack **stack_a, t_stack **stack_b, char **input)
{
	if (size == 2 && !ft_stack_a_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (size == 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_triad_sorting(stack_a);
	else if (size > 3 && !ft_stack_a_is_sorted(*stack_a))
		ft_sorting(stack_a, stack_b, size);
	return ;
}

int	main(int argc, char **argv)
{
	int		size;
	char	**clean_input;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 4)
		return (0);
	clean_input = ft_check_input(argv);
	if (clean_input == NULL)
		ft_error(NULL, NULL);
	if (!ft_input_is_instuction(clean_input))
		ft_error(NULL, NULL);
	stack_a = ft_make_stack_a(clean_input);
	stack_b = NULL;
	size = ft_stack_size(stack_a);

	for_tests(stack_a, stack_b, size);
	do_move(&stack_a, &stack_b, clean_input);
	for_tests(stack_a, stack_b, size);

	ft_le_xav(clean_input);
	ft_xav_the_stack(&stack_b);
	ft_xav_the_stack(&stack_a);
	return (0);
}
