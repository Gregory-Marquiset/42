/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_9_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	zero_dot_digit_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	while (n-- > 0)
		i += put_char('0');
	i += conv_hexa_uppercase(nbr);
	return (i);
}

int	zero_digit(va_list args, char *str)
{
	int	n;

	n = 0;
	n = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (is_flag(*str))
		return (zero_digit_flag(args, str, n));
	else if (*str == '.')
		return (zero_digit_dot(args, str + 1, n));
	return (0);
}

int	zero_digit_dot(va_list args, char *str, int n)
{
	if (*str == 'd' || *str == 'i')
		return (zero_digit_dot_di(va_arg(args, int), n));
	if (*str == 'u')
		return (zero_digit_dot_u(va_arg(args, unsigned int), n));
	if (*str == 'x')
		return (zero_digit_dot_x(va_arg(args, unsigned), n));
	if (*str == 'X')
		return (zero_digit_dot_uppx(va_arg(args, unsigned), n));
	else if (*str == '0')
		return (zero_digit_dot_zero(args, str + 1, n));
	else if (is_digit(*str))
		return (zero_digit_dot_digit(args, str, n));
	return (0);
}

int	zero_digit_dot_digit(va_list args, char *str, int n1)
{
	int	n2;

	n2 = 0;
	n2 = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (*str == 'd' || *str == 'i')
		return (zero_digit_dot_digit_di(va_arg(args, int), n1, n2));
	if (*str == 'u')
		return (zero_digit_dot_digit_u(va_arg(args, unsigned int), n1, n2));
	if (*str == 'x')
		return (zero_digit_dot_digit_x(va_arg(args, unsigned), n1, n2));
	if (*str == 'X')
		return (zero_digit_dot_digit_uppx(va_arg(args, unsigned), n1, n2));
	return (0);
}

int	zero_digit_dot_digit_di(long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	if (n2 <= 0 || n2 < len_nbr(nbr))
	{
		n1 -= len_nbr(nbr);
		if (nbr < 0)
			n1++;
	}
	else if (n2 > 0)
		n1 -= n2;
	if (nbr < 0)
		n1--;
	while (i < n1 && nbr != 0)
		i += put_char(' ');
	if (nbr < 0)
	{
		nbr = -nbr;
		i += put_char('-');
	}
	n2 -= len_nbr(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}
