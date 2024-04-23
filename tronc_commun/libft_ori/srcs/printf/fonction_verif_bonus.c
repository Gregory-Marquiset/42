/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_verif_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:06:59 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:47:03 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'p'
		|| c == 'x' || c == 'X')
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

int	is_symbol(char c)
{
	if (c == '#' || c == ' ' || c == '-' || c == '+' || c == '.')
		return (1);
	return (0);
}

int	zero_digit_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	while (i < n)
		i += put_char('0');
	return (i += conv_hexa_lowercase(nbr));
}

int	zero_digit_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	while (i < n)
		i += put_char('0');
	return (i += conv_hexa_uppercase(nbr));
}
