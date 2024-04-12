/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:35:13 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 09:32:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data
{
	int		fd_1;
	int		fd_2;
	int		*pipe;
	char	**cmd_split;
	char	*path;
	char	**path_split;
}		t_data;
