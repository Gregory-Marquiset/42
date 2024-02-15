/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:57:16 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 00:53:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s, int len)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	len = len + ft_strlen(s1);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free(s1);
	return (str);
}

int	contain_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == 10)
			return (1);
	return (0);
}

char	*print_line(char **tempo)
{
	int		i;
	char	*line;
	char	*str;

	if (!*tempo)
		return (NULL);
	str = *tempo;
	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	line = ft_strdup(str, i);
	*tempo = ft_strdup(str + i, ft_strlen(str + i));
	if (str)
		free(str);
	str = NULL;
	return (line);
}
