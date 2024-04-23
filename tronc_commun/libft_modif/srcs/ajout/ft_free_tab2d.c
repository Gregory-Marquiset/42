/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:27:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 07:38:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_tab2d(char **input)
{
	int	i;

	if (!input || !input[0])
		return ;
	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
