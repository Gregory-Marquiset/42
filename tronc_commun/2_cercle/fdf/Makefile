# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 13:36:33 by gmarquis          #+#    #+#              #
#    Updated: 2024/04/19 08:54:58 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/coordo.c $\
srcs/draw.c $\
srcs/end.c $\
srcs/get_info.c $\
srcs/gradient.c $\
srcs/init.c $\
srcs/input.c $\
srcs/keys_events.c $\
srcs/main.c $\
srcs/pixel_color.c $\
srcs/verif.c $\
srcs/z_events.c

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

all : libft minilibx $(NAME)

bonus : all

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF) $(LIBFT_PATH)libft_bns.a $(MINILIBX_PATH)libmlx.a
	$(CC) -lm -lXext -lX11 $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a $(MINILIBX_PATH)libmlx.a

clean :
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_PATH)
	rm -rf objs/

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus minilibx libft clean fclean re
