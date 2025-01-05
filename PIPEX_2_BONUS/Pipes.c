/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:33:37 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 18:53:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	create_pipes(t_pipex *p)
{
	int	i;
	int	pipe_status;

	i = 0;
	while (i < p->pipe_count)
	{
		pipe_status = pipe(p->pipes[i]);
		if (pipe_status == -1)
			error_system("Error: Pipe creation failed");
		i++;
	}
}

void	close_pipes(t_pipex *p)
{
	int	i;

	if (p->infile >= 0)
		close(p->infile);
	if (p->outfile >= 0)
		close(p->outfile);
	i = 0;
	while (i < p->pipe_count)
	{
		if (p->pipes[i])
		{
			close(p->pipes[i][READ]);
			close(p->pipes[i][WRITE]);
		}
		i++;
	}
}
