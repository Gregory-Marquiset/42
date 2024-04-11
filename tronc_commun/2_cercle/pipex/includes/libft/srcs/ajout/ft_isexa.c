/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:22:17 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 15:44:10 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isexa(char *code)
{
	int		i;
	int		j;
	char	*low;
	char	*upp;

	if (!code)
		return (0);
	if (code[0] != '0' || (code[1] != 'x' && code[1] != 'X')
		|| ft_strlen(code) != 8)
		return (0);
	low = "0123456789abcdef";
	upp = "0123456789ABCDEF";
	i = 2;
	while (code[i])
	{
		j = 0;
		while (code[i] != low[j] && code[i] != upp[j])
		{
			if (!low[j] || !upp[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
