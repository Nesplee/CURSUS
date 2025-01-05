/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:19:11 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 22:03:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

static void	handle_first_cmd(t_pipex *p, char **av, char **env)
{
	int	here_doc_fd;

	if (p->here_doc)
	{
		here_doc_fd = handle_here_doc(p);
		if (dup2(here_doc_fd, STDIN_FILENO) == -1)
			error_system("dup2 here_doc failed");
		close(here_doc_fd);
	}
	else if (p->infile == -1)
	{
		close_pipes(p);
		free_pipex(p);
		exit(1);
	}
	else if (dup2(p->infile, STDIN_FILENO) == -1)
		error_system("dup2 infile failed");
	if (dup2(p->pipes[0][WRITE], STDOUT_FILENO) == -1)
		error_system("dup2 pipe write failed");
	close_pipes(p);
	child_process(p, 0, av, env);
}

static void	handle_mid_cmd(t_pipex *p, int i, char **av, char **env)
{
	if (dup2(p->pipes[i - 1][READ], STDIN_FILENO) == -1)
		error_system("dup2 pipe read failed");
	if (dup2(p->pipes[i][WRITE], STDOUT_FILENO) == -1)
		error_system("dup2 pipe write failed");
	close_pipes(p);
	child_process(p, i, av, env);
}

static void	handle_last_cmd(t_pipex *p, char **av, char **env)
{
	if (dup2(p->pipes[p->pipe_count - 1][READ], STDIN_FILENO) == -1)
		error_system("dup2 pipe read failed");
	if (p->outfile == -1)
	{
		close_pipes(p);
		free_pipex(p);
		exit(1);
	}
	if (dup2(p->outfile, STDOUT_FILENO) == -1)
		error_system("dup2 outfile failed");
	close_pipes(p);
	child_process(p, p->cmd_count - 1, av, env);
}

static void	fork_process(t_pipex *p, int i, char **av, char **env)
{
	p->pids[i] = fork();
	if (p->pids[i] == -1)
	{
		free_pipex(p);
		error_system("Fork failed");
	}
	if (p->pids[i] == 0)
	{
		if (i == 0)
			handle_first_cmd(p, av, env);
		else if (i == p->cmd_count - 1)
			handle_last_cmd(p, av, env);
		else
			handle_mid_cmd(p, i, av, env);
		free_pipex(p);
		exit(EXIT_FAILURE);
	}
}

int	execute_cmds(t_pipex *p, char **av, char **env)
{
	int	i;
	int	status;

	create_pipes(p);
	i = 0;
	while (i < p->cmd_count)
	{
		fork_process(p, i, av, env);
		i++;
	}
	close_pipes(p);
	status = wait_children(p);
	return (status);
}
