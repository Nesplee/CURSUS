/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:57:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/10/25 10:19:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*allocate_line(char *buffer, int len)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[len] = '\0';
	return (line);
}

static char	*extract_line(char **buffer, int newline_pos)
{
	char	*line;
	char	*new_buffer;
	int		len;

	if (newline_pos == -1)
		len = ft_strlen(*buffer);
	else
		len = newline_pos + 1;
	line = allocate_line(*buffer, len);
	if (line == NULL)
		return (NULL);
	if (newline_pos != -1 && (*buffer)[newline_pos + 1] != '\0')
		new_buffer = ft_strdup(*buffer + newline_pos + 1);
	else
		new_buffer = NULL;
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

int	read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*new_buffer;
	ssize_t	bytes_read;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (0);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp);
		return (0);
	}
	temp[bytes_read] = '\0';
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	else
	{
		new_buffer = ft_strjoin(*buffer, temp);
		free(*buffer);
		*buffer = new_buffer;
	}
	free(temp);
	return (*buffer != NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (buffer == NULL)
		buffer = ft_strdup("");
	newline_pos = found_newline(buffer);
	while (newline_pos == -1 && read_to_buffer(fd, &buffer))
		newline_pos = found_newline(buffer);
	if (newline_pos >= 0 || (buffer && *buffer))
		return (extract_line(&buffer, newline_pos));
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (NULL);
}
