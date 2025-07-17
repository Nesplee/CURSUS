/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:35:20 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:48:21 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		HANDLE_REDIR_OP - Gère les redirections et opérateurs
** ============================================================================
**	Parametres:
**		- @lexer: structure t_lexer contenant input et position.
**		- @pos:   index de départ du token.
**		- @len:   pointeur vers la longueur du token à calculer.
**		- @c:     caractère à analyser (<, >, |, &).
**
**	Processus:
**		1. Si c est une redirection (< ou >) :
**		   a. Si redirection double (<<, >>), *len = 2.
**		   b. Vérifier syntaxe redir via check_redirs_syntax().
**		2. Sinon si c est un opérateur (& ou |) :
**		   a. Si opérateur double (&&, ||), *len = 2.
**		   b. Vérifier syntaxe oper via check_operators_syntax().
**		3. Sinon retourner -1 (non pris en charge).
**
**	Retour:
**		Code de retour de la vérification ou -1 si pas concerné.
*/
static int	handle_redir_op(t_lexer *lexer, int pos, int *len, char c)
{
	if (ft_isreddir(c))
	{
		if ((lexer->input[pos + 1]) == c)
			*len = 2;
		return (check_redirs_syntax(lexer));
	}
	if (ft_isoperator(c))
	{
		if ((c == '&' && lexer->input[pos + 1] == '&')
			|| (c == '|' && lexer->input[pos + 1] == '|'))
			*len = 2;
		return (check_operators_syntax(lexer));
	}
	return (-1);
}

/*
** ============================================================================
**		HANDLE_QUOTE_PAREN - Gère quotes et parenthèses
** ============================================================================
**	Parametres:
**		- @lexer: structure t_lexer contenant input et position.
**		- @pos:   index de la quote ouvrante.
**		- @len:   pointeur vers la longueur du token à calculer.
**		- @c:     caractère de quote (' ou "').
**
**	Processus:
**		1. Si c est une quote :
**		   a. Parcourir jusqu'à la quote fermante.
**		   b. Si trouvée, *len = distance + 1.
**		2. Vérifier syntaxe quote via check_quotes_syntax().
**		3. Sinon retourner -1.
**
**	Retour:
**		Code de retour de la vérification ou -1 si pas concerné.
*/
static int	handle_quote_paren(t_lexer *lexer, int pos, int *len, char c)
{
	int	i;

	if (ft_isquote(c))
	{
		i = pos + 1;
		while (lexer->input[i] && lexer->input[i] != c)
			i++;
		if (lexer->input[i] == c)
			*len = i - pos + 1;
		return (check_quotes_syntax(lexer));
	}
	return (-1);
}

/*
** ============================================================================
**		HANDLE_VAR - Gère les variables
** ============================================================================
**	Parametres:
**		- @lexer: structure t_lexer contenant input et position.
**		- @pos:   index du '$'.
**		- @len:   pointeur vers la longueur du token à calculer.
**		- @c:     caractère courant.
**
**	Processus:
**		1. Si c == '$' :
**		   a. Si variable spéciale '?', *len = 2.
**		   b. Sinon parcourir alnum et '_' pour calculer *len.
**		   c. Vérifier syntaxe var via check_var_syntax().
**		2. Sinon retourner SUCCESS.
**
**	Retour:
**		SUCCESS ou code d'erreur de check_var_syntax().
*/
static int	handle_var(t_lexer *lexer, int pos, int *len, char c)
{
	int		i;
	char	next;

	if (c == '$')
	{
		next = lexer->input[pos + 1];
		if (next == '\0' || (!ft_isalnum((unsigned char)next)
				&& next != '_' && next != '?'))
			return (SUCCESS);
		if (next == '?')
		{
			*len = 2;
			return (SUCCESS);
		}
		i = pos + 1;
		while (lexer->input[i] && (ft_isalnum(lexer->input[i])
				|| lexer->input[i] == '_'))
			i++;
		*len = i - pos;
		return (check_var_syntax(lexer));
	}
	return (SUCCESS);
}

/*
** ============================================================================
**		HANDLE_SYNTAX_AT - Point d'entrée de vérification syntaxique
** ============================================================================
**	Parametres:
**		- @lexer: structure t_lexer contenant input et position.
**		- @pos:   index du caractère à vérifier.
**		- @len:   pointeur vers la longueur du token à calculer.
**
**	Processus:
**		1. Initialiser *len = 1.
**		2. Positionner lexer->position = pos.
**		3. Si parenthèse, appeler check_parentheses_syntax().
**		4. Essayer handle_redir_op(), handle_quote_paren(), handle_var().
**
**	Retour:
**		Code de retour de la vérification.
*/
static int	handle_syntax_at(t_lexer *lexer, int pos, int *len)
{
	char	c;
	int		status;

	*len = 1;
	lexer->position = pos;
	c = lexer->input[pos];
	if (c == '(' || c == ')')
		return (check_parentheses_syntax(lexer));
	status = handle_redir_op(lexer, pos, len, c);
	if (status >= 0)
		return (status);
	status = handle_quote_paren(lexer, pos, len, c);
	if (status >= 0)
		return (status);
	return (handle_var(lexer, pos, len, c));
}

/*
** ============================================================================
**		CHECK_SYNTAX - Fonction principale de vérification
** ============================================================================
**	Parametres:
**		- @lexer: structure t_lexer contenant input et position.
**
**	Processus:
**		1. Parcourir lexer->input tant que non nul.
**		2. Appeler handle_syntax_at() à chaque pos.
**		3. En cas d'erreur, retourner le code.
**
**	Retour:
**		SUCCESS si toute la syntaxe est valide, sinon code d'erreur.
*/
int	check_syntax(t_lexer *lexer)
{
	int		pos;
	int		status;
	int		len;

	pos = 0;
	while (lexer->input[pos])
	{
		status = handle_syntax_at(lexer, pos, &len);
		if (status != SUCCESS)
			return (status);
		pos += len;
	}
	return (SUCCESS);
}
