/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:20:14 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/06 00:22:28 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "../../includes/printf/includes/ft_printf.h"
# include "../../includes/libft/includes/libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

//		utils.c				//
void				ft_xav_the_stack(t_stack **stack);
t_stack				*ft_make_stack_a(char **list);

//		verif_input_utils.c	//
void				ft_error(t_stack **stack_a, t_stack **stack_b);
void				ft_le_xav(char **clean_input);
long				ft_atol(char *clean_input);
int					ft_count(char **input);
char				*ft_join(char **input, char set);

//		verif_input.c		//
int					ft_input_is_digit(char *clean_input);
int					ft_input_is_instuction(char **clean_input);
char				**ft_check_input(char **input);

#endif
