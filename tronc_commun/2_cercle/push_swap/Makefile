# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/03/15 09:48:57 by gmarquis         ###   ########.fr        #
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
srcs/swap.c

SRCS_UTILS = srcs/utils/actions.c $\
srcs/utils/stack_utils.c $\
srcs/utils/utils.c $\
srcs/utils/verif_input.c

SRCS_BNS = srcs/bonus/srcs/main.c $\
srcs/bonus/srcs/push.c $\
srcs/bonus/srcs/reverse_rotate.c $\
srcs/bonus/srcs/rotate.c $\
srcs/bonus/srcs/swap.c

LIBFT_PATH = includes/libft/

NAME = push_swap
CHECKER = checker

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

OBJS_DIR_UTILS = objs/utils/
OBJS_UTILS = $(notdir $(SRCS_UTILS:.c=.o))
OBJS_PREF_UTILS = $(addprefix $(OBJS_DIR_UTILS), $(OBJS_UTILS:.c=.o))

OBJS_DIR_BNS = objs/bonus/
OBJS_BNS = $(notdir $(SRCS_BNS:.c=.o))
OBJS_PREF_BNS = $(addprefix $(OBJS_DIR_BNS), $(OBJS_BNS:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

mandatory : libft $(OBJS_PREF) $(NAME)

bonus : libft $(OBJS_PREF_BNS) $(CHECKER)

all : mandatory bonus

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_UTILS)%.o : srcs/utils/%.c 
	$(MK) -p $(OBJS_DIR_UTILS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BNS)%.o : srcs/bonus/srcs/%.c 
	$(MK) -p $(OBJS_DIR_BNS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS_PREF) $(OBJS_PREF_UTILS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a

$(CHECKER) : $(OBJS_PREF_BNS) $(OBJS_PREF_UTILS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a

clean :
	@make clean -C $(LIBFT_PATH)
	rm -rf objs/

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)
	rm -f $(CHECKER)

re : fclean all

.PHONY : all clean fclean re
