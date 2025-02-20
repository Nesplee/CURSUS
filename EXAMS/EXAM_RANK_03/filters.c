#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] -s2[i]);
		i++;
	}
	return (0);
}

char	*censure_text(char *text, char *pattern)
{
	int	pos;
	int	pat_len;
	int	star;

	pos = 0;
	pat_len = ft_strlen(pattern);
	while (text[pos])
	{
		if (ft_strncmp(&text[pos], pattern, pat_len) == 0)
		{
			star = 0;
			while (star < pat_len)
			{
				text[pos + star] = '*';
				star++;
			}
			pos = pos + pat_len - 1;
		}
		pos++;
	}
	return (text);
}

int	main(int ac, char **av)
{
	char	*buff;
	char	c;
	int		pos;
	int		reader;
	int		size;

	if (ac != 2)
	{
		printf("Error: One argument needed\n");
		return (1);
	}
	size = BUFFER_SIZE;
	buff = (char *)malloc(sizeof(char) * size + 1);
	if (!buff)
	{
		printf("Error: Malloc failed\n");
		return (1);
	}
	reader = read(0, &c, 1);
	pos = 0;
	while (reader > 0)
	{
		buff[pos] = c;
		pos++;
		if (pos >= size - ft_strlen(av[1] - 1))
		{
			size = size * 2;
			buff = (char *)realloc(buff, size * 2);
			if (!buff)
			{
				printf("Error: Realloc failed\n");
				return (1);
			}
		}
		reader = read(0, &c, 1);
	}
	buff[pos] = '\0';
	printf("%s", censure_text(buff, av[1]));
	free(buff);
	return (0);
}
