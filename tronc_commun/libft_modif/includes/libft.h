/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:11:44 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 07:11:17 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <ctype.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//______________________Fonctions obligatoire de base

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

//_______________________Fonction obligatoire supplémentaires

char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c, char c2);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char *s1, char *s2, int flag);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);

//_______________________Fonction bonus

int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);

//_______________________Fonction ajouter

int					ft_absolute_nbr(int nbr);
int					ft_atoi_base(char *str, char *base);
long				ft_atol(char *input);
int					ft_base_length(char *base);
int					ft_base_verif(char *str, char *base);
int					ft_contain_n(char *str, char n);
int					ft_count_n(char *str, char n);
int					ft_countain_double(char **input);
size_t				ft_countuntil(char *str, char n);
int					ft_countwords(char *str, char set, char set2, char end);
void				ft_exit(int out, char *message);
void				ft_free_tab2d(char **input);
int					ft_isnbr(char *input);
int					ft_isexa(char *code);
int					ft_isint(char *clean_input);
char				*ft_memlcpy(char *s, size_t len);
char				*ft_strndup(char *s, int len);
void				ft_verif_extention(char *filename, char *exe);

//_______________________get next line

//		get_next_line.c			//
char				*print_line(char **tempo);
char				*get_next_line(int fd);

//_______________________Printf

//		fonction_1_bonus.c		//
int					redirection_dot(va_list args, char *str);
int					put_diu(va_list args, char *str);
int					minus_flag(va_list args, char *str, int nbr);
int					space_x(va_list args, int nspace);
int					space_uppx(va_list args, int nspace);

//		fonction_2_bonus.c		//
int					digit_dot_digit_flag(va_list args, char *str, int n1,
						int n2);
int					minus_digit_dot(va_list args, char *str, int n);
int					minus_digit_dot_digit(va_list args, char *str, int n1);
int					minus_digit_dot_digit_di(long long nbr, int n1, int n2);
int					minus_digit_dot_digit_u(unsigned int nbr, int n1, int n2);

//		fonction_3_bonus.c		//
int					minus_digit_dot_digit_x(unsigned long long nbr, int n1,
						int n2);
int					minus_digit_dot_digit_uppx(unsigned long long nbr, int n1,
						int n2);
int					minus_digit_dot_digit_s(char *str, int n1, int n2);
int					minus_digit_dot_s(char *str, int n);
int					minus_digit_dot_di(long long nbr, int n);

//		fonction_4_bonus.c		//
int					minus_digit_dot_u(unsigned int nbr, int n);
int					minus_digit_dot_x(unsigned long long nbr, int n);
int					minus_digit_dot_uppx(unsigned long long nbr, int n);
int					minus_c(int c, int n);
int					minus_s(char *str, int n);

//		fonction_5_bonus.c		//
int					minus_di(int nbr, int n);
int					minus_u(unsigned int nbr, int n);
int					minus_p(unsigned long long nbr, int n);
int					minus_x(unsigned long long nbr, int n);
int					minus_uppx(unsigned long long nbr, int n);

//		fonction_6_bonus.c		//
int					minus_dot(va_list args, char *str);
int					minus_dot_digit_di(long long nbr, int n);
int					minus_dot_digit_u(unsigned int nbr, int n);
int					minus_dot_digit_x(unsigned long long nbr, int n);
int					minus_dot_digit_uppx(unsigned long long nbr, int n);

//		fonction_7_bonus.c		//
int					digit_flag_space(va_list args, char *str, int nbr);
int					dot_digit(va_list args, char *str);
int					digit_dot(va_list args, char *str, int nbr);
int					dot_digit_flag(va_list args, char *str, int nbr);
int					dot_zero(va_list args, char *str);

//		fonction_8_bonus.c		//
int					digit_dot_digit(va_list args, char *str, int nbr);
int					zero_dot(va_list args, char *str);
int					zero_dot_digit_di(long long nbr, int n);
int					zero_dot_digit_u(long long nbr, int n);
int					zero_dot_digit_x(unsigned long long nbr, int n);

