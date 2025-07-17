/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_operators.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:25:26 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:02:55 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		CHECK_OPERATOR_START - Vérifie qu'un opérateur est précédé valide.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos: position du premier caractère de l'opérateur.
**
**	Variables locales:
**		cur: caractère de l'opérateur ('&' ou '|').
**		len: longueur de l'opérateur (1 ou 2).
**
**	Processus:
**		1. Déterminer len selon cur et le caractère suivant (&&, || ou simple).
**		2. Si pos == 0, syntaxe invalide en début de ligne.
**		3. Avancer pos de len, puis ignorer les espaces.
**		4. Si fin de chaîne, syntaxe invalide.
**
**	Retour:
**		SUCCESS si opérateur précédé correctement, ERR_SYNTAX sinon.
*/
static int	check_operator_start(t_lexer *lexer, int pos)
{
	char	cur;
	int		len;

	cur = lexer->input[pos];
	if ((cur == '&' && lexer->input[pos + 1] == '&')
		|| (cur == '|' && lexer->input[pos + 1] == '|'))
		len = 2;
	else
		len = 1;
	if (pos == 0)
		return (ERR_SYNTAX);
	pos += len;
	while (lexer->input[pos] && ft_isspace(lexer->input[pos]))
		pos++;
	if (lexer->input[pos] == '\0')
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_SPECIAL_AFTER - Vérifie caractère après un opérateur.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos: position du premier caractère de l'opérateur.
**
**	Variables locales:
**		next: caractère situé juste après l'opérateur.
**
**	Processus:
**		1. Lire next = input[pos + 1].
**		2. Si next est ';', ')' ou '<' ou '>', syntaxe invalide.
**
**	Retour:
**		SUCCESS si caractère valide, ERR_SYNTAX sinon.
*/
static int	check_special_after(t_lexer *lexer, int pos)
{
	char	next;

	next = lexer->input[pos + 1];
	if (next == ';' || next == ')' || next == '>' || next == '<')
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_CMD_AFTER - Vérifie qu'une commande suit un opérateur.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**		- @pos: position du premier caractère de l'opérateur.
**
**	Variables locales:
**		i: indice pour parcourir après l'opérateur.
**
**	Processus:
**		1. Mettre i = pos + 1, puis ignorer les espaces.
**		2. Si fin de chaîne, syntaxe invalide.
**		3. Si caractère est un opérateur (sauf '('), syntaxe invalide.
**
**	Retour:
**		SUCCESS si une commande suit, ERR_SYNTAX sinon.
*/
static int	check_cmd_after(t_lexer *lexer, int pos)
{
	int	i;

	i = pos + 1;
	while (lexer->input[i] == ' ')
		i++;
	if (lexer->input[i] == '\0')
		return (ERR_SYNTAX);
	if (ft_isoperator(lexer->input[i]) && lexer->input[i] != '(')
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_OPERATOR_SEQUENCE - Vérifie séquence complète d'opérateurs.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**
**	Variables locales:
**		pos: position de l'opérateur.
**		cur: caractère actuel.
**		next: caractère suivant.
**
**	Processus:
**		1. Vérifier position initiale via check_operator_start().
**		2. Si opérateur double (&& ou ||), incrémenter pos.
**		3. Refuser séquences mixtes (&| ou |&).
**		4. Vérifier caractère après via check_special_after().
**		5. Vérifier commande suivante via check_cmd_after().
**
**	Retour:
**		SUCCESS si séquence valide, ERR_SYNTAX sinon.
*/
static int	check_operator_sequence(t_lexer *lexer)
{
	int		pos;
	char	cur;
	char	next;

	pos = lexer->position;
	cur = lexer->input[pos];
	next = lexer->input[pos + 1];
	if (check_operator_start(lexer, pos) != SUCCESS)
		return (ERR_SYNTAX);
	if ((cur == '&' && next == '&') || (cur == '|' && next == '|'))
		pos++;
	else if ((cur == '|' && next == '&') || (cur == '&' && next == '|'))
		return (ERR_SYNTAX);
	if (check_special_after(lexer, pos) != SUCCESS)
		return (ERR_SYNTAX);
	if (check_cmd_after(lexer, pos + 1) != SUCCESS)
		return (ERR_SYNTAX);
	return (SUCCESS);
}

/*
** ============================================================================
**		CHECK_OPERATORS_SYNTAX - Validation syntaxe des opérateurs.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur vers t_lexer contenant l'input.
**
**	Variables locales:
**		status: code de retour de check_operator_sequence().
**
**	Processus:
**		1. Vérifier lexer et input non-NULL.
**		2. Appeler check_operator_sequence() à position courante.
**		3. En cas d'erreur, appeler print_lexer_error().
**
**	Retour:
**		SUCCESS si syntaxe valide, ERR_SYNTAX sinon.
*/
int	check_operators_syntax(t_lexer *lexer)
{
	int	status;

	if (!lexer || !lexer->input)
		return (ERR_SYNTAX);
	status = check_operator_sequence(lexer);
	if (status != SUCCESS)
		print_lexer_error(status, lexer->input + lexer->position);
	return (status);
}
