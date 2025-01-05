/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:40:26 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 22:33:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	wait_children(t_pipex *p)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	last_status = 0;
	while (i < p->cmd_count)
	{
		if (waitpid(p->pids[i], &status, 0) == -1)
			error_system("waitpid failed");
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_status = WTERMSIG(status) + 128;
		i++;
	}
	if (p->outfile == -1)
		return (1);
	return (last_status);
}

static char	**validate_cmd(t_pipex *p, char *cmd)
{
	char	**cmd_args;

	cmd_args = parse_cmds(cmd);
	if (!cmd_args || !cmd_args[0])
	{
		free_pipex(p);
		error_cmd(cmd, "Invalid command");
	}
	return (cmd_args);
}

static char	*get_cmd_path(t_pipex *p, char **cmd_args, char **env)
{
	char	*cmd_path;

	if (!cmd_args[0])
	{
		cleanup_cmd(cmd_args, NULL);
		free_pipex(p);
		exit(127);
	}
	if (access(cmd_args[0], X_OK) == 0)
		cmd_path = ft_strdup(cmd_args[0]);
	else
		cmd_path = find_command_from_path(cmd_args[0], env);
	if (!cmd_path)
	{
		cleanup_cmd(cmd_args, NULL);
		free_pipex(p);
		exit(127);
	}
	return (cmd_path);
}

static void	exe_child_cmd(t_pipex *p, char *c_path, char **c_args, char **env)
{
	if (!c_path)
	{
		cleanup_cmd(c_args, NULL);
		free_pipex(p);
		error_cmd(c_args[0], "Command not found");
		exit(127);
	}
	if (execve(c_path, c_args, env) == -1)
	{
		cleanup_cmd(c_args, c_path);
		free_pipex(p);
		if (errno == EACCES)
			error_cmd(c_args[0], "Permission denied");
		error_cmd(c_args[0], "Command not found");
		exit(127);
	}
}

void	child_process(t_pipex *p, int index, char **av, char **env)
{
	char	*cmd_path;
	char	**cmd_args;

	cmd_args = validate_cmd(p, av[index + 2]);
	if (!cmd_args || !cmd_args[0])
	{
		cleanup_cmd(cmd_args, NULL);
		free_pipex(p);
		error_cmd(av[index + 2], "Command not found");
		exit(127);
	}
	cmd_path = get_cmd_path(p, cmd_args, env);
	exe_child_cmd(p, cmd_path, cmd_args, env);
}
