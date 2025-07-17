/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:38:07 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 21:22:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

static char	**copy_env(char **env)
{
	int		n;
	char	**dup;
	int		i;

	n = ft_count_env(env);
	dup = (char **)malloc((n + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = env[i];
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

static void	sort_env(char **arr)
{
	int		n;
	int		i;
	int		j;
	char	*tmp;

	n = ft_count_env(arr);
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*
** ============================================================================
**      PROCESS_EXPORT_ARG - Traite un argument pour la builtin export.
** ============================================================================
**      Parametres:
**          - @arg: chaîne de la forme KEY=VALUE.
**          - @env: pointeur vers le tableau d'environnement.
**
**      Variables locales:
**          - eq: position du caractère '=' dans arg.
**
**      Processus:
**          1. Rechercher '=' via ft_strchr().
**          2. Vérifier présence et validité de l'identifiant :
**             a. eq ne doit pas être NULL ni arg (clé vide).
**             b. Premier caractère doit être lettre ou '_'.
**          3. En cas d'identifiant invalide, afficher message d'erreur.
**          4. Sinon, mettre à jour l'environnement via ft_update_env().
**
**      Retour:
**          EXIT_SUCCESS ou EXIT_FAILURE.
*/

static int	process_export_arg(char *arg, char ***env)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	if (!ft_isalpha((unsigned char)arg[0]) && arg[0] != '_')
	{
		ft_putstr_fd("export: `", STDERR);
		ft_putstr_fd(arg, STDERR);
		ft_putstr_fd("': not a valid identifier\n", STDERR);
		return (EXIT_FAILURE);
	}
	if (eq == NULL)
		return (EXIT_SUCCESS);
	if (eq == arg)
	{
		ft_putstr_fd("export: `", STDERR);
		ft_putstr_fd(arg, STDERR);
		ft_putstr_fd("': not a valid identifier\n", STDERR);
		return (EXIT_FAILURE);
	}
	return (ft_update_env(arg, env));
}

static void	print_sorted_env_quote(char **arr)
{
	int		i;
	char	*eq;
	char	*name;
	char	*value;

	i = 0;
	while (arr[i])
	{
		eq = ft_strchr(arr[i], '=');
		if (eq)
		{
			name = ft_substr(arr[i], 0, eq - arr[i]);
			value = ft_strdup(eq + 1);
			ft_putstr_fd(name, STDOUT);
			ft_putstr_fd("=\"", STDOUT);
			ft_putstr_fd(value, STDOUT);
			ft_putendl_fd("\"", STDOUT);
			free(name);
			free(value);
		}
		else
			ft_putendl_fd(arr[i], STDOUT);
		i++;
	}
}
/*
** ============================================================================
**      FT_EXPORT - Implémente la commande export du shell.
** ============================================================================
**      Parametres:
**          - @args: tableau de chaînes d'arguments (args[0] = "export").
**          - @env:  pointeur vers le tableau d'environnement.
**
**      Variables locales:
**          - i: indice de boucle sur args[].
**          - ret: code de retour de process_export_arg().
**
**      Processus:
**          1. Si aucun argument supplémentaire, appeler ft_env() pour afficher.
**          2. Sinon, pour chaque args[i] :
**             a. Appeler process_export_arg().
**             b. En cas d'erreur, retourner immédiatement le code d'erreur.
**          3. Retourner EXIT_SUCCESS si tous les arguments sont valides.
**
**      Retour:
**          EXIT_SUCCESS ou EXIT_FAILURE.
*/

int	ft_export(char **args, char ***env)
{
	int		i;
	char	**dup;

	if (!args[1])
	{
		dup = copy_env(*env);
		if (!dup)
			return (EXIT_FAILURE);
		sort_env(dup);
		print_sorted_env_quote(dup);
		free(dup);
		return (EXIT_SUCCESS);
	}
	i = 1;
	while (args[i])
	{
		if (process_export_arg(args[i], env) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
