/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:14:52 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/19 11:10:48 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

int	ft_uclen(unsigned char uc)
{
	int	len;

	len = 0;
	if (uc < 0xE0)
		len = 2;
	else
	{
		if (uc < 0xF0)
			len = 3;
		else
			len = 4;
	}
	return (len);
}

int	ft_is_ascii(unsigned char c)
{
	return (c < 0x80);
}

int	ft_is_multi_byte(unsigned char c)
{
	return ((c & 0xE0) == 0xC0 || (c & 0xF0) == 0xE0 || (c & 0xF8) == 0xF0);
}

wchar_t	asciitowc(unsigned char c)
{
	return (c);
}

wchar_t	mbytowc(const char *input, int len)
{
	wchar_t	wc;
	int		i;

	wc = (unsigned char)input[0] & (0xFF >> (len + 1));
	i = 1;
	while (i < len)
	{
		wc = wc << 6;
		wc |= (unsigned char)input[i] & 0x3F;
		i++;
	}
	return (wc);
}
