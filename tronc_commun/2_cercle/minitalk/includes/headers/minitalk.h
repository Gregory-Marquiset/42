/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:16:38 by greg              #+#    #+#             */
/*   Updated: 2024/01/18 11:17:02 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <locale.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <wchar.h>

//		check_pid.c			//
int		ft_is_digit(char c);
int		ft_is_space(char c);
int		ft_atoi(char *str);

//		client_b_utils.c	//
void	wctoestr(const wchar_t *src, char *dst);
int		ft_is_ascii(unsigned char c);
int		ft_is_multi_byte(unsigned char c);
wchar_t	asciitowc(unsigned char c);
wchar_t	mbytowc(const char *input, int len);

//		convert_wc.c		//
int		ft_wctobu_110000(char *s, wchar_t wc);
int		ft_wctobu_10000(char *s, wchar_t wc);
int		ft_wctobu_800(char *s, wchar_t wc);
int		ft_wctobu_80(char *s, wchar_t wc);

//		server_b_utils.c	//
void	ft_putwchar(wchar_t wc);
void	ft_putwstr(wchar_t *wstr);
wchar_t	hexatowc(char *str);
wchar_t	*strtowstr(int len, char *str);
void	strto(char *str);

//		utils.c				//
int		ft_strlen(char *str);
char	*ft_memcpy(char *str, char c);
int		ft_is_hexa(char c);
int		containe_unicode(char *str);
void	client_send_char(char c, pid_t pid);

#endif
