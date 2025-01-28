/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:25:51 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/13 19:59:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_here_doc(char *arg)
{
	int	r;

	r = ft_strncmp(arg, HEREDOC, 8);
	if (r == 0)
		return (1);
	return (0);
}

void	write_to_pipe(int fd, char *limiter)
{
	char	*line;
	char	*full_limit;

	full_limit = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN);
		if (!line || ft_strcmp(line, full_limit) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(full_limit);
}

void	handle_here_doc(char *limiter, int *fd_in)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipe_fd) == -1)
		error_exit(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		error_exit(ERR_FORK);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		write_to_pipe(pipe_fd[1], limiter);
		close(pipe_fd[1]);
		exit(0);
	}
	wait(&status);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
	{
		*fd_in = pipe_fd[0];
		close(pipe_fd[1]);
	}
	else
		error_exit(ERR_HEREDOC);
}
