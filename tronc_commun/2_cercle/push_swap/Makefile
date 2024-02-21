# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/02/21 18:03:57 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/cost.c $\
srcs/main.c $\
srcs/move.c $\
srcs/position.c $\
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
PRINTF_PATH = includes/printf/

NAME = push_swap

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

libftprintf :
	@make bonus -C $(PRINTF_PATH)

all : libft libftprintf $(OBJS_PREF) $(NAME)

bonus : all

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a $(PRINTF_PATH)libftprintf.a

clean :
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	rm -rf objs/

fclean :
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)
	rm -rf objs/

re : fclean all

.PHONY : all clean fclean re
