/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_13_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:34 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	space_digit_s(char *str, int n)
{
	int	i;

	i = 0;
	n -= len_str(str);
	while (n > 0)
	{
		i += put_char(' ');
		n--;
	}
	i += put_str(str);
	return (i);
}
