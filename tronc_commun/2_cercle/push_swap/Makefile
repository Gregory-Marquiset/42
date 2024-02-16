# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/02/16 09:25:28 by gmarquis         ###   ########.fr        #
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

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

MK = mkdir

RM = rm -f

LIBFT_PATH = includes/libft/
PRINTF_PATH = includes/printf/

OBJS_DIR = objs/

OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

libftprintf :
	@make bonus -C $(PRINTF_PATH)

all : libft libftprintf $(OBJS_PREF) $(NAME)

bonus : all

$(OBJS_DIR)%.o : srcs/%.c Makefile includes/push_swap.h includes/printf/libftprintf.a includes/libtf/libft_bns.a
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	@ar r $@ $^

clean :
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	rm -rf objs/

fclean :
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	$(RM) $(NAME)
	rm -rf objs/

re : fclean all

.PHONY : all clean fclean re
