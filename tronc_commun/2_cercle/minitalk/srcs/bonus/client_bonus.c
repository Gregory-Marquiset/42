/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/01/08 20:38:17 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/minitalk.h"


static void	valid_send(int i)
{
	static int bytes = 1;
	static int chars = 0;

	if (i == SIGUSR1 && bytes % 8 != 0)
		ft_printf("Char %2d | Byte %3d | signal answer valide !\n", chars, bytes);
	else if (i == SIGUSR1 && bytes % 8 == 0)
	{
		chars++;
		ft_printf("Char %2d | Byte %3d | signal answer valide !\n", chars, bytes);
	}
	bytes++;
}

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
	signal(SIGUSR1, valid_send);
	while (argv[2][i])
	{
		client_send_char(argv[2][i], pid);
		i++;
	}
	client_send_char('\0', pid);
	return (0);
}
