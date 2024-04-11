/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:10:03 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 19:23:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_freetab(char **str, unsigned int i)
{
	unsigned int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return ;
}

static char	*ft_strlcpymem(char *s, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s || len == 0)
		return (0);
	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_tabsize(char *s, char c, char c2)
{
	unsigned int	i;
	unsigned int	tabcount;

	if (!s || !c || !c2)
		return (0);
	i = 0;
	tabcount = 0;
	if (s[i] == c || s[i] == c2)
		i++;
	while (s[i] != c && s[i])
	{
		if (s[i] == c2)
			break ;
		tabcount++;
		i++;
	}
	return (tabcount);
}

static int	ft_movestr(char *str, char c, char c2)
{
	int	i;

	if (!str || !c || !c2)
		return (0);
	i = 0;
	while (str[i] != c && str[i])
	{
		if (str[i] == c2)
			break ;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c, char c2)
{
	int		i;
	int		counttab;
	char	**str;
	char	*strtemp;

	i = 0;
	if (!s || s[0] == '\0' || !c || !c2)
		return (NULL);
	counttab = ft_countwords((char *)s, c, c2, '\0');
	strtemp = (char *)s;
	str = (char **)malloc((counttab + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < counttab && strtemp[0] != '\0')
	{
		while (*strtemp == c || *strtemp == c2)
			strtemp++;
		str[i] = ft_strlcpymem(strtemp, ft_tabsize(strtemp, c, c2));
		if (!str[i])
			return (ft_freetab(str, i), NULL);
		strtemp += ft_movestr(strtemp, c, c2);
		i++;
	}
	return (str[i] = NULL, str);
}
