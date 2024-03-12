/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:57:04 by gmarquis          #+#    #+#             */
/*   Updated: 2023/12/26 12:07:28 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

//		get_next_line.c		//
char	*get_next_line(int fd);

//		get_next_line_utils.c		//
int		ft_strlen(char *str);
char	*ft_strdup(char *s, int len);
char	*ft_strjoin(char *s1, char *s2);
int		contain_n(char *str);
char	*print_line(char **tempo);

#endif
