/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:25:23 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/11 00:53:05 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif


# include "libft/includes/libft.h"
# include "struct.h"
#include <sys/wait.h>

//		main.c      //

//		end.c		//
void	ft_out(t_data *data, char *message, int flag);

#endif
