/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:30:44 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/11 01:50:47 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_out(t_data *data, char *message, int flag)
{
	if (flag >= 1)
		close(data->fd_1);
	if (flag >= 2)
		close(data->fd_2);
	if (data->pipe)
		free(data->pipe);
	if (data->cmd_split)
		ft_free_tab2d(data->cmd_split);
	if (data->path)
		free(data->path);
	if (data->path_split)
		ft_free_tab2d(data->path_split);
	ft_exit(2, message);
}
