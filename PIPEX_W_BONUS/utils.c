/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:22 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_resources(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->infile >= 0)
		close(pipex->infile);
	if (pipex->outfile >= 0)
		close(pipex->outfile);
	if (pipex->pipes)
	{
		while (++i < pipex->pipe_count)
			if (pipex->pipes[i])
				free(pipex->pipes[i]);
		free(pipex->pipes);
	}
	if (pipex->pids)
		free(pipex->pids);
	free(pipex);
}

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_count)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i])
		{
			free_resources(pipex);
			exit(EXIT_FAILURE);
		}
		if (pipe(pipex->pipes[i]) == -1)
		{
			perror("pipe");
			free_resources(pipex);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_all_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_count)
	{
		if (pipex->pipes[i])
		{
			if (pipex->pipes[i][0] >= 0)
				close(pipex->pipes[i][0]);
			if (pipex->pipes[i][1] >= 0)
				close(pipex->pipes[i][1]);
		}
		i++;
	}
}

int	init_memory(t_pipex *pipex)
{
	pipex->pipes = malloc(sizeof(int *) * pipex->pipe_count);
	if (!pipex->pipes)
		return (0);
	pipex->pids = malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pipex->pids)
	{
		free(pipex->pipes);
		return (0);
	}
	return (1);
}
