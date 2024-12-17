/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:27:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 12:56:09 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	redirect_input(int fd_in)
{
	int	dev_null;

	if (fd_in >= 0)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
		{
			perror("dup2 input");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		dev_null = open("/dev/null", O_RDONLY);
		if (dup2(dev_null, STDIN_FILENO) == -1)
		{
			perror("dup2 /dev/null");
			exit(EXIT_FAILURE);
		}
		close(dev_null);
	}
}

static void	redirect_output(int fd_out)
{
	int	dev_null;

	if (fd_out >= 0)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2 output");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		dev_null = open("/dev/null", O_WRONLY);
		if (dup2(dev_null, STDOUT_FILENO) == -1)
		{
			perror("dup2 /dev/null");
			exit(EXIT_FAILURE);
		}
		close(dev_null);
	}
}

void	execute_first_command(t_pipex *pipex, char **av, char **envp)
{
	redirect_input(pipex->infile);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		exit(EXIT_FAILURE);
	}
	close_pipes(pipex);
	execute_command(pipex, av[2], envp);
}

void	execute_second_command(t_pipex *pipex, char **av, char **envp)
{
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		exit(EXIT_FAILURE);
	}
	redirect_output(pipex->outfile);
	close_pipes(pipex);
	execute_command(pipex, av[3], envp);
}
