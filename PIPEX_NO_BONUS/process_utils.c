/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:51:13 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 12:52:39 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_fork_error(t_pipex *pipex)
{
	perror("fork");
	close_pipes(pipex);
	free(pipex);
	exit(EXIT_FAILURE);
}

int	get_exit_status(int status2, t_pipex *pipex)
{
	if (pipex->outfile < 0)
		return (1);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	if (WIFSIGNALED(status2))
		return (128 + WTERMSIG(status2));
	return (EXIT_FAILURE);
}

int	fork_processes(t_pipex *pipex, char **av, char **envp)
{
	int	status1;
	int	status2;

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
	waitpid(pipex->pid1, &status1, 0);
	waitpid(pipex->pid2, &status2, 0);
	return (get_exit_status(status2, pipex));
}
