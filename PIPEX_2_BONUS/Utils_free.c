/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:12:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 18:15:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

static void	free_pipes(t_pipex *p)
{
	int	i;

	if (!p || !p->pipes)
		return ;
	i = 0;
	while (i < p->pipe_count)
	{
		if (p->pipes[i])
		{
			close(p->pipes[i][READ]);
			close(p->pipes[i][WRITE]);
			free(p->pipes[i]);
		}
		i++;
	}
	free(p->pipes);
	p->pipes = NULL;
}

static void	free_pids(t_pipex *p)
{
	if (p->pids)
	{
		free(p->pids);
		p->pids = NULL;
	}
}

static void	free_files(t_pipex *p)
{
	if (p->infile >= 0)
		close(p->infile);
	if (p->outfile >= 0)
		close(p->outfile);
}

static void	free_limiter(t_pipex *p)
{
	if (p->limiter)
	{
		free(p->limiter);
		p->limiter = NULL;
	}
}

void	free_pipex(t_pipex *p)
{
	if (!p)
		return ;
	free_pipes(p);
	free_pids(p);
	free_limiter(p);
	free_files(p);
}
