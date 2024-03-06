/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:22 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/06 00:19:32 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_xav_the_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_xav_the_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_le_xav(char **clean_input)
{
	int	i;

	if (!clean_input || !clean_input[0])
		return ;
	i = 0;
	while (clean_input[i])
	{
		free(clean_input[i]);
		i++;
	}
	free(clean_input);
	return ;
}

long	ft_atol(char *clean_input)
{
	int		i;
	int		sign;
	long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	if (clean_input[i] == '+')
		i++;
	else if (clean_input[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (ft_isdigit(clean_input[i]))
	{
		rslt = (rslt * 10) + clean_input[i] - 48;
		i++;
	}
	return (rslt * sign);
}

int	ft_count(char **input)
{
	int	index;
	int	i;
	int	count_char;

	index = 1;
	count_char = 0;
	while (input[index])
	{
		i = 0;
		while (input[index][i])
		{
			i++;
			count_char++;
		}
		index++;
		count_char++;
	}
	return (count_char);
}

char	*ft_join(char **input, char set)
{
	char	*str;
	int		count_char;
	int		index;
	int		i;
	int		position;

	count_char = ft_count(input);
	str = malloc(count_char);
	if (!str)
		return (0);
	index = 1;
	position = 0;
	while (input[index])
	{
		i = 0;
		while (input[index][i])
			str[position++] = input[index][i++];
		if (position + 1 < count_char)
			str[position++] = set;
		++index;
	}
	str[position] = '\0';
	return (str);
}
