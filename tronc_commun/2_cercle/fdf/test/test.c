
#include "libft.h"

# ifndef C_WHITE
#  define C_WHITE 16777215
# endif

int	ft_get_color(char *str)
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
	int	nbr;

	if (argc != 2)
		return (0);
	nbr = ft_get_color(argv[1]);
	ft_printf("%d\n", nbr);
	return (0);
}

/*int	ft_verif_cordo(char *str)
{
	long	nbr;

	nbr = atol(str);
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return ((int)nbr);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%d\n", ft_verif_cordo(argv[1]));
	printf("%s\n", ft_verif_color(argv[1]));
	return (0);
}*/

//			verif						//

/*int	ft_strlen(char *str)
{
	int	len;

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
