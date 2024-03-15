/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:43:02 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:22:18 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_ra(t_stack **stack_a)
{
	rotate(stack_a);
}

void	ft_rb(t_stack **stack_b)
{
	rotate(stack_b);
}
