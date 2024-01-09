/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:57:03 by gmarquis          #+#    #+#             */
/*   Updated: 2023/12/14 17:57:30 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//		fonction_1_bonus.c		//
int	redirection_dot(va_list args, char *str);
int	put_diu(va_list args, char *str);
int	minus_flag(va_list args, char *str, int nbr);
int	space_x(va_list args, int nspace);
int	space_uppx(va_list args, int nspace);

//		fonction_2_bonus.c		//
int	digit_dot_digit_flag(va_list args, char *str, int n1, int n2);
int	minus_digit_dot(va_list args, char *str, int n);
int	minus_digit_dot_digit(va_list args, char *str, int n1);
int	minus_digit_dot_digit_di(long long nbr, int n1, int n2);
int	minus_digit_dot_digit_u(unsigned int nbr, int n1, int n2);

//		fonction_3_bonus.c		//
int	minus_digit_dot_digit_x(unsigned long long nbr, int n1, int n2);
int	minus_digit_dot_digit_uppx(unsigned long long nbr, int n1, int n2);
int	minus_digit_dot_digit_s(char *str, int n1, int n2);
int	minus_digit_dot_s(char *str, int n);
int	minus_digit_dot_di(long long nbr, int n);

//		fonction_4_bonus.c		//
int	minus_digit_dot_u(unsigned int nbr, int n);
int	minus_digit_dot_x(unsigned long long nbr, int n);
int	minus_digit_dot_uppx(unsigned long long nbr, int n);
int	minus_c(int c, int n);
int	minus_s(char *str, int n);

//		fonction_5_bonus.c		//
int	minus_di(int nbr, int n);
int	minus_u(unsigned int nbr, int n);
int	minus_p(unsigned long long nbr, int n);
int	minus_x(unsigned long long nbr, int n);
int	minus_uppx(unsigned long long nbr, int n);

//		fonction_6_bonus.c		//
int	minus_dot(va_list args, char *str);
int	minus_dot_digit_di(long long nbr, int n);
int	minus_dot_digit_u(unsigned int nbr, int n);
int	minus_dot_digit_x(unsigned long long nbr, int n);
int	minus_dot_digit_uppx(unsigned long long nbr, int n);

//		fonction_7_bonus.c		//
int	digit_flag_space(va_list args, char *str, int nbr);
int	dot_digit(va_list args, char *str);
int	digit_dot(va_list args, char *str, int nbr);
int	dot_digit_flag(va_list args, char *str, int nbr);
int	dot_zero(va_list args, char *str);

//		fonction_8_bonus.c		//
int	digit_dot_digit(va_list args, char *str, int nbr);
int	zero_dot(va_list args, char *str);
int	zero_dot_digit_di(long long nbr, int n);
int	zero_dot_digit_u(long long nbr, int n);
int	zero_dot_digit_x(unsigned long long nbr, int n);

//		fonction_9_bonus.c		//
int	zero_dot_digit_uppx(unsigned long long nbr, int n);
int	zero_digit(va_list args, char *str);
int	zero_digit_dot(va_list args, char *str, int n);
int	zero_digit_dot_digit(va_list args, char *str, int n1);
int	zero_digit_dot_digit_di(long long nbr, int n1, int n2);

//		fonction_10_bonus.c		//
int	zero_digit_dot_digit_u(long long nbr, int n1, int n2);
int	zero_digit_dot_digit_x(unsigned long long nbr, int n1, int n2);
int	zero_digit_dot_digit_uppx(unsigned long long nbr, int n1, int n2);
int	zero_digit_dot_zero(va_list args, char *str, int n);
int	zero_digit_dot_zero_di(long long nbr, int n);

//		fonction_11_bonus.c		//
int	zero_digit_dot_zero_u(long long nbr, int n);
int	zero_digit_dot_zero_x(unsigned long long nbr, int n);
int	zero_digit_dot_zero_uppx(unsigned long long nbr, int n);
int	zero_digit_dot_di(long long nbr, int n);
int	zero_digit_dot_u(long long nbr, int n);

//		fonction_12_bonus.c		//
int	zero_digit_dot_x(unsigned long long nbr, int n);
int	zero_digit_dot_uppx(unsigned long long nbr, int n);
int	zero_digit_flag(va_list args, char *str, int n);
int	zero_digit_di(long long nbr, int n);
int	zero_digit_u(long long nbr, int n);

//		fonction_13_bonus.c		//

int	space_digit_s(char *str, int n);

//		fonction_digit_bonus.c		//
int	a_to_i(char *str);
int	digit(va_list args, char *str);
int	le_z(va_list args, char *str);
int	put_dot(int nbr);
int	put_str_n(char *str, int n);

//		fonction_espace_bonus.c	//
int	space_c(va_list args, int nspace);
int	space_s(va_list args, int nspace);
int	space_di(va_list args, int nspace);
int	space_u(va_list args, int nspace);
int	space_p(va_list args, int nspace);

//		fonction_dot_bonus.c	//
int	dot_s(va_list args, int n);
int	dot_di(va_list args, int n);
int	dot_u(va_list args, int n);
int	dot_x(va_list args, int n);
int	dot_uppx(va_list args, int n);

//		fonction_hexa_bonus.c		//
int	conv_hexa_lowercase(unsigned long long nbr);
int	conv_hexa_uppercase(unsigned long long nbr);
int	adress_lowercase(unsigned long long adrs);
int	adress_uppercase(unsigned long long adrs);
int	adress(unsigned long long adrs);

//		fonction_len_bonus.c	//
int	len_flag(char *str);
int	len_str(char *str);
int	len_nbr(long long nbr);
int	len_hexa(unsigned long long nbr);
int	len_adress(unsigned long long nbr);

//		fonction_put_bonus.c		//
int	put_char(int c);
int	put_str(char *str);
int	put_nbr(long long nbr);
int	put_espace_di(int nbr);
int	put_plus(int nbr);

//		fonction_symbol_bonus.c		//
int	sharp(va_list args, char *str);
int	space(va_list args, char *str);
int	plus(va_list args, char *str);
int	le_dot(va_list args, char *str);
int	minus(va_list args, char *str);

//		fonction_verif_bonus.c		//
int	is_flag(char c);
int	is_digit(char c);
int	is_symbol(char c);
int	zero_digit_x(unsigned long long nbr, int n);
int	zero_digit_uppx(unsigned long long nbr, int n);

//		ft_printf.c					//
int	redirection(va_list args, char *str);
int	symbol(va_list args, char *str);
int	reading(va_list args, char *str);
int	ft_printf(const char *s, ...);

#endif
