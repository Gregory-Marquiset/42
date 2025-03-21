/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/11 01:48:29 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (ft_printf("The correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (ft_printf("Invalide pid !\n"), 0);
	i = 0;
	while (argv[2][i])
		client_send_char(argv[2][i++], pid);
	client_send_char('\0', pid);
	return (0);
}
