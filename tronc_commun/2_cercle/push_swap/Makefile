# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 22:14:21 by gmarquis          #+#    #+#              #
#    Updated: 2024/03/12 12:03:48 by gmarquis         ###   ########.fr        #
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

SRCS_BNS = checker/srcs/main.c $\
checker/srcs/push.c $\
checker/srcs/reverse_rotate.c $\
checker/srcs/rotate.c $\
checker/srcs/swap.c $\
checker/srcs/utils.c $\
checker/srcs/verif_input_utils.c $\
checker/srcs/verif_input.c $\

SRCS_GNL = checker/includes/gnl/srcs/get_next_line.c $\
checker/includes/gnl/srcs/get_next_line_utils.c

LIBFT_PATH = includes/libft/
PRINTF_PATH = includes/printf/

NAME = push_swap
CHECKER = checker

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:.c=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

OBJS_DIR_BNS = objs_bns/
OBJS_BNS = $(notdir $(SRCS_BNS:.c=.o))
OBJS_PREF_BNS = $(addprefix $(OBJS_DIR_BNS), $(OBJS_BNS:.c=.o))

OBJS_DIR_GNL = objs_gnl/
OBJS_GNL = $(notdir $(SRCS_GNL:.c=.o))
OBJS_PREF_GNL = $(addprefix $(OBJS_DIR_GNL), $(OBJS_GNL:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

libftprintf :
	@make bonus -C $(PRINTF_PATH)

mandatory : libft libftprintf $(OBJS_PREF) $(NAME)

bonus : libft libftprintf $(OBJS_PREF_BNS) $(OBJS_PREF_GNL) $(CHECKER)

all : mandatory bonus

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BNS)%.o : checker/srcs/%.c 
	$(MK) -p $(OBJS_DIR_BNS)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJS_DIR_GNL)%.o : checker/includes/gnl/srcs/%.c
	$(MK) -p $(OBJS_DIR_GNL)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS_PREF)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a $(PRINTF_PATH)libftprintf.a

$(CHECKER) : $(OBJS_PREF_BNS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a $(PRINTF_PATH)libftprintf.a

clean :
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(PRINTF_PATH)
	rm -rf objs/

fclean :
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(PRINTF_PATH)
	rm -f $(NAME)
	rm -f $(CHECKER)
	rm -rf objs/

re : fclean all

.PHONY : all clean fclean re
