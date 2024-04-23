/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:56:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:41 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	redirection_dot(va_list args, char *str)
{
	long long	nbr;

	if (*str == 's')
		return (put_str(va_arg(args, char *)));
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		return (put_diu(args, str));
	else if (*str == 'p')
		return (adress(va_arg(args, unsigned long long)));
	else if (*str == 'x')
	{
		nbr = va_arg(args, long long);
		if (nbr > -1 && nbr < 1)
			return (0);
		return (conv_hexa_lowercase((unsigned)nbr));
	}
	else if (*str == 'X')
	{
		nbr = va_arg(args, long long);
		if (nbr > -1 && nbr < 1)
			return (0);
		return (conv_hexa_uppercase((unsigned)nbr));
	}
	return (0);
}

int	put_diu(va_list args, char *str)
{
	long long	nbr;

	if (*str == 'd' || *str == 'i')
	{
		nbr = va_arg(args, int);
		if (nbr == 0)
			return (0);
		return (put_nbr(nbr));
	}
	else if (*str == 'u')
	{
		nbr = va_arg(args, unsigned int);
		if (nbr <= 0)
			return (0);
		return (put_nbr(nbr));
	}
	return (0);
}

int	minus_flag(va_list args, char *str, int nbr)
{
	if (*str == 'c')
		return (minus_c(va_arg(args, int), nbr));
	else if (*str == 's')
		return (minus_s(va_arg(args, char *), nbr));
	else if (*str == 'd' || *str == 'i')
		return (minus_di(va_arg(args, int), nbr));
	else if (*str == 'u')
		return (minus_u(va_arg(args, unsigned int), nbr));
	else if (*str == 'p')
		return (minus_p(va_arg(args, unsigned long long), nbr));
	else if (*str == 'x')
		return (minus_x(va_arg(args, unsigned), nbr));
	else if (*str == 'X')
		return (minus_uppx(va_arg(args, unsigned), nbr));
	return (0);
}

int	space_x(va_list args, int nspace)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, unsigned long long);
	nspace -= len_hexa(nbr);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + conv_hexa_lowercase(nbr));
}

int	space_uppx(va_list args, int nspace)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, unsigned long long);
	nspace -= len_hexa(nbr);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + conv_hexa_uppercase(nbr));
}
