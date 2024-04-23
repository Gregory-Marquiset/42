/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_space_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:37:16 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:58 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	space_c(va_list args, int nspace)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (len < nspace - 1)
	{
		i += put_char(' ');
		len++;
	}
	return (i + put_char(va_arg(args, int)));
}

int	space_s(va_list args, int nspace)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	str = va_arg(args, char *);
	if (nspace <= 6 && !str)
		return (put_str("(null)"), 6);
	nspace -= len_str(str);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + put_str(str));
}

int	space_di(va_list args, int nspace)
{
	int	i;
	int	len;
	int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, int);
	nspace -= len_nbr(nbr);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + put_nbr(nbr));
}

int	space_u(va_list args, int nspace)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, int);
	nspace -= len_nbr(nbr);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + put_nbr(nbr));
}

int	space_p(va_list args, int nspace)
{
	int					i;
	int					len;
	unsigned long long	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, unsigned long long);
	if (nspace <= 5 && !nbr)
		return (put_str("(nil)"), 5);
	nspace -= len_adress(nbr);
	while (len < nspace)
	{
		i += put_char(' ');
		len++;
	}
	return (i + adress(nbr));
}
