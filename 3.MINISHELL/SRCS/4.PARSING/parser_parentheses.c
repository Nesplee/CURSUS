/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parentheses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:35:19 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:22:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	FIND_CLOSING - Trouve la parenthèse fermante correspondante.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* à parcourir.
**		- @start:  indice juste après la parenthèse ouvrante.
**
**	Variables locales:
**		- i:     position courante dans tokens.
**		- depth: compteur de profondeur de parenthèses.
**
**	Processus:
**		1. Initialiser depth = 1 et i = start.
**		2. Tant que tokens[i] existe et depth > 0 :
**		   a. Si token est '(' incrémenter depth.
**		   b. Si token est ')' décrémenter depth.
**		   c. Incrémenter i.
**		3. Si depth != 0, erreur de correspondance.
**		4. Retourner i - 1 comme index de la parenthèse fermante.
**
**	Retour:
**		Index de la parenthèse fermante, ou -1 en cas d’erreur.
*/
static int	find_closing(t_token **tokens, int start)
{
	int	i;
	int	depth;

	depth = 1;
	i = start;
	while (tokens[i] && depth > 0)
	{
		if (tokens[i]->type == T_OPERATOR)
		{
			if (tokens[i]->ope == OP_LPAR)
				depth++;
			else if (tokens[i]->ope == OP_RPAR)
				depth--;
		}
		i++;
	}
	if (depth != 0)
		return (-1);
	return (i - 1);
}

/*
** ============================================================================
**	COPY_TOKENS - Copie un segment de tokens dans un nouveau tableau.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* source.
**		- @start:  indice de début de copie (inclus).
**		- @end:    indice de fin de copie (exclus).
**
**	Variables locales:
**		- slice: pointeur sur le nouveau tableau alloué.
**		- len:   nombre d’éléments à copier.
**		- i:     indice de parcours.
**
**	Processus:
**		1. Calculer len = end - start.
**		2. Allouer slice pour len + 1 pointeurs.
**		3. Copier tokens[start + i] dans slice[i] pour i < len.
**		4. Terminer slice[len] par NULL.
**
**	Retour:
**		Tableau copié ou NULL en cas d’échec d’allocation.
*/
static t_token	**copy_tokens(t_token **tokens, int start, int end)
{
	t_token	**slice;
	int		len;
	int		i;

	len = end - start;
	slice = malloc(sizeof(t_token *) * (len + 1));
	if (!slice)
		return (NULL);
	i = 0;
	while (i < len)
	{
		slice[i] = tokens[start + i];
		i++;
	}
	slice[i] = NULL;
	return (slice);
}

/*
** ============================================================================
**	EXTRACT_SUBCOMMANDS - Extrait et parse les sous-commandes entre ().
** ============================================================================
**	Parametres:
**		- @prs: pointeur vers t_parser (tokens et position actuels).
**
**	Variables locales:
**		- start:     indice juste après '('.
**		- close_idx: index de la parenthèse fermante trouvée.
**		- sub_tokens: copie des tokens entre start et close_idx.
**		- subs:      tableau de t_command* résultant de parser().
**
**	Processus:
**		1. Définir start = prs->current + 1.
**		2. close_idx = find_closing(prs->tokens, start).
**		3. Si close_idx < 0, erreur de parenthèses.
**		4. sub_tokens = copy_tokens(prs->tokens, start, close_idx).
**		5. subs = parser(sub_tokens); libérer sub_tokens.
**		6. Mettre prs->current = close_idx + 1.
**
**	Retour:
**		Tableau de sous-commandes ou NULL en cas d’erreur.
*/
static t_command	**extract_subcommands(t_parser *prs)
{
	int			start;
	int			close_idx;
	t_token		**sub_tokens;
	t_command	**subs;

	start = prs->current + 1;
	close_idx = find_closing(prs->tokens, start);
	if (close_idx < 0)
		return (dis_paren_mismatch_err(), NULL);
	sub_tokens = copy_tokens(prs->tokens, start, close_idx);
	if (!sub_tokens)
		return (NULL);
	subs = parser(sub_tokens);
	free(sub_tokens);
	if (!subs)
		return (NULL);
	prs->current = close_idx + 1;
	return (subs);
}

/*
** ============================================================================
**	PARSE_GROUP - Parse une suite de tokens entre parenthèses.
** ============================================================================
**	Parametres:
**		- @prs: pointeur vers t_parser (tokens et position).
**
**	Variables locales:
**		- subs: Sous-commandes extraites.
**		- cmd:  nouvelle commande subshell allouée.
**
**	Processus:
**		1. subs = extract_subcommands(prs).
**		2. cmd = init_command().
**		3. cmd->sub_commands = subs; cmd->is_subshell = 1.
**		4. parse_redirections(cmd, prs), gérer erreur si besoin.
**
**	Retour:
**		Pointeur sur t_command subshell ou NULL en cas d’erreur.
*/
static t_command	*parse_group(t_parser *prs)
{
	t_command	**subs;
	t_command	*cmd;

	subs = extract_subcommands(prs);
	if (subs == NULL)
		return (NULL);
	cmd = init_command();
	if (cmd == NULL)
	{
		free_command_list(subs);
		return (NULL);
	}
	cmd->sub_commands = subs;
	cmd->is_subshell = 1;
	if (!parse_redirections(cmd, prs))
	{
		free_command_list(subs);
		free_command(cmd);
		return (NULL);
	}
	return (cmd);
}

/*
** ============================================================================
**	PARSE_GROUP_OR_COMMAND - Choisit entre groupe ou commande simple.
** ============================================================================
**	Parametres:
**		- @prs: pointeur vers t_parser contenant tokens et position.
**
**	Processus:
**		1. Lire tok = prs->tokens[prs->current].
**		2. Si tok est OP_LPAR, appel à parse_group().
**		3. Sinon, appel à parse_command().
**
**	Retour:
**		Pointeur sur t_command parsée ou NULL en cas d’erreur.
*/
t_command	*parse_group_or_command(t_parser *prs)
{
	t_token	*tok;

	tok = prs->tokens[prs->current];
	if (tok->type == T_OPERATOR && tok->ope == OP_LPAR)
		return (parse_group(prs));
	return (parse_command(prs));
}
