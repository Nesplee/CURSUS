/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:57 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/26 18:33:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	ADD_MATCH_TOKENS - Crée des tokens T_WORD pour chaque correspondance.
** ============================================================================
**	Parametres:
**		- @m:    tableau de chemins correspondants.
**		- @n:    nombre d’éléments dans m.
**		- @new:  adresse du tableau de t_token* à étendre.
**		- @ni:   pointeur vers le nombre de tokens déjà présents.
**
**	Processus:
**		1. Pour j de 0 à n-1 :
**		   a. Allouer un token via init_token().
**		   b. Affecter type T_WORD et dupliquer m[j] en value.
**		   c. Réallouer *new pour (*ni + 2) pointeurs.
**		   d. Placer le token à (*new)[*ni] et incrémenter *ni.
**		2. Terminer *new[*ni] par NULL.
**
**	Retour:
**		1 si succès, 0 sinon (mémoire).
*/
static int	add_match_tokens(char **m, int nm, t_token ***new, int *ni)
{
	int		j;
	t_token	*t;

	j = 0;
	while (j < nm)
	{
		t = init_token();
		if (!t)
			return (0);
		t->type = T_WORD;
		t->value = ft_strdup(m[j]);
		if (!t->value)
			return (free(t), 0);
		*new = realloc(*new, sizeof(**new) * (*ni + 2));
		if (!*new)
			return (free_token(t), 0);
		(*new)[(*ni)++] = t;
		j++;
	}
	(*new)[*ni] = NULL;
	return (1);
}

/*
** ============================================================================
**	PROCESS_TOKEN - Remplace un token par ses correspondances si wildcard.
** ============================================================================
**	Parametres:
**		- @tok:  token à traiter.
**		- @new:  adresse du tableau t_token** en construction.
**		- @ni:   pointeur vers le nombre de tokens déjà ajoutés.
**
**	Processus:
**		1. Si tok est T_WORD sans quote et contient '*' ou '?' :
**		   a. Appeler collect_matches() pour obtenir m et n.
**		   b. Si n > 0, libérer tok et appeler add_match_tokens().
**		   c. Libérer m puis retourner 1 ou 0.
**		2. Sinon, réallouer *new pour (*ni + 2), ajouter tok, terminer NULL.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	process_token(t_token *tok, t_token ***new, int *ni)
{
	char	**m;
	int		n;

	if (tok->type == T_WORD && tok->quote == NO_QUOTE
		&& (ft_strchr(tok->value, '*') || ft_strchr(tok->value, '?')))
	{
		m = collect_matches(tok->value, &n);
		if (n > 0)
		{
			free_token(tok);
			if (!add_match_tokens(m, n, new, ni))
				return (ft_split_free(m), 0);
			ft_split_free(m);
			return (1);
		}
		if (m)
			ft_split_free(m);
	}
	*new = realloc(*new, sizeof(**new) * (*ni + 2));
	if (!*new)
		return (0);
	(*new)[(*ni)++] = tok;
	(*new)[*ni] = NULL;
	return (1);
}

/*
** ============================================================================
**	EXPAND_WILDCARDS - Point d’entrée de l’expansion des wildcards.
** ============================================================================
**	Parametres:
**		- @tokens: adresse du tableau t_token** issu du parser.
**
**	Processus:
**		1. Sauvegarder *tokens dans old, initialiser new=NULL, ni=0.
**		2. Pour chaque old[i], appeler process_token().
**		3. Si une erreur survient, retourner 0.
**		4. Libérer old et mettre *tokens = new.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	expand_wildcards(t_token ***tokens)
{
	t_token	**old;
	t_token	**new;
	int		i;
	int		ni;

	old = *tokens;
	new = NULL;
	i = 0;
	ni = 0;
	while (old[i])
	{
		if (!process_token(old[i], &new, &ni))
			return (0);
		i++;
	}
	free(old);
	*tokens = new;
	return (1);
}
