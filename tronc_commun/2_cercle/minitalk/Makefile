# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:01:55 by greg              #+#    #+#              #
#    Updated: 2024/02/21 17:41:12 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/client.c $\
srcs/server.c

SRCS_B = srcs/bonus/client_bonus.c $\
srcs/bonus/server_bonus.c

SRCS_U = srcs/utils/check_pid.c $\
srcs/utils/client_b_utils.c $\
srcs/utils/server_b_utils.c $\
srcs/utils/convert_wc.c $\
srcs/utils/utils.c

NAME = client
NAME_S = server

NAME_CB = client_bonus
NAME_SB = server_bonus

MK = mkdir
CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

PRINTF_PATH = includes/printf/

OBJS_DIR = objs/
UTILS_DIR = utils/
BNS_DIR = bonus/

OBJS = $(notdir $(SRCS:.c=.o))
OBJS_U = $(notdir $(SRCS_U:.c=.o))
OBJS_B = $(notdir $(SRCS_B:.c=.o))

OBJS_PREF = $(addprefix $(OBJS_DIR), $(OBJS:.c=.o))
OBJS_PREF_U = $(addprefix $(OBJS_DIR)$(UTILS_DIR), $(OBJS_U))
OBJS_PREF_B = $(addprefix $(OBJS_DIR)$(BNS_DIR), $(OBJS_B))

libftprintf :
	@make bonus -C $(PRINTF_PATH)

mandatory : libftprintf $(OBJS_PREF_U) $(OBJS_PREF) $(NAME) $(NAME_S)

bonus : libftprintf $(OBJS_PREF_U) $(OBJS_PREF_B) $(NAME_CB) $(NAME_SB)

all : mandatory bonus

$(OBJS_DIR)%.o : srcs/%.c Makefile includes/minitalk.h includes/printf/libftprintf.a
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)$(UTILS_DIR)%.o : srcs/utils/%.c includes/minitalk.h includes/printf/libftprintf.a
	$(MK) -p $(OBJS_DIR)$(UTILS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)$(BNS_DIR)%.o : srcs/bonus/%.c includes/minitalk.h includes/printf/libftprintf.a
	$(MK) -p $(OBJS_DIR)$(BNS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : objs/client.o objs/utils/utils.o objs/utils/check_pid.o includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) objs/client.o objs/utils/utils.o objs/utils/check_pid.o includes/printf/libftprintf.a -o $(NAME)

$(NAME_S) : objs/server.o objs/utils/utils.o includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) objs/server.o objs/utils/utils.o includes/printf/libftprintf.a -o $(NAME_S)

$(NAME_CB) : objs/bonus/client_bonus.o objs/utils/check_pid.o objs/utils/client_b_utils.o objs/utils/utils.o includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) objs/bonus/client_bonus.o objs/utils/check_pid.o objs/utils/client_b_utils.o objs/utils/utils.o includes/printf/libftprintf.a -o $(NAME_CB)

$(NAME_SB) : objs/bonus/server_bonus.o objs/utils/convert_wc.o objs/utils/server_b_utils.o objs/utils/utils.o includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) objs/bonus/server_bonus.o objs/utils/convert_wc.o objs/utils/server_b_utils.o objs/utils/utils.o includes/printf/libftprintf.a -o $(NAME_SB)

clean :
	@make clean -C $(PRINTF_PATH)
	rm -rf objs/

fclean : clean
	@make fclean -C $(PRINTF_PATH)
	$(RM) $(NAME) $(NAME_S)
	$(RM) $(NAME_CB) $(NAME_SB)

re : fclean all

.PHONY : all clean fclean re
