/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:56:48 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/26 03:14:01 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_find_n(char *s, ssize_t *len, char n)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != n)
		i++;
	if (s[i] == n)
		return (*len += i + 1, 1);
	*len += i;
	return (0);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		++i;
	}
	if (size)
		dst[i] = 0;
}

int	ft_read_file(int fd, t_string *string, char n)
{
	ssize_t	read_return;
	ssize_t	return_l;
	char	*tmp;

	return_l = 0;
	read_return = BUFFER_SIZE;
	while (!ft_find_n(string->content + return_l, &return_l, n) && read_return == BUFFER_SIZE)
	{
		if (string->len + BUFFER_SIZE >= string->max_size)
		{
			tmp = malloc(string->max_size * 2);
			if (!tmp)
				return (-1);
			ft_strlcpy(tmp, string->content, string->len + 1);
			free(string->content);
			string->content = tmp;
			string->max_size *= 2;
		}
		read_return = read(fd, string->content + string->len, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		string->len += read_return;
		string->content[string->len] = 0;
	}
	return (return_l);
}

char	*get_next_line(int fd, char n)
{
	ssize_t		line_len;
	char		*return_l;
	t_string	string;
	static char	static_l[FD][BUFFER_SIZE] = {0};

	if (fd >= FD || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	string.max_size = BUFFER_SIZE + 1;
	string.content = malloc(string.max_size);
	if (!string.content)
		return (NULL);
	string.len = 0;
	while (static_l[fd][string.len])
		string.len++;
	ft_strlcpy(string.content, static_l[fd], string.len + 1);
	line_len = ft_read_file(fd, &string, n);
	if (line_len == -1 || !*string.content)
		return (free(string.content), NULL);
	return_l = malloc(line_len + 1);
	if (!return_l)
		return (free(string.content), NULL);
	ft_strlcpy(return_l, string.content, line_len + 1);
	ft_strlcpy(static_l[fd], string.content + line_len, string.len - line_len + 1);
	return (free(string.content), return_l);
}
