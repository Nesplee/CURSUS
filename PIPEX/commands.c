/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:41:49 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/16 16:10:08 by dinguyen         ###   ########.fr       */
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

static char	**split_paths(char *path_variable)
{
	char	**paths;

	paths = ft_split(path_variable, ':');
	if (!paths)
	{
		ft_putstr_fd("Error: ft_split failed\n", 2);
		exit(EXIT_FAILURE);
	}
	return (paths);
}

static char	*construct_cmd_path(char *path, char *cmd)
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
	char	*path_variable;
	char	*cmd_path;
	int		i;

	path_variable = get_path_variable(envp);
	if (!path_variable)
		return (NULL);
	paths = split_paths(path_variable);
	i = 0;
	while (paths[i])
	{
		cmd_path = construct_cmd_path(paths[i], cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free_double_ptr(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_double_ptr(paths);
	return (NULL);
}

void	execute_command(t_pipex *pipex, char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	(void)pipex;
	args = ft_split(cmd, ' ');
	if (!args)
	{
		ft_putstr_fd("Error: split failed\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd_path = find_command_path(args[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error: command not found\n", 2);
		free_double_ptr(args);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		perror("execve");
		free(cmd_path);
		free_double_ptr(args);
		exit(EXIT_FAILURE);
	}
}
