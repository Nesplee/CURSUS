/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:53:11 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_line(char *line, char *limiter, int write_fd)
{
	if (!ft_strncmp(line, limiter, ft_strlen(limiter))
		&& line[ft_strlen(limiter)] == '\n')
	{
		free(line);
		return (1);
	}
	if (line[0] != '\0')
		ft_putstr_fd(line, write_fd);
	free(line);
	return (0);
}

int	handle_here_doc(char *limiter, int write_fd)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (handle_line(line, limiter, write_fd))
			break ;
		ft_putstr_fd("heredoc> ", 1);
	}
	close(write_fd);
	return (0);
}
