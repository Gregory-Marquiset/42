/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:56:48 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/09 00:51:44 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*tempo;
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(tempo), tempo = NULL, NULL);
	if (contain_n(tempo))
		return (print_line(&tempo));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		tempo = ft_strjoin(tempo, buffer);
		if (contain_n(tempo))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&tempo));
}
