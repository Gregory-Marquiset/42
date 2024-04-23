/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:57:04 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 14:22:50 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef FDS
#  define FDS 1024
# endif

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
# include "../../../libft_modif/includes/libft.h"

typedef struct	s_gnl
{
	char		static_l[FDS][BUFFER_SIZE];
	int			fd;
	char		n;
	char		buffer[BUFFER_SIZE];
	char		*tempo;
	int			o_read;
	char		l_to_print[4];
}				t_gnl;

//		get_next_line.c		//
char	*get_next_line_modif(int fd, char n);

#endif
