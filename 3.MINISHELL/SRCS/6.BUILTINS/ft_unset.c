/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:02:42 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/29 12:11:04 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
** ft_find_unset_index
** ============================================================================
** Description:
**   Cherche l'index de la variable dont le nom (avant '=') correspond
**   à var dans le tableau env.
**
** Paramètres:
**   var : Nom de la variable (sans le '=' et la valeur).
**   env : Tableau d'environnement.
**
** Retour:
**   L'index si trouvé, -1 sinon.
*/

static int	ft_find_unset_index(char *var, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
			return (i);
		i = i + 1;
	}
	return (-1);
}

/*
** ============================================================================
** ft_build_new_env
** ============================================================================
** Description:
**   Construit un nouveau tableau d'environnement en omissionnant
**   l'élément dont l'index est idx.
**
** Paramètres:
**   env : Tableau d'environnement.
**   idx : Index de l'élément à supprimer.
**
** Retour:
**   Le nouveau tableau ou NULL en cas d'échec.
*/

static char	**ft_build_new_env(char **env, int idx)
{
	int		count;
	int		i;
	int		j;
	char	**new_env;

	count = ft_count_env(env);
	new_env = malloc(sizeof(char *) * count);
	if (new_env == 0)
		return (0);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (i == idx)
			free(env[i]);
		else
		{
			new_env[j] = env[i];
			j = j + 1;
		}
		i = i + 1;
	}
	new_env[j] = NULL;
	return (new_env);
}

/*
** ============================================================================
** ft_unset
** ============================================================================
** Description:
**   Supprime la variable d'environnement dont le nom est donné dans args[1].
**   Si trouvée, reconstruit le tableau env en utilisant ft_build_new_env.
**
** Paramètres:
**   args : Tableau de chaînes (commande et arguments).
**   env  : Adresse du tableau d'environnement.
**
** Retour:
**   EXIT_SUCCESS si la suppression est effectuée ou si la variable
**   est absente, EXIT_FAILURE en cas d'erreur.
*/

int	ft_unset(char **args, char ***env)
{
	int		idx;
	char	**new_env;

	if (args[1] == 0)
	{
		ft_putstr_fd("unset: not enough arguments\n", STDERR);
		return (EXIT_FAILURE);
	}
	idx = ft_find_unset_index(args[1], *env);
	if (idx < 0)
		return (EXIT_SUCCESS);
	new_env = ft_build_new_env(*env, idx);
	if (new_env == 0)
		return (EXIT_FAILURE);
	free(*env);
	*env = new_env;
	return (EXIT_SUCCESS);
}
