/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:27:19 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/16 15:06:51 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_fork_error(t_pipex *pipex)
{
	perror("fork");
	close_pipes(pipex);
	free(pipex);
	exit(EXIT_FAILURE);
}

static void	execute_first_command(t_pipex *pipex, char **av, char **envp)
{
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup 2 pipe write");
		exit(EXIT_FAILURE);
	}
	close_pipes(pipex);
	execute_command(pipex, av[2], envp);
}

static void	execute_second_command(t_pipex *pipex, char **av, char **envp)
{
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup 2 pipe read");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		exit(EXIT_FAILURE);
	}
	close_pipes(pipex);
	execute_command(pipex, av[3], envp);
}

void	fork_processes(t_pipex *pipex, char **av, char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		handle_fork_error(pipex);
	if (pipex->pid1 == 0)
		execute_first_command(pipex, av, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		handle_fork_error(pipex);
	if (pipex->pid2 == 0)
		execute_second_command(pipex, av, envp);
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}
