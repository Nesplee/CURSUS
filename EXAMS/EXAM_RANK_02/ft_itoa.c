#include <stdlib.h>

char	*small_itoa(int n)
{
	char	*r;
	int		s;
	int		i;

	s = 0;
	r = (char *)malloc(sizeof(char) * 12);
	if (r == NULL)
		return (NULL);
	if (n < 0)
	{
		s = 1;
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		r[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (s == 1)
		r[i++] = '-';
	r[i] = '\0';
	return (r);
}

void	ft_swap(char *a, char *b)
{
	char	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void	reverse_string(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start <= end)
	{
		ft_swap(&str[start], &str[end]);
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;

	if (n == 0)
	{
		res = malloc(sizeof(char *) * 2);
		if (res == NULL)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (n == -2147483648)
	{
		res = malloc(sizeof(char *) * 12);
		if (res == NULL)
			return (NULL);
		res = "-2147483648";
		return (res);
	}
	res = small_itoa(n);
	reverse_string(res);
	return (res);
}
