/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:34:43 by greg              #+#    #+#             */
/*   Updated: 2024/01/08 23:35:05 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minitalk.h"

int	ft_str_len(char *str)
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

	len = ft_str_len(str) + 2;
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
	else if (c >= 32 && c <= 126)
		str = ft_memcpy(str, c);
	else if (c == '\0')
	{
		ft_printf("%s", str);
		new_str = 0;
		free(str);
	}
}

void	bytoc(int received)
{
	static int	i = 0;
	static char	c = 0;

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
/*
int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc > 1 || argv[1])
		return (ft_printf("Too many arguments !\n"), 0);
	pid = getpid();
	ft_printf("The pid of this server is %d\n", pid);
	signal(SIGUSR2, bytoc);
	signal(SIGUSR1, bytoc);
	while (117)
		;
}
*/
