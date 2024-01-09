
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'a';
	printf("%c\n", c);
	c -= (1 << 5);
	printf("%c\n", c);
	return (0);
}
