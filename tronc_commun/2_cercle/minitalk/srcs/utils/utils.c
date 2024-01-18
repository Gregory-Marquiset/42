/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:33:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/18 11:41:21 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *str, char c)
{
	int		len;
	char	*new;
	int		i;

	len = ft_strlen(str) + 2;
	new = malloc(len);
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	i++;
	new[i] = '\0';
	free(str);
	return (new);
}

int	ft_is_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	return (0);
}

int	containe_unicode(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] == 'u')
		{
			i += 2;
			if (ft_is_hexa(str[i]) && ft_is_hexa(str[i + 1])
				&& ft_is_hexa(str[i + 2]) && ft_is_hexa(str[i + 3]))
				return (1);
		}
		i++;
	}
	return (0);
}

void	client_send_char(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(1500);
		i--;
	}
}
