/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:48:48 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:47:58 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CHECK_VAR_NAME - Vérifie la validité du nom d'une variable.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    position du caractère suivant le '$'.
**
**	Variables locales:
**		(aucune)
**
**	Processus:
**		1. Si input[pos] est '?' ou '$', retourne SUCCESS.
**		2. Si fin de chaîne, retourne ERR_VAR_SYNTAX.
**		3. Si premier caractère est un chiffre, ERR_VAR_SYNTAX.
**		4. Si caractère non lettre, chiffre ou '_', ERR_VAR_SYNTAX.
**
**	Retour:
**		SUCCESS si le nom est valide, ERR_VAR_SYNTAX sinon.
*/
static int	check_var_name(t_lexer *lexer, int pos)
{
	char	c;

	c = lexer->input[pos];
	if (c == '?' || c == '$')
		return (SUCCESS);
	if (!c)
		return (ERR_VAR_SYNTAX);
	if (!ft_isalpha((unsigned char)c) && c != '_'
		&& !ft_isdigit((unsigned char)c))
		return (ERR_VAR_SYNTAX);
	return (SUCCESS);
}
/*
** ============================================================================
**		CHECK_VAR_SEQUENCE - Parcourt l'input pour vérifier les variables.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    position de départ dans l'input.
**
**	Variables locales:
**		- status: code de retour de check_var_name().
**
**	Processus:
**		1. Parcourir la chaîne depuis pos.
**		2. À chaque '$', appeler check_var_name() sur pos+1.
**		3. Si erreur, retourner immédiatement le code.
**
**	Retour:
**		SUCCESS si toutes les variables sont valides, ERR_VAR_SYNTAX sinon.
*/

static int	check_var_sequence(t_lexer *lexer, int pos)
{
	int	status;

	while (lexer->input[pos])
	{
		if (lexer->input[pos] == '$')
		{
			status = check_var_name(lexer, pos + 1);
			if (status != SUCCESS)
				return (status);
		}
		pos++;
	}
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_QUOTE_CONTENT - Vérifie variables dans les quotes.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    position après la quote ouvrante.
**		- @quote:  caractère de la quote ('\'' ou '\"').
**
**	Variables locales:
**		(aucune)
**
**	Processus:
**		1. Parcourir jusqu'à la quote fermante.
**		2. Si quote double, à chaque '$' appeler check_var_name().
**		3. Si fin de chaîne avant la fermante, ERR_QUOTE_UNCLOSED.
**
**	Retour:
**		SUCCESS si la quote est fermée, code d'erreur sinon.
*/
static int	check_quote_content(t_lexer *lexer, int pos, char quote)
{
	while (lexer->input[pos] && lexer->input[pos] != quote)
	{
		if (lexer->input[pos] == '$' && quote == '"')
			if (check_var_name(lexer, pos + 1) != SUCCESS)
				return (ERR_VAR_SYNTAX);
		pos++;
	}
	if (!lexer->input[pos])
		return (ERR_QUOTE_UNCLOSED);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_VAR_QUOTES - Gère variables dans et hors des quotes.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    position actuelle dans l'input.
**
**	Variables locales:
**		- quote: caractère détecté s'il s'agit d'une quote.
**
**	Processus:
**		1. Si input[pos] est quote, appeler check_quote_content().
**		2. Sinon, appeler check_var_sequence() depuis pos.
**
**	Retour:
**		Code de retour de la fonction appelée.
*/
static int	check_var_quotes(t_lexer *lexer, int pos)
{
	char	quote;

	if (ft_isquote(lexer->input[pos]))
	{
		quote = lexer->input[pos];
		return (check_quote_content(lexer, pos + 1, quote));
	}
	return (check_var_sequence(lexer, pos));
}

/*
** ============================================================================
**		CHECK_VAR_SYNTAX - Point d'entrée vérification syntaxe variables.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input et position.
**
**	Processus:
**		1. Vérifier lexer et input non-NULL.
**		2. Appeler check_var_quotes() depuis lexer->position.
**		3. En cas d'erreur, afficher via print_lexer_error().
**
**	Retour:
**		SUCCESS si syntaxe correcte, code d'erreur sinon.
*/
int	check_var_syntax(t_lexer *lexer)
{
	int	status;

	if (!lexer || !lexer->input)
		return (ERR_SYNTAX);
	status = check_var_quotes(lexer, lexer->position);
	if (status != SUCCESS)
		print_lexer_error(status, lexer->input + lexer->position);
	return (status);
}
