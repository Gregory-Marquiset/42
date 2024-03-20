/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 21:15:54 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*ft_new_point(int y, int x, char *str)
{
	t_point	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(str);
	new->v = ft_strncmp(str, "V", 1);
	new->next = NULL;
	return (new);
}

t_fdf	*ft_new_fdf(char	**map_2d, char	*one_line)
{
	t_fdf	*info;

	info = malloc(sizeof * info);
	if (!info)
		return (0);
	info->width = ft_countwords(one_line, ' ', ' ', '\n');
	info->height = ft_countwords(one_line, '\n', '\n', '\0');
	info->map = ft_make_map(map_2d);
	return (info);
}
/*
t_point	*ft_get_bottom(t_point *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_add_bottom(t_point **stack, t_point*new)
{
	t_point	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = ft_get_bottom(*stack);
	bottom->next = new;
}

t_point	*ft_make_stack_a(char **list)
{
	t_point	*stack;
	int		i;

	if (!list || !list[0])
		return (0);
	i = 0;
	stack = ft_new_element(list[i++]);
	if (!stack)
		return (0);
	while (list[i])
	{
		ft_add_bottom(&stack, ft_new_element(list[i]));
		i++;
	}
	ft_free_tab2d(list);
	return (stack);
}
*/
