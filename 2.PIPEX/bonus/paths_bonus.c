/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:45:52 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/08 16:21:28 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_path_from_env(char **env)
{
	char	*path;

	if (!env || !*env)
		return (ft_strdup("/usr/bin:/bin"));
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			path = ft_strdup(*env + 5);
			if (!path)
				return (NULL);
			return (path);
		}
		env++;
	}
	return (ft_strdup("/usr/bin:/bin"));
}

static char	*build_cmd_path(char *dir, char *cmd)
{
	char	*temp;
	char	*final_path;
	int		access_status;

	temp = ft_strjoin(dir, "/");
	if (temp == NULL)
		return (NULL);
	final_path = ft_strjoin(temp, cmd);
	free(temp);
	if (final_path == NULL)
		return (NULL);
	access_status = access(final_path, F_OK | X_OK);
	if (access_status == 0)
		return (final_path);
	free(final_path);
	return (NULL);
}

char	*find_command_from_path(char *cmd, char **env)
{
	char	*path;
	char	*cmd_path;
	char	**paths;
	int		i;

	path = get_path_from_env(env);
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		cmd_path = build_cmd_path(paths[i], cmd);
		if (cmd_path)
		{
			ft_split_free(paths);
			return (cmd_path);
		}
		i++;
	}
	ft_split_free(paths);
	return (NULL);
}
