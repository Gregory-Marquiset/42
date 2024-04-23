/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:50:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:47:07 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	redirection(va_list args, char *str)
{
	if (*str == 'c')
		return (put_char(va_arg(args, int)));
	else if (*str == 's')
		return (put_str(va_arg(args, char *)));
	else if (*str == 'd' || *str == 'i')
		return (put_nbr(va_arg(args, int)));
	else if (*str == 'u')
		return (put_nbr(va_arg(args, unsigned int)));
	else if (*str == 'p')
		return (adress(va_arg(args, unsigned long long)));
	else if (*str == 'x')
		return (conv_hexa_lowercase(va_arg(args, unsigned)));
	else if (*str == 'X')
		return (conv_hexa_uppercase(va_arg(args, unsigned)));
	return (0);
}

int	symbol(va_list args, char *str)
{
	if (*str == '#')
		return (sharp(args, str + 1));
	else if (*str == ' ')
		return (space(args, str + 1));
	else if (*str == '+')
		return (plus(args, str + 1));
	if (*str == '-')
		return (minus(args, str + 1));
	else if (*str == '.')
		return (le_dot(args, str + 1));
	return (0);
}

int	reading(va_list args, char *str)
{
	if (*str == '%')
		return (put_char('%'));
	else if (is_flag(*str))
		return (redirection(args, str));
	else if (is_digit(*str))
		return (digit(args, str));
	else if (is_symbol(*str))
		return (symbol(args, str));
	else if (*str == '0')
		return (le_z(args, str + 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	char	*str;
	va_list	args;

	len = 0;
	va_start(args, s);
	str = (char *)s;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += reading(args, str);
			str += len_flag(str);
		}
		else if (*str != '%')
		{
			len += put_char(*str);
			str++;
		}
	}
	va_end(args);
	return (len);
}
