/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_hexa_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:28 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:45 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	conv_hexa_lowercase(unsigned long long nbr)
{
	int		i;
	char	*base_examin;

	i = 0;
	base_examin = "0123456789abcdef";
	if (nbr == 0)
		return (i += put_char('0'));
	if (nbr < 16)
		i += put_char(base_examin[nbr]);
	if (nbr >= 16)
	{
		i += conv_hexa_lowercase(nbr / 16);
		i += conv_hexa_lowercase(nbr % 16);
	}
	return (i);
}

int	conv_hexa_uppercase(unsigned long long nbr)
{
	int		i;
	char	*base_examaj;

	i = 0;
	base_examaj = "0123456789ABCDEF";
	if (nbr == 0)
		return (i += put_char('0'));
	if (nbr < 16)
		i += put_char(base_examaj[nbr]);
	if (nbr >= 16)
	{
		i += conv_hexa_uppercase(nbr / 16);
		i += conv_hexa_uppercase(nbr % 16);
	}
	return (i);
}

int	adress_lowercase(unsigned long long adrs)
{
	int		i;
	char	*base_hexa;

	i = 0;
	base_hexa = "0123456789abcdef";
	if (adrs == 0)
		i += put_char('0');
	if (adrs != 0)
	{
		i += put_char('0');
		i += put_char('x');
		if (adrs == 0)
			i += put_char(0);
		if (adrs < 16)
			i += put_char(base_hexa[adrs]);
		if (adrs >= 16)
		{
			i += conv_hexa_lowercase(adrs / 16);
			i += conv_hexa_lowercase(adrs % 16);
		}
	}
	return (i);
}

int	adress_uppercase(unsigned long long adrs)
{
	int		i;
	char	*base_hexa;

	i = 0;
	base_hexa = "0123456789ABCDEF";
	if (adrs == 0)
		i += put_char('0');
	if (adrs != 0)
	{
		i += put_char('0');
		i += put_char('X');
		if (adrs < 16)
			i += put_char(base_hexa[adrs]);
		if (adrs >= 16)
		{
			i += conv_hexa_uppercase(adrs / 16);
			i += conv_hexa_uppercase(adrs % 16);
		}
	}
	return (i);
}

int	adress(unsigned long long adrs)
{
	int		i;
	char	*base_hexa;

	i = 0;
	base_hexa = "0123456789abcdef";
	if (!adrs)
	{
		put_str("(nil)");
		return (5);
	}
	i += put_char('0');
	i += put_char('x');
	if (adrs < 16)
		i += put_char(base_hexa[adrs]);
	if (adrs >= 16)
	{
		i += conv_hexa_lowercase(adrs / 16);
		i += conv_hexa_lowercase(adrs % 16);
	}
	return (i);
}
