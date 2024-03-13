/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_10_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:11 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	zero_digit_dot_digit_u(long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	if (n2 <= 0 || n2 < len_nbr(nbr))
		n1 -= len_nbr(nbr);
	else if (n2 > 0)
		n1 -= n2;
	while (i < n1 && nbr > 0)
		i += put_char(' ');
	n2 -= len_nbr(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}

int	zero_digit_dot_digit_x(unsigned long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	if (n2 <= 0 || n2 < len_hexa(nbr))
		n1 -= len_hexa(nbr);
	else if (n2 > 0)
		n1 -= n2;
	while (i < n1 && nbr > 0)
		i += put_char(' ');
	n2 -= len_hexa(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += conv_hexa_lowercase(nbr);
	return (i);
}

int	zero_digit_dot_digit_uppx(unsigned long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	if (n2 <= 0 || n2 < len_hexa(nbr))
		n1 -= len_hexa(nbr);
	else if (n2 > 0)
		n1 -= n2;
	while (i < n1 && nbr > 0)
		i += put_char(' ');
	n2 -= len_hexa(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += conv_hexa_uppercase(nbr);
	return (i);
}

int	zero_digit_dot_zero(va_list args, char *str, int n)
{
	while (*str == '0')
		str++;
	if (*str == 'd' || *str == 'i')
		return (zero_digit_dot_zero_di(va_arg(args, int), n));
	if (*str == 'u')
		return (zero_digit_dot_zero_u(va_arg(args, unsigned int), n));
	if (*str == 'x')
		return (zero_digit_dot_zero_x(va_arg(args, unsigned), n));
	if (*str == 'X')
		return (zero_digit_dot_zero_uppx(va_arg(args, unsigned), n));
	return (0);
}

int	zero_digit_dot_zero_di(long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		while (i < n)
			i += put_char(' ');
		return (i);
	}
	n -= len_nbr(nbr);
	if (n-- > 0)
		i += put_char(' ');
	return (i += put_nbr(nbr));
}
