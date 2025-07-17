/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:57:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 17:08:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	JOIN_PATH - Concatène un répertoire et une commande avec '/'.
** ============================================================================
**	Parametres:
**		- @dir: chemin du répertoire.
**		- @cmd: nom de la commande.
**
**	Processus:
**		1. Allouer len(dir) + 1 + len(cmd) + 1 octets.
**		2. Copier dir, ajouter '/', copier cmd, terminer par '\\0'.
**
**	Retour:
**		Chaîne allouée du chemin complet ou NULL.
*/
static char	*join_path(const char *dir, const char *cmd)
{
	size_t	len_dir;
	size_t	len_cmd;
	char	*full_path;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_dir + 1 + len_cmd + 1);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len_dir + 1);
	full_path[len_dir] = '/';
	ft_strlcpy(full_path + len_dir + 1, cmd, len_cmd + 1);
	return (full_path);
}

/*
** ============================================================================
**	GET_PATH_ENV - Récupère la valeur de PATH depuis env ou getenv().
** ============================================================================
**	Parametres:
**		- @env: tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. Parcourir env[] pour trouver "PATH=".
**		2. Si trouvé, retourner pointeur après "PATH=".
**		3. Sinon, retourner getenv("PATH").
**
**	Retour:
**		Chaîne PATH ou NULL.
*/
static char	*get_path_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*search_in_paths(char **paths, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = join_path(paths[i], cmd);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*find_executable(char *cmd, char **env)
{
	char	*path_env;
	char	**paths;
	char	*exec;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_path_env(env);
	if (!path_env)
	{
		dis_cmd_not_found_err(cmd);
		exit(127);
	}
	paths = ft_split(path_env, ':');
	exec = search_in_paths(paths, cmd);
	ft_split_free(paths);
	if (exec)
		return (exec);
	dis_cmd_not_found_err(cmd);
	exit(127);
}
