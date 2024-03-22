/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:16:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/01/24 21:35:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/includes/ft_printf.h"
# include <locale.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <wchar.h>

//		check_pid.c			//
int		ft_is_digit(char c);
int		ft_is_space(char c);
int		ft_atoi(char *str);

//		utils.c				//
int		ft_strlen(char *str);
char	*ft_memcpy(char *str, char c);
void	client_send_char(char c, pid_t pid);
void	ctoa(char c);
void	bytoc(int received);

#endif
