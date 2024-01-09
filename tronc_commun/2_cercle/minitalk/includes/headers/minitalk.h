/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greg <greg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:16:38 by greg              #+#    #+#             */
/*   Updated: 2024/01/08 17:32:59 by greg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

//		client.c		//
int		ft_is_digit(char c);
int		ft_is_space(char c);
int		ft_atoi(char *str);
void	client_send_char(char c, pid_t pid);

//		server.c		//
int		ft_str_len(char *str);
char	*ft_memcpy(char *str, char c);
void	ctoa(char c);
void	bytoc(int received);

#endif
