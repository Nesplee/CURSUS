/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:51:38 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 14:06:29 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*try_paths(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = construct_cmd_path(paths[i], cmd);
		if (!cmd_path)
		{
			free_double_ptr(paths);
			return (NULL);
		}
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
