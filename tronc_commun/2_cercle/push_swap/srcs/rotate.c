/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:02 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:21:56 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
