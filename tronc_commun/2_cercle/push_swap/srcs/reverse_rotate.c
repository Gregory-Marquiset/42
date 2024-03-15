/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:22:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
