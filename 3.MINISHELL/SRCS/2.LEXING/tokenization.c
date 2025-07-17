/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:34:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 18:58:25 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		INIT_TOKENIZATION - Prépare le lexer pour la tokenisation.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**		- @input: chaîne d’entrée à analyser.
**
**	Variables locales:
**		malloc_size - taille à allouer pour tokens.
**		copy        - copie de input via ft_strdup().
**
**	Processus:
**		1. Vérifier lexer et input non-NULL.
**		2. Allouer lexer->tokens pour (len(input) + 1) pointeurs.
**		3. ft_memset() à 0.
**		4. Initialiser position et token_count.
**		5. Dupliquer input, libérer l’ancienne si existante.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	init_tokenization(t_lexer *lexer, char *input)
{
	size_t	malloc_size;
	char	*copy;

	if (!lexer || !input)
		return (0);
	malloc_size = sizeof(t_token *) * (ft_strlen(input) + 1);
	lexer->tokens = malloc(malloc_size);
	if (!lexer->tokens)
		return (0);
	ft_memset(lexer->tokens, 0, malloc_size);
	lexer->position = 0;
	lexer->token_count = 0;
	copy = ft_strdup(input);
	if (!copy)
		return (0);
	if (lexer->input)
		free(lexer->input);
	lexer->input = copy;
	return (1);
}

/*
** ============================================================================
**		PROCESS_TOKENS - Traite le prochain token.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**
**	Processus:
**		1. Sauter espaces (ft_skip_spaces).
**		2. Tester redirection (< >), opérateur, variable, quote, mot.
**		3. Appeler le handler correspondant.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	process_tokens(t_lexer *lexer)
{
	if (!lexer || !lexer->input)
		return (0);
	if (ft_isspace(lexer->input[lexer->position]))
	{
		ft_skip_spaces(lexer);
		return (1);
	}
	else if (ft_isreddir(lexer->input[lexer->position]))
		return (handle_redirection(lexer));
	else if (ft_isoperator(lexer->input[lexer->position]))
		return (handle_operator(lexer));
	else if (ft_isvariable(lexer->input[lexer->position]))
		return (handle_variable(lexer));
	else if (ft_isquote(lexer->input[lexer->position]))
		return (handle_quote(lexer));
	return (handle_word(lexer));
}

/*
** ============================================================================
**		PROCESS_LEXER - Extrait tous les tokens de l’entrée.
** ============================================================================
**	Parametres:
**		- @lexer: pointeur sur t_lexer.
**
**	Processus:
**		1. Boucler tant que input[pos] != '\0'.
**		2. Appeler process_tokens().
**		3. En cas d’erreur, free_lexer() et retourner NULL.
**		4. Terminer tokens[token_count] par NULL et détacher lexer->tokens.
**
**	Retour:
**		Tableau de t_token* ou NULL si erreur.
*/
static t_token	**process_lexer(t_lexer *lexer)
{
	t_token	**tokens;

	while (lexer->input[lexer->position])
	{
		if (!process_tokens(lexer))
		{
			free_lexer(lexer);
			return (NULL);
		}
	}
	tokens = lexer->tokens;
	lexer->tokens[lexer->token_count] = NULL;
	lexer->tokens = NULL;
	return (tokens);
}

/*
** ============================================================================
**		TOKENIZE - Point d’entrée principal du lexer.
** ============================================================================
**	Parametres:
**		- @input: chaîne à analyser.
**
**	Processus:
**		1. init_lexer() puis init_tokenization().
**		2. check_syntax(), free_lexer() si erreur.
**		3. process_lexer() pour obtenir tokens.
**		4. free_lexer() et retourner tokens.
**
**	Retour:
**		Tableau de t_token* ou NULL.
*/
t_token	**tokenize(char *input)
{
	t_lexer	*lexer;
	t_token	**tokens;
	int		status;

	lexer = init_lexer(input);
	if (!lexer || !init_tokenization(lexer, input))
	{
		if (lexer)
			free_lexer(lexer);
		return (NULL);
	}
	status = check_syntax(lexer);
	if (status != SUCCESS)
	{
		free_lexer(lexer);
		return (NULL);
	}
	lexer->position = 0;
	tokens = process_lexer(lexer);
	lexer->tokens = NULL;
	free_lexer(lexer);
	return (tokens);
}
