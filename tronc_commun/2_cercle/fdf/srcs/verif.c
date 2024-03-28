/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 02:27:45 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_verif_cordo(char *str)
{
	long	nbr;

	if (!str)
		return(0);
	nbr = ft_atol(str);
	if (ft_isint(str))
		return ((int)nbr);
	return (0);
}

void	ft_verif_extention(char *filename, char *exe)
{
	int	i;
	int	j;

	if (!filename || !exe)
		ft_exit("Erreur : file ou extention maquante.\n");
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
	ft_exit("Erreur : file ou extention invalide.\n");
}
