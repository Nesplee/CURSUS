/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:33:47 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:17:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_ac(int ac)
{
	if (ac < 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2\n", 2);
		ft_putstr_fd("   or: ./pipex here_doc LIMITER cmd1 cmd2 file\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

static void	init_here_doc(t_pipex *pipex, char **av, int ac)
{
	pipex->limiter = av[2];
	pipex->cmd_count = ac - 4;
}

int	open_files(t_pipex *pipex, char **av)
{
	int	fd[2];

	if (pipex->here_doc)
	{
		if (pipe(fd) == -1)
			return (-1);
		handle_here_doc(pipex->limiter, fd[1]);
		pipex->infile = fd[0];
		pipex->outfile = open(av[pipex->cmd_count + 2],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->infile = open(av[1], O_RDONLY);
		pipex->outfile = open(av[pipex->cmd_count + 2],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->infile < 0)
		perror(av[1]);
	if (pipex->outfile < 0)
		perror(av[pipex->cmd_count + 2]);
	return (0);
}

t_pipex	*init_pipex(int ac, char **av)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->here_doc = (ft_strncmp(av[1], "here_doc", 9) == 0);
	if (pipex->here_doc)
		init_here_doc(pipex, av, ac);
	else
	{
		pipex->limiter = NULL;
		pipex->cmd_count = ac - 3;
	}
	pipex->pipe_count = pipex->cmd_count - 1;
	if (!init_memory(pipex) || open_files(pipex, av) == -1)
	{
		free_resources(pipex);
		return (NULL);
	}
	create_pipes(pipex);
	return (pipex);
}
