/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:25:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:21:24 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
