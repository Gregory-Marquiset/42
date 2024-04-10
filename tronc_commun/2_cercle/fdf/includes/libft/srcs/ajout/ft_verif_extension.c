/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:47:13 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 16:02:27 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_verif_extention(char *filename, char *exe)
{
	int	i;
	int	j;

	if (!filename || filename[0] == '\0')
		ft_exit(2, "Error : missing file.\n");
	if (!exe)
		ft_exit(2, "Error : missing extension.\n");
	i = 0;
	while (filename[i])
		i++;
	i--;
	while (filename[i] != '.')
		i--;
	j = 0;
	while (filename[i] == exe[j] && filename[i] && exe[j])
	{
		i++;
		j++;
	}
	if (filename[i] == '\0' && exe[j] == '\0')
		return ;
	ft_exit(2, "Error : invalid extension.\n");
}
