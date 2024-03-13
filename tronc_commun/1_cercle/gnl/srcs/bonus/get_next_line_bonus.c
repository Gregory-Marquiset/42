/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:57:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 12:18:32 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*tempo[1024];
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(tempo[fd]), tempo[fd] = NULL, NULL);
	if (contain_n(tempo[fd], '\n'))
		return (print_line(&tempo[fd]));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = 0;
		tempo[fd] = ft_strjoin(tempo[fd], buffer);
		if (contain_n(tempo[fd], '\n'))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (print_line(&tempo[fd]));
}
