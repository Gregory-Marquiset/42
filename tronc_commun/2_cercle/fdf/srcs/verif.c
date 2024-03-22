/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 02:24:36 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_verif_extention(char *filename, char *exe)
{
	int	i;
	int	j;

	if (!filename || !exe)
		return (ft_exit("Erreur : file ou extention maquante.\n"), 0);
	i = 0;
	while (filename[i] == '.' || filename[i] == '/')
		i++;
	while (filename[i] != '.')
		i++;
	i++;
	j = 0;
	while (filename[i] == exe[j] && filename[i] && exe[j])
	{
		i++;
		j++;
	}
	if (filename[i] == '\0' && exe[j] == '\0')
		return (1);
	return (ft_exit("Erreur : file ou extention invalide.\n"), 0);
}
