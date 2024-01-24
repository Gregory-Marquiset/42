/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:07 by greg              #+#    #+#             */
/*   Updated: 2024/01/23 16:40:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_is_tnvfr(char c)
{
	if (c == 't' || c == 'n' || c == 'v' || c == 'f' || c == 'r')
		return (1);
	return (0);
}

void	conv_chara(char *argv)
{
	int		i;
	int		len;
//	char	*str;

	i = 0;
	len = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '\\' && ft_is_tnvfr(argv[i + 1]))
				i++;
		i++;
		len++;
	}
	ft_printf("%d\n", len);
	ft_printf("%s", argv);
	return ;
}

int	main(int argc, char **argv)
{
	pid_t	pid;
//	int		i;

	if (argc != 3)
		return (ft_printf("The correct format is ./client pid array\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (ft_printf("Invalide pid !\n"), 0);
	conv_chara(argv[2]);
//	i = 0;
//	while (argv[2][i])
//		client_send_char(argv[2][i++], pid);
//	client_send_char('\0', pid);
	return (0);
}
