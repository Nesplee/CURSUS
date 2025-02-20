#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (res ==NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
