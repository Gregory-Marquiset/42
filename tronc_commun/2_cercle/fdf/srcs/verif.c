/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 08:46:14 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_verif_color(char *str)
{
	char	*color;
	int		i;
	int		j;

	i = 0;
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	color = malloc(9);
	if (!color)
		return (NULL);
	i++;
	j = 0;
	while (j < 8)
		color[j++] = str[i++];
	color[8] = '\0';
	if (str[i] == '\0' && ft_isexa(color))
		return (color);
	else
		return (NULL);
}

int	ft_verif_cordo(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return ((int)nbr);
	return (0);
}

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
