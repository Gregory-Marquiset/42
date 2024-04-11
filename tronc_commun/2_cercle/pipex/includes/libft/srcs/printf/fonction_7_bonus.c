/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_7_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:02 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	digit_flag_space(va_list args, char *str, int nbr)
{
	if (*str == 'c')
		return (space_c(args, nbr));
	else if (*str == 's')
		return (space_s(args, nbr));
	else if (*str == 'd' || *str == 'i')
		return (space_di(args, nbr));
	else if (*str == 'u')
		return (space_u(args, nbr));
	else if (*str == 'p')
		return (space_p(args, nbr));
	else if (*str == 'x')
		return (space_x(args, nbr));
	else if (*str == 'X')
		return (space_uppx(args, nbr));
	return (0);
}

int	dot_digit(va_list args, char *str)
{
	int	nbr;

	nbr = 0;
	nbr = a_to_i(str);
	while (is_digit(*str) || *str == '0')
		str++;
	if (is_flag(*str))
		return (dot_digit_flag(args, str, nbr));
	return (0);
}

int	digit_dot(va_list args, char *str, int nbr)
{
	if (is_flag(*str))
		return (put_dot(nbr));
	else if (is_digit(*str))
		return (digit_dot_digit(args, str, nbr));
	return (0);
}

int	dot_digit_flag(va_list args, char *str, int nbr)
{
	if (*str == 's')
		return (dot_s(args, nbr));
	else if (*str == 'd' || *str == 'i')
		return (dot_di(args, nbr));
	else if (*str == 'u')
		return (dot_u(args, nbr));
	else if (*str == 'x')
		return (dot_x(args, nbr));
	else if (*str == 'X')
		return (dot_uppx(args, nbr));
	return (0);
}

int	dot_zero(va_list args, char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = va_arg(args, int);
	if (nbr > -1 && nbr < 1)
		return (0);
	else if (*str == 'u')
		return (put_nbr((unsigned int)nbr));
	else if (*str == 'd' || *str == 'i')
		return (put_nbr((int)nbr));
	else if (*str == 'x')
		return (conv_hexa_lowercase((unsigned)nbr));
	else if (*str == 'X')
		return (conv_hexa_uppercase((unsigned)nbr));
	return (i);
}
