/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_b_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:14:52 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/18 11:52:45 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

void	wctoestr(const wchar_t *src, char *dst)
{
	int		shift;
	char	hexa_digit;

	while (*src != L'\0')
	{
		if (*src >= 32 && *src <= 126)
			*dst++ = (char)(*src);
		else
		{
			*dst++ = '\\';
			*dst++ = 'u';
			shift = 12;
			while (shift >= 0)
			{
				hexa_digit = (*src >> shift) & 0xF;
				*dst = hexa_digit < 10 ? '0' + hexa_digit : 'A' + (hexa_digit - 10);		//		a virer
				dst++;
				shift -= 4;
			}
		}
		src++;
	}
	*dst = '\0';
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
