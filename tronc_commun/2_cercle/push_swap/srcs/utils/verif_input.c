/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:16:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 09:39:44 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_count(char **input)
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

static char	*ft_alt_strjoin(char **input, char set)
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

char	**ft_check_input(char **input)
{
	int		i;
	char	*str;
	char	**clean_input;

	if (!input || !input[0])
		return (NULL);
	str = ft_alt_strjoin(input, ' ');
	if (!str)
		return (NULL);
	clean_input = ft_split(str, ' ');
	if (!clean_input)
		return (NULL);
	free(str);
	i = 0;
	while (clean_input[i])
	{
		if (!ft_input_is_digit(clean_input[i])
			|| !ft_isint(clean_input[i]))
			return (ft_free_tab2d(clean_input), NULL);
		i++;
	}
	if (ft_countain_double(clean_input))
		return (ft_free_tab2d(clean_input), NULL);
	return (clean_input);
}
