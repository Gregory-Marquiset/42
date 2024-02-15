/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:06:59 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:03:07 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*str;
	char		*dst;

	if ((dest == src) || n == 0)
		return (dest);
	str = (const char *)src;
	dst = (char *)dest;
	while (n--)
		*dst++ = *str++;
	return (dest);
}
