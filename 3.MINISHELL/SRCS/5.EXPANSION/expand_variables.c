/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:52:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 21:26:51 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	GET_VAR_VALUE - Recherche la valeur d'une variable dans l'env.
** ============================================================================
**	Parametres:
**		- @name: nom de la variable (sans '$').
**		- @env:  tableau de chaînes "KEY=VALUE".
**
**	Variables locales:
**		- i:   indice courant dans env.
**		- len: longueur du nom.
**		- res: valeur dupliquée trouvée.
**
**	Processus:
**		1. len = ft_strlen(name).
**		2. Pour chaque env[i] non NULL :
**		   a. Si ft_strncmp(env[i], name, len) == 0 et env[i][len] == '=' :
**		      - res = ft_strdup(env[i] + len + 1).
**		      - Retourner res.
**		3. Si non trouvé, retourner ft_strdup("").
**
**	Retour:
**		Chaine allouée de la valeur ou chaine vide.
*/
char	*get_var_value(char *name, char **env)
{
	int		i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			res = ft_strdup(env[i] + len + 1);
			return (res);
		}
		i++;
	}
	return (ft_strdup(""));
}

/*
** ============================================================================
**	REPLACE_VAR_TOKEN - Remplace un token variable par sa valeur.
** ============================================================================
**	Parametres:
**		- @tok: token de type T_VAR contenant "$name".
**		- @env: tableau d'environnement.
**
**	Variables locales:
**		- name: nom extrait (tok->value + 1).
**		- val:  valeur récupérée via get_var_value().
**
**	Processus:
**		1. name = ft_substr(tok->value, 1, ft_strlen(tok->value) - 1).
**		2. val = get_var_value(name, env); free(name).
**		3. free(tok->value); tok->value = val; tok->type = T_WORD.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	replace_var_token(t_token *tok, char **env)
{
	char	*name;
	char	*val;

	name = ft_substr(tok->value, 1, ft_strlen(tok->value) - 1);
	if (!name)
		return (0);
	val = get_var_value(name, env);
	free(name);
	if (!val)
		return (0);
	free(tok->value);
	tok->value = val;
	tok->type = T_WORD;
	return (1);
}

/*
** ============================================================================
**	REPLACE_EXIT_STATUS - Insère le code de sortie dans un token.
** ============================================================================
**	Parametres:
**		- @tok:         token de type T_VAR "$?".
**		- @exit_status: code de sortie à insérer.
**
**	Variables locales:
**		- val: chaîne obtenue via ft_itoa(exit_status).
**
**	Processus:
**		1. val = ft_itoa(exit_status).
**		2. free(tok->value); tok->value = val; tok->type = T_WORD.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	replace_exit_status(t_token *tok, int exit_status)
{
	char	*val;

	val = ft_itoa(exit_status);
	if (!val)
		return (0);
	free(tok->value);
	tok->value = val;
	tok->type = T_WORD;
	return (1);
}
