/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:16:02 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/29 12:09:08 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	ft_find_var_index - Cherche l'index d'une variable "VAR=VALUE" dans env.
** ============================================================================
**	Paramètres:
**		- @new_var: chaîne "VAR=VALUE".
**		- @env:     tableau d'environnement.
**
**	Processus:
**		1. Repérer '=' dans new_var.
**		2. Extraire le nom avant '='.
**		3. Parcourir env[] pour trouver "NAME=".
**		4. Retourner l'indice ou -1 si absent.
**
**	Retour:
**		Index trouvé ou -1.
*/
static int	ft_find_var_index(char *new_var, char **env)
{
	size_t	i;
	size_t	name_len;
	char	*eq;
	char	*name;

	i = 0;
	eq = ft_strchr(new_var, '=');
	if (eq == 0)
		return (-1);
	name_len = eq - new_var;
	name = ft_substr(new_var, 0, name_len);
	if (name == 0)
		return (-1);
	while (env[i])
	{
		if ((ft_strncmp(env[i], name, name_len) == 0)
			&& (env[i][name_len] == '='))
		{
			free(name);
			return ((int)i);
		}
		i++;
	}
	free(name);
	return (-1);
}

/*
** ============================================================================
**	ft_count_env - Compte le nombre de chaînes dans env.
** ============================================================================
**	Paramètres:
**		- @env: tableau d'environnement.
**
**	Processus:
**		1. Parcourir env[] jusqu'au NULL.
**		2. Incrémenter un compteur.
**
**	Retour:
**		Nombre d'éléments.
*/
int	ft_count_env(char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

/*
** ============================================================================
**	ft_update_existing_env - Met à jour une var existante dans env.
** ============================================================================
**	Paramètres:
**		- @new_var: chaîne "VAR=VALUE".
**		- @index:   position dans *env.
**		- @env:     adresse du tableau d'environnement.
**
**	Processus:
**		1. Dupliquer new_var.
**		2. Free l'ancienne chaîne puis remplacer.
**
**	Retour:
**		EXIT_SUCCESS ou EXIT_FAILURE.
*/
static int	ft_update_existing_env(char *new_var, int index, char ***env)
{
	char	*tmp;

	tmp = ft_strdup(new_var);
	if (tmp == 0)
		return (EXIT_FAILURE);
	free((*env)[index]);
	(*env)[index] = tmp;
	return (EXIT_SUCCESS);
}

/*
** ============================================================================
**	ft_add_new_env - Ajoute une nouvelle var dans env.
** ============================================================================
**	Paramètres:
**		- @new_var: chaîne "VAR=VALUE".
**		- @env:     adresse du tableau d'environnement.
**
**	Processus:
**		1. Compter les entrées existantes.
**		2. Allouer un tableau de taille +2.
**		3. Copier les pointeurs et ajouter new_var dupliqué.
**		4. Terminer par NULL, free l'ancien env.
**
**	Retour:
**		EXIT_SUCCESS ou EXIT_FAILURE.
*/
static int	ft_add_new_env(char *new_var, char ***env)
{
	int		count;
	int		i;
	char	**new_env;
	char	*tmp;

	count = ft_count_env(*env);
	new_env = malloc(sizeof(char *) * (count + 2));
	if (new_env == 0)
		return (EXIT_FAILURE);
	i = 0;
	while (i < count)
	{
		new_env[i] = (*env)[i];
		i = i + 1;
	}
	tmp = ft_strdup(new_var);
	if (tmp == 0)
		return (EXIT_FAILURE);
	new_env[i] = tmp;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
	return (EXIT_SUCCESS);
}

/*
** ============================================================================
**	ft_update_env - Met à jour ou ajoute une variable dans env.
** ============================================================================
**	Paramètres:
**		- @new_var: chaîne "VAR=VALUE".
**		- @env:     adresse du tableau d'environnement.
**
**	Processus:
**		1. Chercher index via ft_find_var_index().
**		2. Si existante, ft_update_existing_env().
**		3. Sinon, ft_add_new_env().
**
**	Retour:
**		EXIT_SUCCESS ou EXIT_FAILURE.
*/
int	ft_update_env(char *new_var, char ***env)
{
	int		index;

	index = ft_find_var_index(new_var, *env);
	if (index >= 0)
		return (ft_update_existing_env(new_var, index, env));
	return (ft_add_new_env(new_var, env));
}
