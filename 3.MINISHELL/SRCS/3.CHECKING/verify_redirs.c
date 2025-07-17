/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:03:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:09:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CHECK_SPECIAL_CHARS - Vérifie les caractères spéciaux après redir.
** ============================================================================
**	Parametres:
**		- @c: caractère à vérifier.
**
**	Processus:
**		1. Tester si c est l’un des suivants :
**		   '|', ';', '&', '(', ')', '\n'.
**
**	Retour:
**		1 si caractère spécial, 0 sinon.
*/
static int	check_special_chars(char c)
{
	return (c == '|' || c == ';' || c == '&'
		|| c == '(' || c == ')' || c == '\n');
}

/*
** ============================================================================
**		CHECK_TRIPLE_REDIR - Interdit trois redirections consécutives.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer.
**		- @pos:   index de la redirection dans input.
**
**	Processus:
**		1. Si '<<<' ou '>>>', erreur.
**		2. Vérifier que le caractère suivant n’est pas spécial.
**
**	Retour:
**		SUCCESS si valide, ERR_SYNTAX sinon.
*/
static int	check_triple_redir(t_lexer *lexer, int pos)
{
	if (lexer->input[pos] == '<')
	{
		if (lexer->input[pos + 1] == '<' && lexer->input[pos + 2] == '<')
			return (ERR_SYNTAX);
	}
	else if (lexer->input[pos] == '>')
	{
		if (lexer->input[pos + 1] == '>' && lexer->input[pos + 2] == '>')
			return (ERR_SYNTAX);
	}
	if (check_special_chars(lexer->input[pos + 1]))
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_REDIR_FILE - Vérifie le nom de fichier après redirection.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer.
**		- @pos:   index juste après l’opérateur.
**
**	Processus:
**		1. Ignorer tous les espaces depuis pos.
**		2. Si fin de chaîne, erreur.
**		3. Si nouveau redir ou caractère spécial, erreur.
**
**	Retour:
**		SUCCESS si valide, ERR_SYNTAX sinon.
*/
static int	check_redir_file(t_lexer *lexer, int pos)
{
	while (lexer->input[pos] && ft_isspace(lexer->input[pos]))
		pos++;
	if (!lexer->input[pos])
		return (ERR_SYNTAX);
	if (ft_isreddir(lexer->input[pos]))
		return (ERR_SYNTAX);
	if (check_special_chars(lexer->input[pos]))
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_REDIR_SEQUENCE - Vérifie une séquence complète de redirs.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer.
**
**	Processus:
**		1. Si pos>0 et précédent est redir, erreur.
**		2. Appeler check_triple_redir() sur pos.
**		3. Gérer cas '<>', '<<', '>>', '<', '>'.
**		4. Vérifier fichier via check_redir_file(pos+1).
**
**	Retour:
**		SUCCESS si valide, ERR_SYNTAX sinon.
*/
static int	check_redir_sequence(t_lexer *lexer)
{
	int	pos;

	pos = lexer->position;
	if (pos > 0 && ft_isreddir(lexer->input[pos - 1]))
		return (ERR_SYNTAX);
	if (check_triple_redir(lexer, pos) != SUCCESS)
		return (ERR_SYNTAX);
	if (lexer->input[pos] == '<')
	{
		if (lexer->input[pos + 1] == '>')
			return (ERR_SYNTAX);
		if (lexer->input[pos + 1] == '<')
			pos++;
	}
	else if (lexer->input[pos] == '>')
	{
		if (lexer->input[pos + 1] == '<')
			return (ERR_SYNTAX);
		if (lexer->input[pos + 1] == '>')
			pos++;
	}
	return (check_redir_file(lexer, pos + 1));
}

/*
** ============================================================================
**		CHECK_REDIRS_SYNTAX - Entrée principale vérif. syntaxe redirections.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l’input.
**
**	Processus:
**		1. Vérifier lexer et input non NULL.
**		2. Appeler check_redir_sequence().
**		3. Si erreur, appeler print_lexer_error().
**
**	Retour:
**		SUCCESS si syntaxe correcte, ERR_SYNTAX sinon.
*/
int	check_redirs_syntax(t_lexer *lexer)
{
	int	status;

	if (!lexer || !lexer->input)
		return (ERR_SYNTAX);
	status = check_redir_sequence(lexer);
	if (status != SUCCESS)
		print_lexer_error(ERR_SYNTAX, lexer->input + lexer->position);
	return (status);
}
