/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:57:24 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 12:18:49 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

//		get_next_line_bonus.c		//
char	*get_next_line(int fd);

//		get_next_line_utils_bonus.c		//
int		ft_strlen(char *str);
char	*ft_strdup(char *s, int len);
char	*ft_strjoin(char *s1, char *s2);
int		contain_n(char *str, char n);
char	*print_line(char **tempo);

#endif
