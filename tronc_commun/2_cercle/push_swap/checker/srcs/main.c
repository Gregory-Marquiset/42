/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/12 09:09:03 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_stack_a_is_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_error(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_xav_the_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_xav_the_stack(stack_b);
	if (command != NULL)
		free(command);
	write(2, "Error\n", 6);
	exit(1);
}

static void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (*stack_a && (*stack_a)->next && !ft_strncmp(command, "sa\n", 4))
		ft_sa(stack_a);
	else if (*stack_b && (*stack_b)->next && !ft_strncmp(command, "sb\n", 4))
		ft_sb(stack_b);
	else if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& !ft_strncmp(command, "ss\n", 4))
		ft_ss(stack_a, stack_b);
	else if (*stack_a && !ft_strncmp(command, "pb\n", 4))
		ft_pb(stack_a, stack_b);
	else if (*stack_a && *stack_b && !ft_strncmp(command, "pa\n", 4))
		ft_pa(stack_a, stack_b);
	else if (*stack_a && (*stack_a)->next && !ft_strncmp(command, "ra\n", 4))
		ft_ra(stack_a);
	else if (*stack_b && (*stack_b)->next && !ft_strncmp(command, "rb\n", 4))
		ft_rb(stack_b);
	else if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& !ft_strncmp(command, "rr\n", 4))
		ft_rr(stack_a, stack_b);
	else if (*stack_a && (*stack_a)->next && !ft_strncmp(command, "rra\n", 5))
		ft_rra(stack_a);
	else if (*stack_b && (*stack_b)->next && !ft_strncmp(command, "rrb\n", 5))
		ft_rrb(stack_b);
	else if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& !ft_strncmp(command, "rrr\n", 5))
		ft_rrr(stack_a, stack_b);
}

static void	wait_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		exec_command(stack_a, stack_b, command);
		free(command);
		command = get_next_line(0);
	}
	if (command)
		free (command);
}

int	main(int argc, char **argv)
{
	char	**clean_input;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	clean_input = ft_check_input(argv);
	if (clean_input == NULL)
		ft_error(NULL, NULL, NULL);
	stack_a = ft_make_stack_a(clean_input);
	stack_b = NULL;
	wait_commands(&stack_a, &stack_b);
	if (!stack_b && ft_stack_a_is_sorted(&stack_a))
		ft_printf("\033[32;01mOK\n\033[00m");
	else
		ft_printf("\033[31;01mKO\n\033[00m");
	ft_xav_the_stack(&stack_a);
	ft_xav_the_stack(&stack_b);
	return (0);
}
