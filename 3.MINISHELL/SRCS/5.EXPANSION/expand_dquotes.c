/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:59:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/08 18:17:16 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	APPEND_BEFORE_VAR - Concatène le texte avant une variable.
** ============================================================================
**	Parametres:
**		- @res:        chaîne résultat accumulée.
**		- @cur:        pointeur sur le début du segment courant.
**		- @var_start:  pointeur sur le caractère '$' de la variable.
**
**	Variables locales:
**		- len:  longueur du fragment avant '$'.
**		- frag: sous-chaîne extraite à concaténer.
**
**	Processus:
**		1. Calculer len = var_start - cur.
**		2. Si len > 0 :
**		   a. frag = ft_substr(cur, 0, len).
**		   b. Concaténer frag à res via ft_strjoin_free().
**		   c. Libérer frag.
**		3. Retourner res (ou NULL en cas d’erreur, res libéré).
**
**	Retour:
**		Chaîne résultante ou NULL.
*/
static char	*append_before_var(char *res, char *cur, char *var_start)
{
	int		len;
	char	*frag;

	len = var_start - cur;
	if (len > 0)
	{
		frag = ft_substr(cur, 0, len);
		if (!frag)
			return (free(res), NULL);
		res = ft_strjoin_free(res, frag);
		free(frag);
	}
	return (res);
}

/*
** ============================================================================
**	APPEND_EXIT_STATUS_FRAG - Concatène le code de sortie.
** ============================================================================
**	Parametres:
**		- @res:    chaîne résultat accumulée.
**		- @status: code de sortie à insérer.
**
**	Variables locales:
**		- num: représentation string de status.
**
**	Processus:
**		1. num = ft_itoa(status).
**		2. Concaténer num à res via ft_strjoin_free().
**		3. Libérer num.
**		4. Retourner res (ou NULL en cas d’erreur, res libéré).
**
**	Retour:
**		Chaîne résultante ou NULL.
*/
static char	*append_exit_status_frag(char *res, int status)
{
	char	*num;

	num = ft_itoa(status);
	if (!num)
		return (free(res), NULL);
	res = ft_strjoin_free(res, num);
	free(num);
	return (res);
}

/*
** ============================================================================
**	APPEND_VAR_FRAGMENT - Concatène la valeur d’une variable.
** ============================================================================
**	Parametres:
**		- @res:   chaîne résultat accumulée.
**		- @cur:   pointeur sur le début du nom de variable.
**		- @env:   tableau d’environnement.
**		- @olen:  pointeur pour stocker la longueur du nom.
**
**	Variables locales:
**		- len:    longueur du nom de variable.
**		- name:   nom extrait via ft_substr().
**		- val:    valeur récupérée via get_var_value().
**
**	Processus:
**		1. Compter len tant que ft_isalnum||‘_’.
**		2. Si len == 0, concaténation de "$" à res.
**		3. name = ft_substr(cur, 0, len), puis val = get_var_value(name).
**		4. Concaténer val à res via ft_strjoin_free().
**		5. Libérer name et val.
**		6. Retourner res ou NULL.
**
**	Retour:
**		Chaîne résultante ou NULL.
*/
static char	*append_var_fragment(char *res, char *cur, char **env, int *olen)
{
	char	*name;
	char	*val;
	int		len;

	if (ft_isdigit((unsigned char)cur[0]))
		len = 1;
	else
	{
		len = 0;
		while (cur[len] && (ft_isalnum((unsigned char)cur[len])
				|| cur[len] == '_'))
			len++;
	}
	*olen = len;
	if (len == 0)
		return (ft_strjoin_free(res, "$"));
	name = ft_substr(cur, 0, len);
	if (!name)
		return (free(res), NULL);
	val = get_var_value(name, env);
	free(name);
	if (!val)
		return (free(res), NULL);
	res = ft_strjoin_free(res, val);
	return (free(val), res);
}

/*
** ============================================================================
**	PROCESS_SEGMENT - Traite un segment contenant une variable.
** ============================================================================
**	Parametres:
**		- @pres:          adresse de la chaîne résultat.
**		- @pcur:          adresse du pointeur courant dans tok->value.
**		- @env:           tableau d’environnement.
**		- @exit_status:   code de sortie du dernier builtin.
**
**	Variables locales:
**		- vs:    position du '$' dans le segment.
**		- olen:  longueur du nom de variable.
**
**	Processus:
**		1. vs = ft_strchr(*pcur, '$').
**		2. append_before_var(pres, *pcur, vs).
**		3. Si *(vs+1) == '?' : append_exit_status_frag().
**		4. Sinon : append_var_fragment() et avancer *pcur de olen.
**		5. Mettre à jour *pcur.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	process_segment(char **pres, char **pcur,
	char **env, int exit_status)
{
	char	*vs;
	int		olen;

	vs = ft_strchr(*pcur, '$');
	*pres = append_before_var(*pres, *pcur, vs);
	if (!*pres)
		return (0);
	if (*(vs + 1) == '?')
	{
		*pres = append_exit_status_frag(*pres, exit_status);
		if (!*pres)
			return (0);
		*pcur = vs + 2;
	}
	else
	{
		*pcur = vs + 1;
		*pres = append_var_fragment(*pres, *pcur, env, &olen);
		if (!*pres)
			return (0);
		*pcur += olen;
	}
	return (1);
}

/*
** ============================================================================
**	EXPAND_VAR_IN_DQUOTES - Étend les variables dans une valeur entre "".
** ============================================================================
**	Parametres:
**		- @tok:          token dont value sera modifiée.
**		- @env:          tableau d’environnement.
**		- @exit_status:  code de sortie du dernier builtin.
**
**	Variables locales:
**		- res:  nouvelle chaîne construite.
**		- cur:  pointeur sur la partie non encore traitée.
**		- vs:   position du caractère '$'.
**
**	Processus:
**		1. res = ft_strdup("").
**		2. cur = tok->value.
**		3. Boucler :
**		   a. vs = ft_strchr(cur, '$').
**		   b. Si !vs || vs[1] == '\0', concaténer cur et break.
**		   c. Sinon, process_segment().
**		4. Libérer l’ancienne tok->value et affecter res.
**
**	Retour:
**		1 si succès, 0 sinon.
*/

int	expand_var_in_dquotes(t_token *tok, char **env, int exit_status)
{
	char	*res;
	char	*cur;

	if (!ft_strchr(tok->value, '$'))
		return (1);
	res = ft_strdup("");
	if (!res)
		return (0);
	cur = tok->value;
	while (ft_strchr(cur, '$'))
	{
		if (!process_segment(&res, &cur, env, exit_status))
			return (0);
	}
	res = ft_strjoin_free(res, cur);
	free(tok->value);
	tok->value = res;
	return (1);
}
