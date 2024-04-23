/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_put_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:30:54 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:51 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		put_str("(null)");
		return (6);
	}
	while (str[i])
	{
		i += put_char(str[i]);
	}
	return (i);
}

int	put_nbr(long long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i += put_char('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		i += put_nbr(nbr / 10);
		i += put_nbr(nbr % 10);
	}
	if (nbr < 10)
	{
		i += put_char(nbr + '0');
	}
	return (i);
}

int	put_espace_di(int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
		i += put_char(' ');
	i += put_nbr(nbr);
	return (i);
}

int	put_plus(int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
		i += put_char('+');
	i += put_nbr(nbr);
	return (i);
}
