/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:35:13 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:43:53 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CHECK_VAR_IN_QUOTES - Vérifie variable dans quotes doubles.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:   index courant dans la chaîne.
**
**	Processus:
**		1. Si input[pos] == '$', tenter check_var_syntax().
**		2. En cas d'erreur, renvoyer ERR_VAR_SYNTAX.
**
**	Retour:
**		SUCCESS ou ERR_VAR_SYNTAX.
*/
static int	check_var_in_quotes(t_lexer *lexer, int pos)
{
	char	next;

	if (lexer->input[pos] == '$')
	{
		next = lexer->input[pos + 1];
		if (next == '\0'
			|| (!ft_isalnum((unsigned char)next) && next != '_'
				&& next != '?'))
			return (SUCCESS);
		if (check_var_syntax(lexer) != SUCCESS)
			return (ERR_VAR_SYNTAX);
	}
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_QUOTES_CONTENT - Analyse contenu entre quotes.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @quote: caractère ouvrant (' ou "').
**		- @pos:    pointeur vers index courant.
**
**	Processus:
**		1. Tant que input[*pos] non nul et != quote :
**		   a. Si quote == '\"', appeler check_var_in_quotes().
**		   b. Incrémenter *pos.
**		2. Si fin de chaîne avant quote fermante, ERR_QUOTE_UNCLOSED.
**
**	Retour:
**		SUCCESS ou ERR_QUOTE_UNCLOSED.
*/
static int	check_quotes_content(t_lexer *lexer, char quote, int *pos)
{
	int	status;

	while (lexer->input[*pos] && lexer->input[*pos] != quote)
	{
		if (quote == '"')
		{
			status = check_var_in_quotes(lexer, *pos);
			if (status != SUCCESS)
				return (status);
		}
		(*pos)++;
	}
	if (!lexer->input[*pos])
		return (ERR_QUOTE_UNCLOSED);
	return (SUCCESS);
}

/*
** ============================================================================
**		PROCESS_QUOTE - Traite une paire de quotes.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    pointeur vers index de quote ouvrante.
**
**	Processus:
**		1. Lire quote = input[*pos], puis (*pos)++.
**		2. Appeler check_quotes_content().
**		3. Si succès, (*pos)++ pour passer quote fermante.
**
**	Retour:
**		SUCCESS ou code d'erreur.
*/
static int	process_quote(t_lexer *lexer, int *pos)
{
	char	quote;
	int		status;

	quote = lexer->input[*pos];
	(*pos)++;
	status = check_quotes_content(lexer, quote, pos);
	if (status != SUCCESS)
		return (status);
	(*pos)++;
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_SUCCESSIVE_QUOTES - Vérifie toutes les quotes.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:    index de départ dans la chaîne.
**
**	Processus:
**		1. Parcourir input[pos] jusqu'à '\0'.
**		2. À chaque quote (' ou "), appeler process_quote().
**		3. Continuer jusqu'à la fin.
**
**	Retour:
**		SUCCESS ou premier code d'erreur rencontré.
*/
static int	check_successive_quotes(t_lexer *lexer, int pos)
{
	int	status;

	while (lexer->input[pos])
	{
		if (lexer->input[pos] == '\'' || lexer->input[pos] == '"')
		{
			status = process_quote(lexer, &pos);
			if (status != SUCCESS)
				return (status);
		}
		else
			pos++;
	}
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_QUOTES_SYNTAX - Entrée principale de vérification.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**
**	Processus:
**		1. Vérifier lexer et input non NULL.
**		2. Appeler check_successive_quotes() depuis lexer->position.
**		3. En cas d'erreur, afficher via print_lexer_error().
**
**	Retour:
**		SUCCESS ou code d'erreur.
*/
int	check_quotes_syntax(t_lexer *lexer)
{
	int	status;

	if (!lexer || !lexer->input)
		return (ERR_SYNTAX);
	status = check_successive_quotes(lexer, lexer->position);
	if (status != SUCCESS)
		print_lexer_error(status, lexer->input + lexer->position);
	return (status);
}
