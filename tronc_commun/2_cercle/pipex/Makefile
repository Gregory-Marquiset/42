# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 22:26:56 by gmarquis          #+#    #+#              #
#    Updated: 2024/04/10 23:36:59 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/end.c $\
srcs/main.c

LIBFT_PATH = includes/libft/

NAME = pipex

MK = mkdir
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

OBJS_DIR = objs/
OBJS = $(notdir $(SRCS:>C=.o))
OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))

libft :
	@make bonus -C $(LIBFT_PATH)

bonus : libft $(NAME)

all : bonus

$(OBJS_DIR)%.o : srcs/%.c
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_PREF)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFT_PATH)libft_bns.a

clean :
	@make clean -C $(LIBFT_PATH)
	rm -rf objs/

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
