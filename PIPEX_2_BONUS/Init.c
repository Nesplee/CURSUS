/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:52:56 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 20:54:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

static void	malloc_arrays(t_pipex *p)
{
	p->pipes = (int **)malloc(sizeof(int *) * p->pipe_count);
	if (!p->pipes)
		error_system("Malloc pipes failed");
	p->pids = (pid_t *)malloc(sizeof(pid_t) * p->cmd_count);
	if (!p->pids)
	{
		free(p->pipes);
		error_system("Malloc pids failed");
	}
}

static void	malloc_pipes(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < p->pipe_count)
	{
		p->pipes[i] = malloc(sizeof(int) * 2);
		if (!p->pipes[i])
		{
			free_pipex(p);
			error_system("Malloc pipe failed");
		}
		p->pipes[i][READ] = -1;
		p->pipes[i][WRITE] = -1;
		i++;
	}
}

static void	init_files(t_pipex *p, int ac, char **av)
{
	if (p->here_doc)
	{
		p->limiter = ft_strdup(av[2]);
		p->infile = -1;
		p->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		p->limiter = NULL;
		p->infile = open(av[1], O_RDONLY);
		if (p->infile == -1)
			perror(av[1]);
		p->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (p->outfile == -1)
		perror(av[ac - 1]);
}

void	init_pipex(t_pipex *p, int ac, char **av)
{
	ft_bzero(p, sizeof(t_pipex));
	p->here_doc = (ac > 1 && !ft_strcmp(av[1], HERE_DOC));
	if (p->here_doc)
		p->cmd_count = ac - 4;
	else
		p->cmd_count = ac - 3;
	p->pipe_count = p->cmd_count - 1;
	malloc_arrays(p);
	malloc_pipes(p);
	init_files(p, ac, av);
}
