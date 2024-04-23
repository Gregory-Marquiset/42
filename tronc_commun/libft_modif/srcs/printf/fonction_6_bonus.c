/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_6_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:58 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	minus_dot(va_list args, char *str)
{
	int	n;

	if (*str == 's')
		return (0);
	n = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (*str == 's')
		return (minus_s(va_arg(args, char *), n));
	else if (*str == 'd' || *str == 'i')
		return (minus_dot_digit_di(va_arg(args, int), n));
	else if (*str == 'u')
		return (minus_dot_digit_u(va_arg(args, unsigned int), n));
	else if (*str == 'x')
		return (minus_dot_digit_x(va_arg(args, unsigned), n));
	else if (*str == 'X')
		return (minus_dot_digit_uppx(va_arg(args, unsigned), n));
	return (0);
}

int	minus_dot_digit_di(long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (0);
	n -= len_nbr(nbr);
	if (nbr < 0)
	{
		i += put_char('-');
		nbr = -nbr;
		n++;
	}
	if (n < 0 || n == 0)
		return (i += put_nbr(nbr));
	while (n-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}

int	minus_dot_digit_u(unsigned int nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (0);
	n -= len_nbr(nbr);
	if (n < 0 || n == 0)
		return (i += put_nbr(nbr));
	while (n-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}

int	minus_dot_digit_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (0);
	n -= len_hexa(nbr);
	if (n < 0 || n == 0)
		return (i += conv_hexa_lowercase(nbr));
	while (n-- > 0)
		i += put_char('0');
	i += conv_hexa_lowercase(nbr);
	return (i);
}

int	minus_dot_digit_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (0);
	n -= len_hexa(nbr);
	if (n < 0 || n == 0)
		return (i += conv_hexa_uppercase(nbr));
	while (n-- > 0)
		i += put_char('0');
	i += conv_hexa_uppercase(nbr);
	return (i);
}
