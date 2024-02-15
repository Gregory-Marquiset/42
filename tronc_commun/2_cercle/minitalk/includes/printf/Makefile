# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:45:40 by greg              #+#    #+#              #
#    Updated: 2024/01/23 07:42:36 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/fonction_1_bonus.c $\
srcs/fonction_2_bonus.c $\
srcs/fonction_3_bonus.c $\
srcs/fonction_4_bonus.c $\
srcs/fonction_5_bonus.c $\
srcs/fonction_6_bonus.c $\
srcs/fonction_7_bonus.c $\
srcs/fonction_8_bonus.c $\
srcs/fonction_9_bonus.c $\
srcs/fonction_10_bonus.c $\
srcs/fonction_11_bonus.c $\
srcs/fonction_12_bonus.c $\
srcs/fonction_13_bonus.c $\
srcs/fonction_digit_bonus.c $\
srcs/fonction_space_bonus.c $\
srcs/fonction_dot_bonus.c $\
srcs/fonction_hexa_bonus.c $\
srcs/fonction_len_bonus.c $\
srcs/fonction_put_bonus.c $\
srcs/fonction_symbol_bonus.c $\
srcs/fonction_verif_bonus.c $\
srcs/ft_printf.c

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = libftprintf.a

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : srcs/%.c includes/ft_printf.h
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	@ar r $@ $^

all : $(NAME)

bonus : all

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
