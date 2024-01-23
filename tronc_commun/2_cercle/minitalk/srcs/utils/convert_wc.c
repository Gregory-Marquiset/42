/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:43:21 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/23 08:28:01 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	ft_wctobu_110000(char *s, wchar_t wc)
{
	if (!s)
		return (0);
	s[0] = (char)(0xF0 | (wc >> 18));
	s[1] = (char)(0x80 | ((wc >> 12) & 0x3F));
	s[2] = (char)(0x80 | ((wc >> 6) & 0x3F));
	s[3] = (char)(0x80 | (wc & 0x3F));
	return (4);
}

int	ft_wctobu_10000(char *s, wchar_t wc)
{
	if (!s)
		return (0);
	s[0] = (char)(0xE0 | (wc >> 12));
	s[1] = (char)(0x80 | ((wc >> 6) & 0x3F));
	s[2] = (char)(0x80 | (wc & 0x3F));
	return (3);
}

int	ft_wctobu_800(char *s, wchar_t wc)
{
	if (!s)
		return (0);
	s[0] = (char)(0xC0 | (wc >> 6));
	s[1] = (char)(0x80 | (wc & 0x3F));
	return (2);
}

int	ft_wctobu_80(char *s, wchar_t wc)
{
	if (!s)
		return (0);
	*s = (char)wc;
	return (1);
}
