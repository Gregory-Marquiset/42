# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 16:01:55 by greg              #+#    #+#              #
#    Updated: 2024/01/23 09:17:03 by gmarquis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = srcs/client.c $\
SRCS_S = srcs/server.c $\

SRCS_CB = srcs/bonus/client_bonus.c $\
SRCS_SB = srcs/bonus/server_bonus.c $\

SRCS_U = srcs/utils/check_pid.c $\
srcs/utils/client_b_utils.c $\
srcs/utils/convert_wc.c $\
srcs/utils/server_b_utils.c

NAME = client
NAME_S = server

NAME_CB = $(CLIENT)_bonus
NAME_SB = $(SERVER)_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

MK = mkdir

RM = rm -f

PRINTF_PATH = includes/printf/

OBJS_DIR = objs/
UTILS_DIR = utils/
BNS_DIR = bonus/

OBJS_C = $(notdir $(SRCS_C:.c=.o))
OBJS_S = $(notdir $(SRCS_S:.c=.o))
OBJS_U = $(notdir $(SRCS_U:.c=.o))
OBJS_CB = $(notdir $(SRCS_CB:.c=.o))
OBJS_SC = $(notdir $(SRCS_SB:.c=.o))

PREF_C = $(addprefix $(OBJS_DIR), $(OBJS_C:.c=.o))
PREF_S = $(addprefix $(OBJS_DIR), $(OBJS_S:.c=.o))
OBJS_PREF_U = $(addprefix $(OBJS_DIR)$(UTILS_DIR), $(OBJS_U))
OBJS_PREF_BNS = $(addprefix $(OBJS_DIR)$(BNS_DIR), $(OBJS_CB), $(OBJS_SB))

all : libftprintf $(NAME) $(NAME_S)

libftprintf :
	@make bonus -C $(PRINTF_PATH)

$(OBJS_DIR)%.o : srcs/%.c Makefile includes/minitalk.h includes/printf/libftprintf.a
	$(MK) -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)$(UTILS_DIR)%.o : srcs/utils/%.c includes/minitalk.h includes/printf/libftprintf.a
	$(MK) -p $(OBJS_DIR)$(UTILS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : ${PREF_C} includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS_C)

$(NAME_S) : ${PREF_S} includes/minitalk.h includes/printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME_S) $(OBJS_S)


bonus:

clean :
	@make fclean -C $(PRINTF_PATH)
	$(RM) $(NAME) $(NAME_S)
	rm -rf objs/

fclean : clean

re : fclean all

.PHONY : all clean fclean re
