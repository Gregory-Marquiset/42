/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 10:01:48 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	ft_is_instruction(char *command)
{
	if (!ft_strncmp(command, "sa\n", 4) || !ft_strncmp(command, "sb\n", 4)
		|| !ft_strncmp(command, "ss\n", 4))
		return (1);
	else if (!ft_strncmp(command, "pa\n", 4) || !ft_strncmp(command, "pb\n", 4))
		return (1);
	else if (!ft_strncmp(command, "ra\n", 4) || !ft_strncmp(command, "rb\n", 4)
		|| !ft_strncmp(command, "rr\n", 4))
		return (1);
	else if (!ft_strncmp(command, "rra\n", 5) || !ft_strncmp(command, "rrb\n",
			5) || !ft_strncmp(command, "rrr\n", 5))
		return (1);
	else
		return (0);
}

static void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (!ft_is_instruction(command))
		ft_error(stack_a, stack_b, command);
	if (*stack_a && (*stack_a)->next && (!ft_strncmp(command, "sa\n", 4)
			|| !ft_strncmp(command, "ss\n", 4)))
		ft_sa(stack_a);
	if (*stack_b && (*stack_b)->next && (!ft_strncmp(command, "sb\n", 4)
			|| !ft_strncmp(command, "ss\n", 4)))
		ft_sb(stack_b);
	if (*stack_a && !ft_strncmp(command, "pb\n", 4))
		ft_pb(stack_a, stack_b);
	if (*stack_a && *stack_b && !ft_strncmp(command, "pa\n", 4))
		ft_pa(stack_a, stack_b);
	if (*stack_a && (*stack_a)->next && (!ft_strncmp(command, "ra\n", 4)
			|| !ft_strncmp(command, "rr\n", 4)))
		ft_ra(stack_a);
	if (*stack_b && (*stack_b)->next && (!ft_strncmp(command, "rb\n", 4)
			|| !ft_strncmp(command, "rr\n", 4)))
		ft_rb(stack_b);
	if (*stack_a && (*stack_a)->next && (!ft_strncmp(command, "rra\n", 5)
			|| !ft_strncmp(command, "rrr\n", 5)))
		ft_rra(stack_a);
	if (*stack_b && (*stack_b)->next && (!ft_strncmp(command, "rrb\n", 5)
			|| !ft_strncmp(command, "rrr\n", 5)))
		ft_rrb(stack_b);
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
		free(command);
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
	if (!stack_b && ft_stack_a_is_sorted(stack_a))
		ft_printf("\033[32;01mOK\n\033[00m");
	else
		ft_printf("\033[31;01mKO\n\033[00m");
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
