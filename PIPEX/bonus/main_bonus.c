/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:40:10 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/13 20:05:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	exec_cmd(t_data *d, int idx, int fd_in, int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error_exit(ERR_FORK);
	if (pid == 0)
	{
		if (dup2(fd_in, STDIN) < 0 || dup2(fd_out, STDOUT) < 0)
			error_exit(ERR_PIPE);
		close_fds(fd_in, fd_out);
		execve(find_command_from_path(parse_cmds(d->av[idx])[0], d->env),
			parse_cmds(d->av[idx]), d->env);
		error_exit(ERR_CMD);
	}
	close_fds(fd_in, fd_out);
	wait(NULL);
}

static int	open_outfile(char **av, int ac)
{
	int	fd;

	if (is_here_doc(av[1]))
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		error_exit(ERR_FILE);
	return (fd);
}

static void	exec_pipe(t_data *d, int idx, int fd_in, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(fd_in, STDIN) < 0 || dup2(pipe_fd[1], STDOUT) < 0)
		error_exit(ERR_PIPE);
	close(fd_in);
	close(pipe_fd[1]);
	execve(find_command_from_path(parse_cmds(d->av[idx])[0], d->env),
		parse_cmds(d->av[idx]), d->env);
	error_exit(ERR_CMD);
}

static void	launch_cmds(t_data *d, int idx, int fd_in)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (idx == d->ac - 2)
	{
		exec_cmd(d, idx, fd_in, open_outfile(d->av, d->ac));
		close(fd_in);
		return ;
	}
	if (pipe(pipe_fd) < 0)
		error_exit(ERR_PIPE);
	pid = fork();
	if (pid < 0)
		error_exit(ERR_FORK);
	if (pid == 0)
		exec_pipe(d, idx, fd_in, pipe_fd);
	close(pipe_fd[1]);
	close(fd_in);
	wait(NULL);
	launch_cmds(d, idx + 1, pipe_fd[0]);
}

int	main(int ac, char **av, char **env)
{
	t_data	d;
	int		fd_in;

	if (ac < 5)
		error_exit(ERR_ARGS);
	d.ac = ac;
	d.av = av;
	d.env = env;
	if (is_here_doc(av[1]))
	{
		if (ac < 6)
			error_exit(ERR_ARGS);
		handle_here_doc(av[2], &fd_in);
		launch_cmds(&d, 3, fd_in);
	}
	else
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in < 0)
			error_exit(ERR_FILE);
		launch_cmds(&d, 2, fd_in);
	}
	return (0);
}
