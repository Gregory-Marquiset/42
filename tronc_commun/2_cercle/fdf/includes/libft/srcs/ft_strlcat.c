/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:35 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:03:55 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	len_dst;
	unsigned long	len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = len_dst;
	j = 0;
	if (size > len_dst)
	{
		while (src[j] && j < size - len_dst - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (size < len_dst)
		return (size + len_src);
	return (len_dst + len_src);
}
