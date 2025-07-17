/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:54:52 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 19:24:35 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	COUNT_PIPES - Compte les pipes hors parenthèses.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* issu du lexer.
**
**	Processus:
**		1. Initialiser count = 0, depth = 0.
**		2. Parcourir tokens[i] tant que non NULL :
**		   a. '('     -> depth++.
**		   b. ')'     -> depth--.
**		   c. '|' et depth == 0 -> count++.
**
**	Retour:
**		Nombre de pipes extérieurs aux groupes.
*/
static int	count_pipes(t_token **tokens)
{
	int	i;
	int	count;
	int	depth;

	i = 0;
	count = 0;
	depth = 0;
	while (tokens[i])
	{
		if (tokens[i]->type == T_OPERATOR)
		{
			if (tokens[i]->ope == OP_LPAR)
				depth++;
			else if (tokens[i]->ope == OP_RPAR)
				depth--;
			else if (tokens[i]->ope == OP_PIPE && depth == 0)
				count++;
		}
		i++;
	}
	return (count);
}

/*
** ============================================================================
**	INIT_PIPE - Crée un pipe entre deux commandes.
** ============================================================================
**	Parametres:
**		- @cmd1: commande émettrice du pipe.
**		- @cmd2: commande réceptrice du pipe.
**
**	Processus:
**		1. Appeler pipe() sur cmd1->pipe_fd.
**		2. Si succès, copier les descripteurs dans cmd2->pipe_fd.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	init_pipe(t_command *cmd1, t_command *cmd2)
{
	if (pipe(cmd1->pipe_fd) == -1)
		return (0);
	cmd2->pipe_fd[0] = cmd1->pipe_fd[0];
	cmd2->pipe_fd[1] = cmd1->pipe_fd[1];
	return (1);
}

/*
** ============================================================================
**	PARSE_PIPED_COMMAND - Extrait une commande suivie d’un pipe optionnel.
** ============================================================================
**	Parametres:
**		- @parser: pointeur vers t_parser contenant tokens et position.
**
**	Processus:
**		1. Appeler parse_group_or_command() pour obtenir la commande.
**		2. Si le token courant est un pipe, incrémenter parser->current.
**
**	Retour:
**		Pointeur sur t_command ou NULL en cas d’erreur.
*/
static t_command	*parse_piped_command(t_parser *parser)
{
	t_command	*cmd;

	cmd = parse_group_or_command(parser);
	if (!cmd)
		return (NULL);
	if (parser->tokens[parser->current]
		&& parser->tokens[parser->current]->type == T_OPERATOR
		&& parser->tokens[parser->current]->ope == OP_PIPE)
		parser->current++;
	return (cmd);
}

/*
** ============================================================================
**	PARSE_PIPES - Point d’entrée pour le parsing des commandes en pipeline.
** ============================================================================
**	Parametres:
**		- @parser: pointeur vers t_parser contenant tokens et position.
**
**	Processus:
**		1. Compter les pipes hors parenthèses via count_pipes().
**		2. Définir parser->cmd_count = pipe_count + 1.
**		3. Allouer parser->commands pour cmd_count + 1 pointeurs.
**		4. Remplir parser->commands[i] avec parse_piped_command().
**		5. Terminer parser->commands par NULL.
**		6. Initialiser un pipe entre chaque paire de commandes adjacentes.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	parse_pipes(t_parser *parser)
{
	int			i;
	int			pipe_count;

	pipe_count = count_pipes(parser->tokens);
	parser->cmd_count = pipe_count + 1;
	parser->commands = malloc(sizeof(t_command *) * (parser->cmd_count + 1));
	if (!parser->commands)
		return (0);
	i = 0;
	while (i < parser->cmd_count)
	{
		parser->commands[i] = parse_piped_command(parser);
		if (!parser->commands[i])
			return (0);
		i++;
	}
	parser->commands[i] = NULL;
	i = 0;
	while (i < parser->cmd_count - 1)
	{
		if (!init_pipe(parser->commands[i], parser->commands[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
