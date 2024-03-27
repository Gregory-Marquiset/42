/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:09:00 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/27 05:22:41 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*#ifndef C_WHITE
# define C_WHITE 16777215
#endif*/

void	ft_fill_map(char *one_line, int **map, char set, char next, char end, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (*one_line != end && j < height)
	{
		i = 0;
		while (*one_line != next && *one_line != end && i < width)
		{
			ft_printf("ici\n");
			while (*one_line == set && *one_line != end)
				one_line++;
			ft_printf("%s", one_line);
			map[i][j] = ft_atoi(one_line);
			ft_printf("%d\n", map[i][j]);
			while (*one_line != set && *one_line != next && *one_line != end)
				one_line++;
			i++;
		}
		j++;
	}
	return ;
}

int	**ft_split_des_enfers(char *one_line, char set, char next, char end)
{
	int		**map;
	int		width;
	int		height;
	int		i;

	width = ft_countwords(one_line, set, set, next);
	height = ft_countwords(one_line, next, next, end);
	map = malloc(width * sizeof(int **));
	if (!map)
		return (ft_printf("Erreur : map** non malloc.\n"), NULL);
	i = 0;
	while (i < width)
	{
		map[i] = malloc(height * sizeof(int *));
		if(!map[i])
		{
			while (i != 0)
				free(map[i--]);
			free (map);
			return (ft_printf("Erreur : map* non malloc.\n"), NULL);
		}
		i++;
	}
	ft_fill_map(one_line, map, set, next, end, width, height);
	return (map);
}

char	*ft_get_one_line(int fd)
{
	char	*one_line;
	int		trigger;
	char	*line;

	one_line = malloc(1);
	if (!one_line)
		return(ft_printf("Erreur : echec malloc pour one_line.\n"), NULL);
	one_line[0] = '\0';
	trigger = 1;
	while (trigger == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			trigger = 0;
		else
		{
			one_line = ft_strjoin(one_line, line, 2);
			if (!one_line)
				return(ft_printf("Erreur : join non reussi.\n"), NULL);
		}
	}
	return (one_line);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*one_line;
	int		**map;
	int		i = 0;
	int		j = 0;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(ft_printf("Erreur : echec de l'open du fd.\n"), 0);
	one_line = ft_get_one_line(fd);
	close(fd);
	if (!one_line)
		return (ft_printf("Erreur : one_line inexistant.\n"), 0);
	map = ft_split_des_enfers(one_line, ' ', '\n', '\0');
	free(one_line);
	while (map[i][j])
	{
		while (map[i])
		{
			ft_printf("width = %2d | height = %2d | valeur = %10d\n", i, j, map[i][j]);
			i++;
		}
		i = 0;
		j++;
	}

	return (0);
}

/*void	ft_verif_extention(char *filename, char *exe)
{
	int	i;
	int	j;

	if (!filename || !exe)
	{
		ft_printf("Erreur : file ou extention maquante.\n");
		exit(0);
	}
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
	ft_printf("Erreur : file ou extention invalide.\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf("Erreur : nmb d'arg invalide.\n"));
	ft_verif_extention(argv[1], argv[2]);
	ft_printf("Valid.\n");
	return (0);
}*/
/*int	ft_get_color(char *str)
{
	if (!str)
		return (C_WHITE);
	while (*str != ',' && *str != '\0')
		str++;
	str++;
	if (ft_isexa(str))
	{
		str += 2;
		return (ft_atoi_base(str, "0123456789ABCDEF"));
	}
	else
		return (C_WHITE);
}

int	main(int argc, char **argv)
{
	int		nbr;
	long	nbr;

	if (argc != 2)
		return (0);
	nbr = ft_get_color(argv[1]);
	ft_printf("%d\n", nbr);
	return (0);
}*/
/*int	ft_verif_cordo(char *str)
{
	nbr = atol(str);
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return ((int)nbr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (0);
	printf("%d\n", ft_verif_cordo(argv[1]));
	printf("%s\n", ft_verif_color(argv[1]));
	return (0);
}*/
//			verif						//
/*int	ft_strlen(char *str)
{
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_exit(char *erreur)
{
	int	len;

	len = ft_strlen(erreur);
	write(2, erreur , len);
	exit(0);
}

int	ft_verif_extention(char *filename, char *exe)
{
	int	i;
	int	j;

	if (!filename || !exe)
		return (ft_exit("Erreur : pas de filename ou d'extention.\n"), 0);
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
	return (ft_exit("Erreur : pas la bonne extention.\n"), 0);
}

int	main(int argc,char **argv)
{
	if (argc != 3)
		return (0);
	printf("%d\n", ft_verif_extention(argv[1], argv[2]));
	return (0);
}*/

//		test tab de tab de struct		//
/*typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	v;
}		t_map;

int	main(int ac, char **av)
{
	t_map	***map;
	int	width = -1;
	int	height;
	int	value;
	int	visible;

	map = malloc(6 * sizeof(t_map **));
	if (!map)
		return (printf("KO.1\n"), 0);
	value = 0;
	visible = 1;
	while (++width < 6)
	{
		height = -1;
		map[width] = malloc(3 * sizeof(t_map *));
		if (!map[width])
			return (printf("KO.2\n"), 0);
		while (++height < 3)
		{
			map[width][height] = malloc(sizeof(t_map));
			if (!map[width][height])
				return (printf("KO.3\n"), 0);
			map[width][height]->x = width;
			map[width][height]->y = height;
			map[width][height]->z = value;
			map[width][height]->v = visible;
			if (value == 0)
				value = 10;
			else
				value = 0;
			if (visible == 0)
				visible = 1;
			else
				visible = 0;
		}
	}
	width = -1;
	while (++width < 6)
	{
		height = -1;
		while (++height < 3)
		{
			printf("map[%d][%d] [x = %2d] [y = %2d] [z = %2d] [v = %2d]\n",
				width, height, map[width][height]->x, map[width][height]->y,
				map[width][height]->z ,map[width][height]->v);
		}
	}
}*/
