# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 17:10:22 by gmarquis          #+#    #+#              #
#    Updated: 2024/02/16 09:25:12 by gmarquis         ###   ########.fr        #
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

SRCS_BNS = srcs/bonus/ft_lstadd_back_bonus.c $\
srcs/bonus/ft_lstadd_front_bonus.c $\
srcs/bonus/ft_lstclear_bonus.c $\
srcs/bonus/ft_lstdelone_bonus.c $\
srcs/bonus/ft_lstiter_bonus.c $\
srcs/bonus/ft_lstlast_bonus.c $\
srcs/bonus/ft_lstmap_bonus.c $\
srcs/bonus/ft_lstnew_bonus.c $\
srcs/bonus/ft_lstsize_bonus.c $\

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

OBJS_DIR_BNS = objs/bonus/
OBJS_BNS = $(notdir $(SRCS_BNS:.c=.o))
OBJS_BNS_PREF = $(addprefix $(OBJS_DIR_BNS), $(OBJS_BNS))

NAME = libft.a
NAME_BNS = libft_bns.a

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(NAME_BNS)

$(OBJS_DIR)%.o : srcs/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BNS)%.o : srcs/bonus/%.c includes/libft.h
	$(MK) -p $(OBJS_DIR_BNS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	@ar r $@ $^

$(NAME_BNS) : $(OBJS_PREF) $(OBJS_BNS_PREF)
	@ar r $@ $^

clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
