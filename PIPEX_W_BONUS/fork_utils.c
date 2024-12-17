/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:04:43 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_child_process(t_pipex *pipex, char **av, char **envp, int i)
{
	if (i == 0)
		execute_first_command(pipex, av, envp);
	else if (i == pipex->cmd_count - 1)
		execute_second_command(pipex, av, envp);
	else
		execute_middle_commands(pipex, av, envp, i);
}

static void	wait_for_processes(t_pipex *pipex, int *last_status)
{
	int	i;
	int	status;

	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pipex->pids[i], &status, 0);
		if (i == pipex->cmd_count - 1)
			*last_status = status;
		i++;
	}
}

int	fork_processes(t_pipex *pipex, char **av, char **envp)
{
	int	i;
	int	last_status;

	i = -1;
	while (++i < pipex->cmd_count)
	{
		pipex->pids[i] = fork();
		if (pipex->pids[i] == -1)
			handle_fork_error(pipex);
		if (pipex->pids[i] == 0)
			handle_child_process(pipex, av, envp, i);
	}
	close_all_pipes(pipex);
	wait_for_processes(pipex, &last_status);
	return (get_exit_status(last_status, pipex));
}
