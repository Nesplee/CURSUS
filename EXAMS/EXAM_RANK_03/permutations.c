#include "permutations.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_perm(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void	init_data(t_data *data, char *str)
{
	data->str = str;
	data->len = ft_strlen(str);
	data->used = (int *)calloc(data->len, sizeof(int));
	data->curr = (char *)malloc(sizeof(char) * data->len + 1);
	if (!data->curr || !data->used)
	{
		free(data->curr);
		free(data->used);
		return ;
	}
	data->curr[data->len] = '\0';
}

void	generate_perm(t_data *data, int pos)
{
	int	i;

	i = 0;
	if (pos == data->len)
	{
		print_perm(data->curr);
		return ;
	}
	while (i < data->len)
	{
		if (!data->used[i])
		{
			data->curr[pos] = data->str[i];
			data->used[i] = 1;
			generate_perm(data, pos + 1);
			data->used[i] = 0;
		}
		i++;
	}
}

void	sort_string(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (str[i + 1])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
 			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	sort_string(av[1]);
	init_data(&data, av[1]);
	generate_perm(&data, 0);
	free(data.curr);
	free(data.used);
	return (0);
}
