/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:45:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	minus_digit_dot_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr != 0)
	{
		i += conv_hexa_lowercase(nbr);
		n--;
	}
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	if (nbr != 0)
	{
		i += conv_hexa_uppercase(nbr);
		n--;
	}
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_digit_dot_s(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return (i += put_str(str));
	i += put_str(str);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_c(int c, int n)
{
	int	i;

	i = 0;
	i += put_char(c);
	n -= 1;
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_s(char *str, int n)
{
	int	i;

	i = 0;
	n -= len_str(str);
	i += put_str(str);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}
