/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:29:07 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 01:39:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

int	process_heredocs(t_command **cmds,
					t_shell *shell, char **envp)
{
	int	ci;
	int	ri;

	ci = 0;
	(void)envp;
	while (cmds[ci])
	{
		ri = 0;
		while (ri < cmds[ci]->redir_count)
		{
			if (cmds[ci]->redirs[ri]->type == REDIR_HEREDOC)
			{
				if (!handle_heredoc(cmds[ci]->redirs[ri],
						shell->env, shell->exit_status))
				{
					shell->exit_status = 1;
					return (0);
				}
			}
			ri++;
		}
		ci++;
	}
	return (1);
}

int	spawn_pipeline(t_command **cmds, t_shell *shell)
{
	int	idx;
	int	prev_fd;

	idx = 0;
	prev_fd = -1;
	g_signal = 1;
	while (cmds[idx])
	{
		if (process_command_iteration(idx, cmds, &prev_fd, shell) < 0)
		{
			dis_pipe_err();
			shell->exit_status = EXIT_FAILURE;
			return (0);
		}
		idx++;
	}
	return (1);
}

int	collect_exit_status(t_shell *shell)
{
	int	status;

	(void)shell;
	while (wait(&status) > 0)
		;
	g_signal = 0;
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (WEXITSTATUS(status));
}
