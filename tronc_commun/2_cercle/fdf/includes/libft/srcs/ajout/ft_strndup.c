/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:28:42 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:18 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(char *s, int len)
{
	char	*str;
	int		count;

	if (!s || !len)
		return (NULL);
	count = 0;
	str = malloc((len + 1));
	while (count < len)
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
