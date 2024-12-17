/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:51:13 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_fork_error(t_pipex *pipex)
{
	perror("fork");
	close_all_pipes(pipex);
	free_resources(pipex);
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
