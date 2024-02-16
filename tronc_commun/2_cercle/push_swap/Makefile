# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/02/16 04:44:44 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/cost.c $\
srcs/main.c $\
srcs/move $\
srcs/position $\
srcs/push.c $\
srcs/reverse_rotate.c $\
srcs/rotate.c $\
srcs/sorting.c $\
srcs/stack_navigation.c $\
srcs/swap.c $\
srcs/triad_sorting.c $\
srcs/utils.c $\
srcs/verif_input_utils.c $\
srcs/verif_input.c

LIBFT_PATH = includes/libft/

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

NAME = push_swap.a

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

libft :
	@make bonus -C $(LIBFT_PATH)

all : libft $(OBJS_PREF) $(NAME)

bonus : all

$(OBJS_DIR)%.o : srcs/%.c includes/push_swap.h includes/archives/libft.a
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	@ar r $@ $^


clean :
	rm -rf $(OBJS_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
