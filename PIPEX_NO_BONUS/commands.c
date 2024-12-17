/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:41:49 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 14:04:47 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path_variable(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

char	*construct_cmd_path(char *path, char *cmd)
{
	char	*temp;
	char	*cmd_path;

	temp = ft_strjoin(path, "/");
	if (!temp)
	{
		ft_putstr_fd("Error: ft_strjoin failed\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd_path = ft_strjoin(temp, cmd);
	free(temp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error: ft_strjoin failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (cmd_path);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_var;

	path_var = get_path_variable(envp);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	return (try_paths(paths, cmd));
}

void	handle_command_error(char **args, t_pipex *pipex, char *cmd_path)
{
	if (cmd_path)
		perror(cmd_path);
	else
	{
		ft_putstr_fd(args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (cmd_path)
		free(cmd_path);
	free_double_ptr(args);
	free(pipex);
	exit(127);
}

void	execute_command(t_pipex *pipex, char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
		handle_command_error(args, pipex, NULL);
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
		handle_command_error(args, pipex, NULL);
	if (execve(cmd_path, args, envp) == -1)
		handle_command_error(args, pipex, cmd_path);
	free(cmd_path);
	free_double_ptr(args);
	free(pipex);
}
