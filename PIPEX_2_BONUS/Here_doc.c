/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:44:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 21:32:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

static void	read_here_doc(int pipe_write, char *limiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		{
			line[ft_strlen(line) - 1] = '\0';
			if (!ft_strcmp(line, limiter))
			{
				free(line);
				break ;
			}
			line[ft_strlen(line)] = '\n';
		}
		write(pipe_write, line, ft_strlen(line));
		free(line);
	}
}

int	handle_here_doc(t_pipex *p)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error_system("pipe failed");
	read_here_doc(pipe_fd[WRITE], p->limiter);
	close(pipe_fd[WRITE]);
	return (pipe_fd[READ]);
}
