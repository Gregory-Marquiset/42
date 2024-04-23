/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:37 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	a_to_i(char *str)
{
	int	nbr;

	nbr = 0;
	while (is_digit(*str) || *str == '0')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr);
}

int	digit(va_list args, char *str)
{
	int	nbr;

	nbr = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (is_flag(*str))
		return (digit_flag_space(args, str, nbr));
	else if (*str == ' ')
		return (digit_flag_space(args, str, nbr));
	else if (*str == '.')
		return (digit_dot(args, str + 1, nbr));
	return (0);
}

int	le_z(va_list args, char *str)
{
	while (*str == '0')
		str++;
	if (is_digit(*str))
		return (zero_digit(args, str));
	else if (*str == 'd' || *str == 'i')
		return (put_nbr(va_arg(args, int)));
	else if (*str == 'u')
		return (put_nbr(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (conv_hexa_lowercase(va_arg(args, unsigned)));
	else if (*str == 'X')
		return (conv_hexa_uppercase(va_arg(args, unsigned)));
	else if (*str == '.')
		return (zero_dot(args, str + 1));
	return (0);
}

int	put_dot(int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
		i += put_char(' ');
	return (i);
}

int	put_str_n(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n && *str)
		i += put_char(*str++);
	return (i);
}
