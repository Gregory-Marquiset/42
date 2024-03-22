/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:33:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/25 06:54:16 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

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

void	ctoa(char c)
{
	static char	*str;
	static int	new_str = 0;

	if (new_str == 0)
	{
		str = malloc(2);
		str[0] = c;
		str[1] = '\0';
		new_str = 1;
	}
	else if (c != '\0')
		str = ft_memcpy(str, c);
	else
	{
		ft_printf("%s", str);
		new_str = 0;
		free(str);
	}
}

void	bytoc(int received)
{
	static int (i) = 0;
	static char (c) = 0;
	if (received == SIGUSR2)
		c += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ctoa(c);
		i = 0;
		c = 0;
	}
}
