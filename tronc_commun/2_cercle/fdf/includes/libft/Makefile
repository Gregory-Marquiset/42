# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 17:10:22 by gmarquis          #+#    #+#              #
#    Updated: 2024/04/12 04:33:26 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_bzero.c $\
srcs/ft_isalpha.c $\
srcs/ft_isprint.c $\
srcs/ft_memcmp.c $\
srcs/ft_memset.c $\
srcs/ft_putnbr_fd.c $\
srcs/ft_strchr.c $\
srcs/ft_strjoin.c $\
srcs/ft_strlen.c $\
srcs/ft_strnstr.c $\
srcs/ft_substr.c $\
srcs/ft_calloc.c $\
srcs/ft_isascii.c $\
srcs/ft_itoa.c $\
srcs/ft_memcpy.c $\
srcs/ft_putchar_fd.c $\
srcs/ft_putstr_fd.c $\
srcs/ft_strdup.c $\
srcs/ft_strlcat.c $\
srcs/ft_strmapi.c $\
srcs/ft_strrchr.c $\
srcs/ft_tolower.c $\
srcs/ft_atoi.c $\
srcs/ft_isalnum.c $\
srcs/ft_isdigit.c $\
srcs/ft_memchr.c $\
srcs/ft_memmove.c $\
srcs/ft_putendl_fd.c $\
srcs/ft_split.c $\
srcs/ft_striteri.c $\
srcs/ft_strlcpy.c $\
srcs/ft_strncmp.c $\
srcs/ft_strtrim.c $\
srcs/ft_toupper.c

SRCS_AJT = srcs/ajout/ft_absolute_nbr.c $\
srcs/ajout/ft_atoi_base.c $\
srcs/ajout/ft_atol.c $\
srcs/ajout/ft_base_lenght.c $\
srcs/ajout/ft_base_verif.c $\
srcs/ajout/ft_contain_n.c $\
srcs/ajout/ft_count_n.c $\
srcs/ajout/ft_countain_double.c $\
srcs/ajout/ft_countwords.c $\
srcs/ajout/ft_exit.c $\
srcs/ajout/ft_free_tab2d.c $\
srcs/ajout/ft_isexa.c $\
srcs/ajout/ft_isint.c $\
srcs/ajout/ft_isnbr.c $\
srcs/ajout/ft_strndup.c $\
srcs/ajout/ft_verif_extension.c

SRCS_BNS = srcs/bonus/ft_lstadd_back_bonus.c $\
srcs/bonus/ft_lstadd_front_bonus.c $\
srcs/bonus/ft_lstclear_bonus.c $\
srcs/bonus/ft_lstdelone_bonus.c $\
srcs/bonus/ft_lstiter_bonus.c $\
srcs/bonus/ft_lstlast_bonus.c $\
srcs/bonus/ft_lstmap_bonus.c $\
srcs/bonus/ft_lstnew_bonus.c $\
srcs/bonus/ft_lstsize_bonus.c

SRCS_GNL = srcs/gnl/get_next_line_bonus.c

SRCS_PRINTF = srcs/printf/fonction_1_bonus.c $\
srcs/printf/fonction_2_bonus.c $\
srcs/printf/fonction_3_bonus.c $\
srcs/printf/fonction_4_bonus.c $\
srcs/printf/fonction_5_bonus.c $\
srcs/printf/fonction_6_bonus.c $\
srcs/printf/fonction_7_bonus.c $\
srcs/printf/fonction_8_bonus.c $\
srcs/printf/fonction_9_bonus.c $\
srcs/printf/fonction_10_bonus.c $\
srcs/printf/fonction_11_bonus.c $\
srcs/printf/fonction_12_bonus.c $\
srcs/printf/fonction_13_bonus.c $\
srcs/printf/fonction_digit_bonus.c $\
srcs/printf/fonction_space_bonus.c $\
srcs/printf/fonction_dot_bonus.c $\
srcs/printf/fonction_hexa_bonus.c $\
srcs/printf/fonction_len_bonus.c $\
srcs/printf/fonction_put_bonus.c $\
srcs/printf/fonction_symbol_bonus.c $\
srcs/printf/fonction_verif_bonus.c $\
srcs/printf/ft_printf.c

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

OBJS_DIR_AJT = objs/ajout/
OBJS_AJT = $(notdir $(SRCS_AJT:.c=.o))
OBJS_AJT_PREF = $(addprefix $(OBJS_DIR_AJT), $(OBJS_AJT))

OBJS_DIR_BNS = objs/bonus/
OBJS_BNS = $(notdir $(SRCS_BNS:.c=.o))
OBJS_BNS_PREF = $(addprefix $(OBJS_DIR_BNS), $(OBJS_BNS))

OBJS_DIR_GNL = objs/gnl/
OBJS_GNL = $(notdir $(SRCS_GNL:.c=.o))
OBJS_GNL_PREF = $(addprefix $(OBJS_DIR_GNL), $(OBJS_GNL))

OBJS_DIR_PRINTF = objs/printf/
OBJS_PRINTF = $(notdir $(SRCS_PRINTF:.c=.o))
OBJS_PRINTF_PREF = $(addprefix $(OBJS_DIR_PRINTF), $(OBJS_PRINTF))

NAME = libft.a
NAME_BNS = libft_bns.a

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror


mandatory : $(NAME)

bonus : $(NAME_BNS)

all : $(NAME_BNS)

$(OBJS_DIR)%.o : srcs/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_AJT)%.o : srcs/ajout/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR_AJT)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_DIR_BNS)%.o : srcs/bonus/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR_BNS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_GNL)%.o : srcs/gnl/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR_GNL)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_PRINTF)%.o : srcs/printf/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR_PRINTF)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS_PREF)
	@ar r $@ $^

$(NAME_BNS) : $(OBJS_PREF) $(OBJS_AJT_PREF) $(OBJS_BNS_PREF) $(OBJS_GNL_PREF) $(OBJS_PRINTF_PREF)
	@ar r $@ $^

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BNS)

re : fclean all
