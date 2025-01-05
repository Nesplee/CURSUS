/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:44 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 19:49:40 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	get_exit_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	return (status);
}

void	cleanup_cmd(char **cmd_args, char *cmd_path)
{
	if (cmd_args)
		ft_split_free(cmd_args);
	if (cmd_path)
		free(cmd_path);
}

void	error_system(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *cmd, char *detail)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (cmd && *cmd)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (detail)
		ft_putendl_fd(detail, STDERR_FILENO);
	if (ft_strcmp(detail, "Command not found") == 0)
		exit(127);
	if (ft_strcmp(detail, "Permission denied") == 0)
		exit(126);
	if (ft_strcmp(detail, "Invalid command") == 0)
		exit(127);
	exit(1);
}

void	error_file(char *file, char *detail)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (file)
	{
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (detail)
		ft_putendl_fd(detail, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
