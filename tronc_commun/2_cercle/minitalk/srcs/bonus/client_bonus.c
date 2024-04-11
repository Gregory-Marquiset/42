/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/11 01:49:37 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static void	valid_send(int i)
{
	static int (bytes) = 0;
	static int (chars) = 1;
	if ((i == SIGUSR1 && bytes % 7 != 0) || (i == SIGUSR1 && bytes == 0))
	{
		ft_printf("char %2d | Byte %3d | answer valide !\n", chars, bytes);
		bytes++;
	}
	else
	{
		ft_printf("char %2d | Byte %3d | answer valide !\n", chars, bytes);
		chars++;
		bytes = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
		return (ft_printf("The correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (ft_printf("Invalide pid !\n"), 0);
	signal(SIGUSR1, valid_send);
	i = 0;
	while (argv[2][i])
		client_send_char(argv[2][i++], pid);
	client_send_char('\0', pid);
	return (0);
}
