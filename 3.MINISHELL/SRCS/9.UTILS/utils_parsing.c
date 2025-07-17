/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:19:45 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 12:41:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	IS_BUILTIN - Vérifie si une commande correspond à un builtin.
** ============================================================================
**	Paramètres:
**		- @cmd_name: nom de la commande.
**
**	Processus:
**		1. Si cmd_name est NULL, retourne BI_NONE.
**		2. Compare cmd_name à chaque builtin connu.
**
**	Retour:
**		La valeur t_builtin_cmd correspondante ou BI_NONE.
*/
t_builtin_cmd	is_builtin(char *cmd_name)
{
	if (!cmd_name)
		return (BI_NONE);
	if (!ft_strcmp(cmd_name, "echo"))
		return (BI_ECHO);
	if (!ft_strcmp(cmd_name, "cd"))
		return (BI_CD);
	if (!ft_strcmp(cmd_name, "pwd"))
		return (BI_PWD);
	if (!ft_strcmp(cmd_name, "export"))
		return (BI_EXPORT);
	if (!ft_strcmp(cmd_name, "unset"))
		return (BI_UNSET);
	if (!ft_strcmp(cmd_name, "env"))
		return (BI_ENV);
	if (!ft_strcmp(cmd_name, "exit"))
		return (BI_EXIT);
	return (BI_NONE);
}

/*
** ============================================================================
**	COUNT_ARGS - Compte les arguments d'une commande à partir d'un indice.
** ============================================================================
**	Paramètres:
**		- @tokens: tableau de t_token*.
**		- @start:  indice de départ dans tokens[].
**
**	Processus:
**		1. Parcourt jusqu’à T_OPERATOR ou NULL.
**		2. Ignore redirections et leur cible.
**		3. Compte T_WORD et T_VAR.
**
**	Retour:
**		Nombre d'arguments.
*/
int	count_args(t_token **tokens, int start)
{
	int	count;
	int	i;

	if (!tokens)
		return (0);
	count = 0;
	i = start;
	while (tokens[i] && tokens[i]->type != T_OPERATOR)
	{
		if (tokens[i]->type == T_REDIR)
		{
			if (tokens[i + 1])
				i += 2;
			else
				break ;
			continue ;
		}
		if (tokens[i]->type == T_WORD || tokens[i]->type == T_VAR)
			count++;
		i++;
	}
	return (count);
}

/*
** ============================================================================
**	FREE_ARGS - Libère un tableau d'arguments partiel.
** ============================================================================
**	Paramètres:
**		- @args:  tableau de chaînes.
**		- @count: nombre d'éléments à libérer.
**
**	Processus:
**		1. Libère args[i] pour i < count.
**		2. free(args).
**
**	Retour:
**		(void)
*/
void	free_args(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(args[i++]);
	free(args);
}

/*
** ============================================================================
**	CLEANUP_PARSER - Nettoyage complet en cas d'échec du parsing.
** ============================================================================
**	Paramètres:
**		- @parser: pointeur vers t_parser.
**
**	Processus:
**		1. Si parser->commands existant, free_parser(parser).
**		2. Sinon, free(parser).
**
**	Retour:
**		NULL.
*/
t_command	**cleanup_parser(t_parser *parser)
{
	if (parser->commands)
		free_parser(parser);
	else
		free(parser);
	return (NULL);
}

/*
** ============================================================================
**	CLEANUP_LINE - Libère tokens, commandes, lexer et parser.
** ============================================================================
**	Paramètres:
**		- @shell:  contexte du shell.
**		- @input:  chaîne d'entrée (ignorée).
**		- @tokens: tableau de t_token*.
**		- @cmds:   tableau de t_command*.
**
**	Processus:
**		1. Si cmds, free_command_list(cmds).
**		2. Si tokens, libère chaque token et free(tokens).
**		3. Si shell->lexer, free_lexer() et shell->lexer = NULL.
**		4. Si shell->parser, free_parser() et shell->parser = NULL.
**
**	Retour:
**		(void)
*/
void	cleanup_line(t_shell *shell, char *input,
	t_token **tokens, t_command **cmds)
{
	int	i;

	(void)input;
	if (cmds)
		free_command_list(cmds);
	if (tokens)
	{
		i = 0;
		while (tokens[i])
			free_token(tokens[i++]);
		free(tokens);
	}
	if (shell->lexer)
	{
		free_lexer(shell->lexer);
		shell->lexer = NULL;
	}
	if (shell->parser)
	{
		free_parser(shell->parser);
		shell->parser = NULL;
	}
}
