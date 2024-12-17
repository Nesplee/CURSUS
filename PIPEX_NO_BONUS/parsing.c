/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:33:47 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 13:00:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_ac(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Usage: Pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	open_files(t_pipex *pipex, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		perror(av[1]);
	pipex->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		perror(av[4]);
	return (0);
}

int	setup_pipes(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
	{
		ft_putstr_fd("Error: pipe creation failed\n", 2);
		close(pipex->infile);
		close(pipex->outfile);
		free(pipex);
		exit(EXIT_FAILURE);
	}
	return (0);
}

t_pipex	*init_pipex(int ac, char **av)
{
	t_pipex	*pipex;

	(void)ac;
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (open_files(pipex, av) == -1)
	{
		free(pipex);
		exit(EXIT_FAILURE);
	}
	setup_pipes(pipex);
	return (pipex);
}
