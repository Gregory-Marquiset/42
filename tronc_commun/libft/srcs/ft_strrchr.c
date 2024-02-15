/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:12 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 01:04:16 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chara;

	i = 0;
	chara = c;
	while (s[i])
		i++;
	while (s[i] >= 0)
	{
		if (s[i] == chara)
			return ((char *)s + i);
		if (i == 0 && s[i] != chara)
			return (0);
		i--;
	}
	return (0);
}
