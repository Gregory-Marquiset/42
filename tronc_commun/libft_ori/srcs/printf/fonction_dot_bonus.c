/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_dot_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 06:37:16 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:46:41 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	dot_s(va_list args, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (n < 6 && str == NULL)
		return (0);
	if (n >= 6 && str == NULL)
		return (put_str("(null)"), 6);
	if (n <= len_str(str))
	{
		while (i < n)
			i += put_char(str[i]);
	}
	else if (n > len_str(str))
		return (put_str(str));
	return (i);
}

int	dot_di(va_list args, int n)
{
	int			i;
	int			len;
	long long	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, int);
	if (n == 0)
		return (i + put_nbr(nbr));
	n -= len_nbr(nbr);
	if (nbr < 0)
	{
		i += put_char('-');
		nbr = -nbr;
		len--;
	}
	while (len < n)
	{
		i += put_char('0');
		len++;
	}
	return (i + put_nbr(nbr));
}

int	dot_u(va_list args, int n)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, int);
	if (n == 0)
		return (i + put_nbr(nbr));
	n -= len_nbr(nbr);
	while (len < n)
	{
		i += put_char('0');
		len++;
	}
	return (i + put_nbr(nbr));
}

int	dot_x(va_list args, int n)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, unsigned long long);
	n -= len_hexa(nbr);
	while (len < n)
	{
		i += put_char('0');
		len++;
	}
	return (i + conv_hexa_lowercase(nbr));
}

int	dot_uppx(va_list args, int n)
{
	int				i;
	int				len;
	unsigned int	nbr;

	i = 0;
	len = 0;
	nbr = va_arg(args, unsigned long long);
	n -= len_hexa(nbr);
	while (len < n)
	{
		i += put_char('0');
		len++;
	}
	return (i + conv_hexa_uppercase(nbr));
}
