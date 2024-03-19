#include <stdio.h>

typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	v;
}	t_map;

int	main(int ac, char **av)
{
	t_map	map[6][10];
	int	i = -1;
	int	j;
	while (++i < 6)
	{
		j = -1;
		while (++j < 9)
			printf("map[%d][%d] [x = %d] | [y = %d] | [x = %d] | [v = %d]\n", i , j, map[i][j].x, map[i][j].y, map[i][j].z ,map[i][j].v);

	}
}
