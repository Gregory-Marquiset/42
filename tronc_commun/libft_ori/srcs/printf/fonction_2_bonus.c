/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:45 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	digit_dot_digit_flag(va_list args, char *str, int n1, int n2)
{
	int					i;
	unsigned long long	nbr;

	i = 0;
	if (*str == 's')
	{
		n1 -= n2;
		while (n1-- != 0)
			i += put_char(' ');
		return (i += put_str_n(va_arg(args, char *), n2));
	}
	nbr = va_arg(args, unsigned);
	n1 -= len_hexa(nbr);
	while (n1-- != 0)
		i += put_char(' ');
	if (*str == 'x')
		return (i += conv_hexa_lowercase(nbr));
	else if (*str == 'X')
		return (i += conv_hexa_uppercase(nbr));
	return (i);
}

int	minus_digit_dot(va_list args, char *str, int n)
{
	if (is_digit(*str) || *str == '0')
		return (minus_digit_dot_digit(args, str, n));
	else if (*str == 's')
		return (minus_digit_dot_s(va_arg(args, char *), n));
	else if (*str == 'd' || *str == 'i')
		return (minus_digit_dot_di(va_arg(args, int), n));
	else if (*str == 'u')
		return (minus_digit_dot_u(va_arg(args, unsigned int), n));
	else if (*str == 'x')
		return (minus_digit_dot_x(va_arg(args, unsigned), n));
	else if (*str == 'X')
		return (minus_digit_dot_uppx(va_arg(args, unsigned), n));
	return (0);
}

int	minus_digit_dot_digit(va_list args, char *str, int n1)
{
	int	n2;

	n2 = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (*str == 's')
		return (minus_digit_dot_digit_s(va_arg(args, char *), n1, n2));
	else if (*str == 'd' || *str == 'i')
		return (minus_digit_dot_digit_di(va_arg(args, int), n1, n2));
	else if (*str == 'u')
		return (minus_digit_dot_digit_u(va_arg(args, unsigned int), n1, n2));
	else if (*str == 'x')
		return (minus_digit_dot_digit_x(va_arg(args, unsigned), n1, n2));
	else if (*str == 'X')
		return (minus_digit_dot_digit_uppx(va_arg(args, unsigned), n1, n2));
	return (0);
}

int	minus_digit_dot_digit_di(long long nbr, int n1, int n2)
{
	int	i;

	i = 0;
	n2 -= len_nbr(nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		i += put_char('-');
		n2++;
	}
	while (n2-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	while (i < n1)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_digit_u(unsigned int nbr, int n1, int n2)
{
	int	i;

	i = 0;
	n2 -= len_nbr(nbr);
	while (n2-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	while (i < n1)
		i += put_char(' ');
	return (i);
}
