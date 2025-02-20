#include <stdlib.h>
#include <stdio.h>

int	find_pgcd(int a, int b)
{
	int	temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	pgcd;

	if (ac == 3)
	{
		x = atoi(av[1]);
		y = atoi(av[2]);
		pgcd = find_pgcd(x, y);
		printf("%d\n", pgcd);
	}
	else
		printf("\n");
	return (0);
}
