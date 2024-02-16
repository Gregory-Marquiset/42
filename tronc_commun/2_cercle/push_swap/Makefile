# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/02/16 01:01:04 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/cost.c $\
srcs/do_move $\
srcs/initialisation.c $\
srcs/main.c $\
srcs/position $\
srcs/push.c $\
srcs/reverse_rotate.c $\
srcs/rotate.c $\
srcs/sorting.c $\
srcs/stack_navigation.c $\
srcs/stack_utils.c $\
srcs/swap.c $\
srcs/triad_sorting.c $\
srcs/verif_input_utils.c $\
srcs/verif_input.c

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = push_swap.a

MK = mkdir -p
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c includes/push_swap.h
	$(MK) $(OBJS_DIR)
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
