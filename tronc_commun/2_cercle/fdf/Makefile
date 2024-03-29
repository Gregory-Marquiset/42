# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 13:36:33 by gmarquis          #+#    #+#              #
#    Updated: 2024/03/29 00:50:27 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/end.c $\
srcs/get_info.c $\
srcs/init.c $\
srcs/main.c $\
srcs/verif.c

LIBFT_PATH = includes/libft/
MINILIBX_PATH = includes/minilibx-linux/

NAME = fdf

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:>C=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

minilibx :
	@make all -C $(MINILIBX_PATH)

bonus : libft minilibx $(NAME)

all : bonus

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	$(CC) -lXext -lX11 $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a $(MINILIBX_PATH)libmlx.a

clean :
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_PATH)
	rm -rf objs/

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
