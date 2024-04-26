/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:51:41 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/25 16:09:11 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_exit(int out, char *message)
{
	int	len;

	len = ft_strlen(message);
	if (!message || len == 0 || out > 2 || out < 1)
	{
		write(2, "Error or undefined message.\n", 28);
		exit(EXIT_FAILURE);
	}
	write(out, message, len);
	if (out == 2)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
