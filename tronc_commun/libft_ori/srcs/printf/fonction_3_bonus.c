/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:48 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	minus_digit_dot_digit_x(unsigned long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	n2 -= len_hexa(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += conv_hexa_lowercase(nbr);
	while (i < n1)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_digit_uppx(unsigned long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	n2 -= len_hexa(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += conv_hexa_uppercase(nbr);
	while (i < n1)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_digit_s(char *str, int n1, int n2)
{
	int	i;

	i = 0;
	if (n1 > n2)
		n1 -= n2;
	else if (n1 < n2)
		n1 -= len_str(str);
	if (n1 < 0)
		return (i += put_str(str));
	i += put_str_n(str, n2);
	while (n1-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_di(long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr != 0)
	{
		if (n < 0)
			return (i += put_nbr(nbr));
		i += put_nbr(nbr);
	}
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_u(unsigned int nbr, int n)
{
	int	i;

	i = 0;
	if (nbr != 0)
	{
		i += put_nbr(nbr);
		n--;
	}
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}
