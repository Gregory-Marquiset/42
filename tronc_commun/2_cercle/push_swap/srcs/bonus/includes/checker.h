/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:20:14 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 15:41:21 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../../includes/libft/includes/libft.h"
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
	struct s_stack	*next;
}					t_stack;

char				*get_next_line(int fd);

//		main.c				//
void				ft_error(t_stack **stack_a, t_stack **stack_b,
						char *command);

//		push.c				//
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);

//		reverse_rotate.c	//
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

//		rotate.c			//
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

//		swap.c				//
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

//		utils.c				//
t_stack				*ft_bikini_bottom(t_stack *stack);
t_stack				*ft_one_before_bikini_bottom(t_stack *stack);
t_stack				*ft_make_stack_a(char **list);

//		verif_input_utils.c	//
void				ft_xav_the_stack(t_stack **stack);
void				ft_le_xav(char **clean_input);
long				ft_atol(char *clean_input);
int					ft_count(char **input);
char				*ft_join(char **input, char set);

//		verif_input.c		//
int					ft_input_is_digit(char *clean_input);
int					ft_input_is_instuction(char *command);
char				**ft_check_input(char **input);

#endif
