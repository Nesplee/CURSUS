#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	rotone(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'y')
		{
			c = str[i] + 1;
			ft_putchar(c);
		}
		else if (str[i] >= 'A' && str[i] <= 'Y')
		{
			c = str[i] + 1;
			ft_putchar(c);
		}
		else if (str[i] == 'z')
			ft_putchar('a');
		else if (str[i] == 'Z')
			ft_putchar('A');
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		rotone(av[1]);
		ft_putchar('\n');
	}
	else
		ft_putchar('\n');
	return (0);
}
