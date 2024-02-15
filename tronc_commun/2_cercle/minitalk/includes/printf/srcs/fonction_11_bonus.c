/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_11_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:33:20 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 00:44:20 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	zero_digit_dot_zero_u(long long nbr, int n)
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

int	zero_digit_dot_zero_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		while (i < n)
			i += put_char(' ');
		return (i);
	}
	n -= len_hexa(nbr);
	if (n-- > 0)
		i += put_char(' ');
	return (i += conv_hexa_lowercase(nbr));
}

int	zero_digit_dot_zero_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		while (i < n)
			i += put_char(' ');
		return (i);
	}
	n -= len_hexa(nbr);
	if (n-- > 0)
		i += put_char(' ');
	return (i += conv_hexa_uppercase(nbr));
}

int	zero_digit_dot_di(long long nbr, int n)
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
	while (n-- > 0)
		i += put_char(' ');
	return (i += put_nbr(nbr));
}

int	zero_digit_dot_u(long long nbr, int n)
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
	while (n-- > 0)
		i += put_char(' ');
	return (i += put_nbr(nbr));
}
