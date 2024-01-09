/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/01/08 17:45:43 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/minitalk.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	rslt;
	int	sign;

	i = 0;
	rslt = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		rslt = rslt * 10 + (str[i] - '0');
		i++;
	}
	return (rslt * sign);
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
		usleep(100);
		i--;
	}
}
/*
int	main(int argc, char **argv)
{
	pid_t	pid;
	int	i;

	if (argc != 3)
		return (ft_printf("Invalid number of arguments !\nThe correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return(ft_printf("Invalide pid !\n"), 0);
	i = 0;
	while (argv[2][i])
	{
		client_send_char(argv[2][i], pid);
		i++;
	}
	client_send_char('\0', pid);
	return (0);
}
*/
