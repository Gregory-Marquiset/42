/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:07 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:04:13 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	index;

	index = 0;
	if (!big && !len)
		return (0);
	if (!*little)
		return ((char *)big);
	while (big[index] && index < len)
	{
		if (big[index] == little[0])
		{
			i = 1;
			while (little[i] && little[i] == big[i + index] && (index
					+ i) < len)
				i++;
			if (little[i] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (0);
}
