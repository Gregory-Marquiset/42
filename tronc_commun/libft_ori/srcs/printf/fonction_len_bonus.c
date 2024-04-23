/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_len_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:02:26 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:48 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	len_flag(char *str)
{
	int	len;

	len = 0;
	if (*str == '%')
		return (++len);
	while (*str && (!(is_flag(*str))))
	{
		if (*str == '%')
			return (++len);
		str++;
		len++;
	}
	return (++len);
}

int	len_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (6);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	len_nbr(long long nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	len_hexa(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr < 16)
		return (1);
	if (nbr >= 16)
	{
		i += len_hexa(nbr / 16);
		i += len_hexa(nbr % 16);
	}
	return (i);
}

int	len_adress(unsigned long long nbr)
{
	int	i;

	i = 2;
	if (nbr == 0)
		return (5);
	if (nbr < 16)
		return (3);
	if (nbr >= 16)
	{
		i += len_hexa(nbr / 16);
		i += len_hexa(nbr % 16);
	}
	return (i);
}