//		fonction_9_bonus.c		//
int					zero_dot_digit_uppx(unsigned long long nbr, int n);
int					zero_digit(va_list args, char *str);
int					zero_digit_dot(va_list args, char *str, int n);
int					zero_digit_dot_digit(va_list args, char *str, int n1);
int					zero_digit_dot_digit_di(long long nbr, int n1, int n2);

//		fonction_10_bonus.c		//
int					zero_digit_dot_digit_u(long long nbr, int n1, int n2);
int					zero_digit_dot_digit_x(unsigned long long nbr, int n1,
						int n2);
int					zero_digit_dot_digit_uppx(unsigned long long nbr, int n1,
						int n2);
int					zero_digit_dot_zero(va_list args, char *str, int n);
int					zero_digit_dot_zero_di(long long nbr, int n);

//		fonction_11_bonus.c		//
int					zero_digit_dot_zero_u(long long nbr, int n);
int					zero_digit_dot_zero_x(unsigned long long nbr, int n);
int					zero_digit_dot_zero_uppx(unsigned long long nbr, int n);
int					zero_digit_dot_di(long long nbr, int n);
int					zero_digit_dot_u(long long nbr, int n);

//		fonction_12_bonus.c		//
int					zero_digit_dot_x(unsigned long long nbr, int n);
int					zero_digit_dot_uppx(unsigned long long nbr, int n);
int					zero_digit_flag(va_list args, char *str, int n);
int					zero_digit_di(long long nbr, int n);
int					zero_digit_u(long long nbr, int n);

//		fonction_13_bonus.c		//

int					space_digit_s(char *str, int n);

//		fonction_digit_bonus.c		//
int					a_to_i(char *str);
int					digit(va_list args, char *str);
int					le_z(va_list args, char *str);
int					put_dot(int nbr);
int					put_str_n(char *str, int n);

//		fonction_espace_bonus.c	//
int					space_c(va_list args, int nspace);
int					space_s(va_list args, int nspace);
int					space_di(va_list args, int nspace);
int					space_u(va_list args, int nspace);
int					space_p(va_list args, int nspace);

//		fonction_dot_bonus.c	//
int					dot_s(va_list args, int n);
int					dot_di(va_list args, int n);
int					dot_u(va_list args, int n);
int					dot_x(va_list args, int n);
int					dot_uppx(va_list args, int n);

//		fonction_hexa_bonus.c		//
int					conv_hexa_lowercase(unsigned long long nbr);
int					conv_hexa_uppercase(unsigned long long nbr);
int					adress_lowercase(unsigned long long adrs);
int					adress_uppercase(unsigned long long adrs);
int					adress(unsigned long long adrs);

//		fonction_len_bonus.c	//
int					len_flag(char *str);
int					len_str(char *str);
int					len_nbr(long long nbr);
int					len_hexa(unsigned long long nbr);
int					len_adress(unsigned long long nbr);

//		fonction_put_bonus.c		//
int					put_char(int c);
int					put_str(char *str);
int					put_nbr(long long nbr);
int					put_espace_di(int nbr);
int					put_plus(int nbr);

//		fonction_symbol_bonus.c		//
int					sharp(va_list args, char *str);
int					space(va_list args, char *str);
int					plus(va_list args, char *str);
int					le_dot(va_list args, char *str);
int					minus(va_list args, char *str);

//		fonction_verif_bonus.c		//
int					is_flag(char c);
int					is_digit(char c);
int					is_symbol(char c);
int					zero_digit_x(unsigned long long nbr, int n);
int					zero_digit_uppx(unsigned long long nbr, int n);

//		ft_printf.c					//
int					redirection(va_list args, char *str);
int					symbol(va_list args, char *str);
int					reading(va_list args, char *str);
int					ft_printf(const char *s, ...);

#endif
