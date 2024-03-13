/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_symbol_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:56:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:47:00 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	sharp(va_list args, char *str)
{
	int	i;

	i = 0;
	if (*str == 'X')
		i += adress_uppercase(va_arg(args, unsigned));
	else if (*str == 'x')
		i += adress_lowercase(va_arg(args, unsigned));
	return (i);
}

int	space(va_list args, char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (*str == ' ')
		str++;
	if (*str == 'd' || *str == 'i')
		return (i += put_espace_di(va_arg(args, int)));
	else if (*str == 's')
		i += put_str(va_arg(args, char *));
	else if (is_digit(*str) || *str == '0')
	{
		nbr = a_to_i(str);
		while (is_digit(*str) || *str == '0')
			str++;
		if (*str == 's')
			i += space_digit_s(va_arg(args, char *), nbr);
	}
	return (i);
}

int	plus(va_list args, char *str)
{
	int	i;

	i = 0;
	while (*str == '+')
		str++;
	if (*str == 'd' || *str == 'i')
		return (i += put_plus(va_arg(args, int)));
	return (i);
}

int	le_dot(va_list args, char *str)
{
	int	i;

	i = 0;
	if (*str == 's')
		return (0);
	if (*str == '0')
		return (dot_zero(args, str + 1));
	if (is_digit(*str))
		return (dot_digit(args, str));
	if (is_flag(*str))
		return (redirection_dot(args, str));
	return (i);
}

int	minus(va_list args, char *str)
{
	int	nbr;

	while (*str == '-')
		str++;
	if (*str == '.')
		return (minus_dot(args, str + 1));
	nbr = a_to_i(str);
	while (is_digit(*str) || *str == '0' || *str == '-')
		str++;
	if (is_flag(*str))
		return (minus_flag(args, str, nbr));
	else if (*str == '.')
		return (minus_digit_dot(args, str + 1, nbr));
	return (0);
}
