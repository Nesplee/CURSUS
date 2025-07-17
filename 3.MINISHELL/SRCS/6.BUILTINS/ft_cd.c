/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:38:21 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 10:51:33 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

int	set_env_var(char **env, const char *key, const char *value)
{
	int		i;
	size_t	klen;
	char	*tmp;
	char	*entry;

	klen = ft_strlen(key);
	tmp = ft_strjoin_free(ft_strdup(key), "=");
	if (!tmp)
		return (0);
	entry = ft_strjoin_free(tmp, value);
	if (!entry)
		return (0);
	i = 0;
	while (env[i] && (ft_strncmp(env[i], key, klen) || env[i][klen] != '='))
		i++;
	if (env[i])
		free(env[i]);
	env[i] = entry;
	if (!env[i + 1])
		env[i + 1] = NULL;
	return (1);
}

static char	*expand_tilde(char *arg)
{
	char	*home;

	home = getenv("HOME");
	if (!home)
		home = "";
	if (arg[1] == '\0')
		return (ft_strdup(home));
	if (arg[1] == '/')
		return (ft_strjoin_free(ft_strdup(home), arg + 1));
	return (ft_strdup(arg));
}

static int	prepare_cd(char **args, char **path, char **oldpwd)
{
	*oldpwd = getcwd(NULL, 0);
	if (!args[1])
	{
		*path = getenv("HOME");
		if (!*path)
		{
			ft_putstr_fd("cd: HOME not set\n", STDERR);
			return (EXIT_FAILURE);
		}
	}
	else if (args[1][0] == '~')
		*path = expand_tilde(args[1]);
	else
		*path = args[1];
	return (EXIT_SUCCESS);
}

static int	change_and_update(char *path, char **env, char *oldpwd)
{
	char	*pwd;
	int		ret;

	ret = EXIT_SUCCESS;
	if (chdir(path) < 0)
	{
		ft_putstr_fd("cd: ", STDERR);
		ft_putstr_fd(path, STDERR);
		ft_putstr_fd(": ", STDERR);
		perror("");
		ret = EXIT_FAILURE;
	}
	if (oldpwd)
	{
		set_env_var(env, "OLDPWD", oldpwd),
		free(oldpwd);
	}
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		set_env_var(env, "PWD", pwd),
		free(pwd);
	}
	return (ret);
}

int	ft_cd(char **args, char **env)
{
	char	*path;
	char	*oldpwd;
	int		ret;
	int		need_free;

	if (prepare_cd(args, &path, &oldpwd) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	need_free = (args[1] && args[1][0] == '~');
	ret = change_and_update(path, env, oldpwd);
	if (need_free)
		free(path);
	return (ret);
}
