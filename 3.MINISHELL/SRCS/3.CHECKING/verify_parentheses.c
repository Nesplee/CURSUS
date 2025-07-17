/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_parentheses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:38:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:19:56 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CHECK_EMPTY_PARENTHESES - Vérifie si les parenthèses sont vides.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:   index de la parenthèse ouvrante +1.
**
**	Variables locales:
**		- (aucune)
**
**	Processus:
**		1. Ignorer tous les espaces à partir de pos.
**		2. Si le caractère courant est ')', retourner ERR_PAREN_EMPTY.
**
**	Retour:
**		ERR_PAREN_EMPTY si vide, SUCCESS sinon.
*/
static int	check_empty_parentheses(t_lexer *lexer, int pos)
{
	while (lexer->input[pos] && ft_isspace(lexer->input[pos]))
		pos++;
	if (lexer->input[pos] == ')')
		return (ERR_PAREN_EMPTY);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_PARENTHESES_CONTENT - Vérifie le contenu entre parenthèses.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:   index de la parenthèse ouvrante.
**
**	Variables locales:
**		- saved_pos: position d'origine du lexer.
**		- status:    code de retour des vérifications internes.
**
**	Processus:
**		1. Si input[pos] == ')', retourner SUCCESS.
**		2. Sauvegarder lexer->position dans saved_pos.
**		3. Positionner lexer->position à pos+1.
**		4. Selon input[pos] :
**		   - redirection : appeler check_redirs_syntax().
**		   - opérateur   : appeler check_operators_syntax().
**		   - sinon       : appeler check_empty_parentheses().
**		5. Restaurer lexer->position à saved_pos.
**
**	Retour:
**		ERR_SYNTAX si erreur, SUCCESS sinon.
*/
static int	check_parentheses_content(t_lexer *lexer, int pos)
{
	int	saved_pos;
	int	status;

	if (lexer->input[pos] == ')')
		return (SUCCESS);
	pos++;
	saved_pos = lexer->position;
	lexer->position = pos;
	if (ft_isreddir(lexer->input[pos]))
		status = check_redirs_syntax(lexer);
	else if (ft_isoperator(lexer->input[pos]))
		status = check_operators_syntax(lexer);
	else
		status = check_empty_parentheses(lexer, pos);
	lexer->position = saved_pos;
	return (status);
}

/*
** ============================================================================
**		CHECK_PARENTHESES_SEQUENCE - Vérifie équilibre global.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**
**	Variables locales:
**		- pos:   index courant dans la chaîne.
**		- count: compteur de parenthèses ouvrantes moins fermantes.
**
**	Processus:
**		1. Si input[0] == ')', retourner ERR_PAREN_MISMATCH.
**		2. Parcourir input :
**		   - '(' : count++
**		   - ')' : count--
**		   - si count < 0, retour ERR_PAREN_MISMATCH.
**		3. Après boucle, si count != 0, ERR_PAREN_MISMATCH.
**
**	Retour:
**		ERR_PAREN_MISMATCH si déséquilibre, SUCCESS sinon.
*/
static int	check_parentheses_sequence(t_lexer *lexer)
{
	int	pos;
	int	count;

	if (lexer->input[0] == ')')
		return (ERR_PAREN_MISMATCH);
	pos = 0;
	count = 0;
	while (lexer->input[pos])
	{
		if (lexer->input[pos] == '(')
			count++;
		else if (lexer->input[pos] == ')')
			count--;
		if (count < 0)
			return (ERR_PAREN_MISMATCH);
		pos++;
	}
	if (count != 0)
		return (ERR_PAREN_MISMATCH);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_SURROUNDING_CHARS - Vérifie caractères autour des ().
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos:   index de la parenthèse à vérifier.
**
**	Variables locales:
**		- (aucune)
**
**	Processus:
**		1. Si input[pos] == '(' et pos>0, vérifier preceding char
**		2. Si input[pos] == ')' et char suivant non nul, vérifier succeeding
**		3. Accepter uniquement espaces ou opérateurs.
**
**	Retour:
**		ERR_SYNTAX si caractère invalide, SUCCESS sinon.
*/
static int	check_surrounding_chars(t_lexer *lexer, int pos)
{
	if (lexer->input[pos] == '(' && pos > 0)
	{
		if (!ft_isspace(lexer->input[pos - 1])
			&& !ft_isoperator(lexer->input[pos - 1]))
			return (ERR_SYNTAX);
	}
	if (lexer->input[pos] == ')' && lexer->input[pos + 1])
	{
		if (!ft_isspace(lexer->input[pos + 1])
			&& !ft_isoperator(lexer->input[pos + 1]))
			return (ERR_SYNTAX);
	}
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_PARENTHESES_SYNTAX - Entrée principale pour vérification.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**
**	Variables locales:
**		- status: code de retour des vérifications.
**
**	Processus:
**		1. Vérifier lexer et input non-NULL.
**		2. Appeler check_parentheses_sequence().
**		3. Si erreur, print_lexer_error() et retour.
**		4. Si char courant == ')', SUCCESS.
**		5. Sinon, check_parentheses_content() puis check_surrounding_chars().
**		6. En cas d'erreur, print_lexer_error().
**
**	Retour:
**		SUCCESS si valide, code d'erreur sinon.
*/
int	check_parentheses_syntax(t_lexer *lexer)
{
	int	status;

	if (!lexer || !lexer->input)
		return (ERR_SYNTAX);
	status = check_parentheses_sequence(lexer);
	if (status != SUCCESS)
	{
		print_lexer_error(status, ")");
		return (status);
	}
	if (lexer->input[lexer->position] == ')')
		return (SUCCESS);
	status = check_parentheses_content(lexer, lexer->position);
	if (status == SUCCESS)
		status = check_surrounding_chars(lexer, lexer->position);
	if (status != SUCCESS)
		print_lexer_error(status, lexer->input + lexer->position);
	return (status);
}
