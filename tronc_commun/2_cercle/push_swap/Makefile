# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greg <greg@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/01/09 01:10:15 by greg             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/initialisation.c \
srcs/push.c \
srcs/reverse_rotate.c \
srcs/rotate.c \
srcs/sorting.c \
srcs/stack_navigation.c \
srcs/stack_utils.c \
srcs/swap.c \
srcs/triad_sorting.c \
srcs/verif_input.c \
srcs/verif_input_utils.c \

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
