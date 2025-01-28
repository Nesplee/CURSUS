/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:40:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/13 19:26:03 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char *cmd, char **env, int in_fd, int *pipe_fd)
{
	char	**args;
	char	*path;

	if (dup2(in_fd, STDIN) == -1)
		error_exit(ERR_FILE);
	if (dup2(pipe_fd[1], STDOUT) == -1)
		error_exit(ERR_PIPE);
	close_fds(pipe_fd[0], pipe_fd[1]);
	args = parse_cmds(cmd);
	path = find_command_from_path(args[0], env);
	if (!path)
	{
		free_array(args);
		error_exit(ERR_CMD);
	}
	execve(path, args, env);
	free(path);
	free_array(args);
	error_exit(ERR_CMD);
}

static void	parent_process(char *cmd, char **env, int out_fd, int *pipe_fd)
{
	char	**args;
	char	*path;

	if (dup2(pipe_fd[0], STDIN) == -1)
		error_exit(ERR_PIPE);
	if (dup2(out_fd, STDOUT) == -1)
		error_exit(ERR_FILE);
	close_fds(pipe_fd[0], pipe_fd[1]);
	args = parse_cmds(cmd);
	path = find_command_from_path(args[0], env);
	if (!path)
	{
		free_array(args);
		error_exit(ERR_CMD);
	}
	execve(path, args, env);
	free(path);
	free_array(args);
	error_exit(ERR_CMD);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid;
	int		status;

	if (ac != 5)
		error_exit(ERR_ARGS);
	if (pipe(pipe_fd) == -1)
		error_exit(ERR_PIPE);
	in_fd = open(av[1], O_RDONLY);
	if (in_fd < 0)
		exit(1);
	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd < 0)
		error_exit(ERR_FILE);
	pid = fork();
	if (pid == -1)
		error_exit(ERR_FORK);
	if (pid == 0)
		child_process(av[2], env, in_fd, pipe_fd);
	waitpid(pid, &status, 0);
	parent_process(av[3], env, out_fd, pipe_fd);
	return (0);
}
