/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_8_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:05 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	digit_dot_digit(va_list args, char *str, int nbr1)
{
	int	n2;

	n2 = 0;
	n2 = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (is_flag(*str))
		return (digit_dot_digit_flag(args, str, nbr1, n2));
	return (0);
}

int	zero_dot(va_list args, char *str)
{
	int	n;

	n = 0;
	n = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (*str == 'd' || *str == 'i')
		return (zero_dot_digit_di(va_arg(args, int), n));
	if (*str == 'u')
		return (zero_dot_digit_u(va_arg(args, unsigned int), n));
	if (*str == 'x')
		return (zero_dot_digit_x(va_arg(args, unsigned), n));
	if (*str == 'X')
		return (zero_dot_digit_uppx(va_arg(args, unsigned), n));
	return (0);
}

int	zero_dot_digit_di(long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i += put_char('-');
		n--;
	}
	while (n-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}

int	zero_dot_digit_u(long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_nbr(nbr);
	while (n-- > 0)
		i += put_char('0');
	i += put_nbr(nbr);
	return (i);
}

int	zero_dot_digit_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	while (n-- > 0)
		i += put_char('0');
	i += conv_hexa_lowercase(nbr);
	return (i);
}
