/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_5_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 00:43:58 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	minus_di(int nbr, int n)
{
	int	i;

	i = 0;
	n -= len_nbr(nbr);
	i += put_nbr(nbr);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_u(unsigned int nbr, int n)
{
	int	i;

	i = 0;
	n -= len_nbr(nbr);
	i += put_nbr(nbr);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_p(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_adress(nbr);
	if (n < 0)
		return (i += adress(nbr));
	i += adress(nbr);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_x(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	i += conv_hexa_lowercase(nbr);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}

int	minus_uppx(unsigned long long nbr, int n)
{
	int	i;

	i = 0;
	n -= len_hexa(nbr);
	i += conv_hexa_uppercase(nbr);
	while (n-- > 0)
		i += put_char(' ');
	return (i);
}
