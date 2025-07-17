/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:33:13 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 20:49:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	EXECUTE_COMMAND - Choisit et exécute le type de commande.
** ============================================================================
**	Parametres:
**		- @cmd:   pointeur vers t_command décrivant la commande.
**		- @shell: contexte global du shell (t_shell*).
**		- @env:   tableau d'environnement "KEY=VALUE".
**
**	Processus:
**		1. Si cmd->is_subshell, appeler execute_subshell().
**		2. Sinon si cmd->is_builtin, appeler execute_builtin_with_redir().
**		3. Sinon, exécuter une commande externe via execute_external_command().
**
**	Retour:
**		Code de retour de l’exécution (EXIT_SUCCESS ou code d’erreur).
*/
int	execute_command(t_command *cmd, t_shell *shell, char **env)
{
	if (cmd->is_subshell)
		return (execute_subshell(cmd, shell, env));
	if (cmd->is_builtin)
		return (execute_builtin_with_redir(cmd, shell, env));
	return (execute_external_command(cmd, env));
}

/*
** ============================================================================
**	EXECUTE_PARSED_LINE - Traite et exécute une ligne déjà tokenisée.
** ============================================================================
**	Parametres:
**		- @shell: contexte global du shell.
**		- @tokens: tableau de t_token* issu du parser.
**		- @line:  chaîne originale de la ligne lue.
**
**	Processus:
**		1. Appliquer expand_all() pour variables et retours.
**		2. Appliquer expand_wildcards() sur les tokens.
**		3. Initialiser parser et générer cmds via parser().
**		4. En cas d’erreur, nettoyer et retourner 1.
**		5. Exécuter la liste de commandes avec execute_commands().
**		6. Nettoyer ressources (tokens, cmds, parser) et libérer line.
**
**	Retour:
**		Code de retour final de l’exécution des commandes.
*/
static int	execute_parsed_line(t_shell *shell, t_token **tokens, char *line)
{
	t_command	**cmds;
	int			status;

	if (!expand_all(tokens, shell->env, shell->exit_status))
		return (cleanup_line(shell, NULL, tokens, NULL), free(line), 1);
	expand_wildcards(&tokens);
	shell->parser = init_parser();
	cmds = parser(tokens);
	if (!cmds)
		return (free_parser(shell->parser), shell->parser = NULL,
			cleanup_line(shell, NULL, tokens, NULL), free(line), 1);
	status = execute_commands(cmds, shell, shell->env);
	cleanup_line(shell, NULL, tokens, cmds);
	free(line);
	return (status);
}

/*
** ============================================================================
**	EXECUTE_SINGLE_LINE - Point d’entrée : exécution d’une ligne brute.
** ============================================================================
**	Parametres:
**		- @line:  ligne de commande lue depuis stdin ou readline.
**		- @shell: contexte global du shell.
**
**	Processus:
**		1. Gérer les subshells et opérateurs logiques avec process_*.
**		2. Tokenizer la ligne via get_tokens().
**		3. Si échec, libérer line et retourner code d’erreur.
**		4. Appeler execute_parsed_line() pour l’exécution complète.
**
**	Retour:
**		Code de retour de l’exécution ou 1 en cas d’erreur de parsing.
*/
int	execute_single_line(char *line, t_shell *shell)
{
	t_token	**tokens;

	if (process_parentheses(line, shell))
		return (free(line), shell->exit_status);
	if (process_logical(line, shell))
		return (free(line), shell->exit_status);
	tokens = get_tokens(shell, line);
	if (!tokens)
	{
		free(line);
		shell->exit_status = 2;
		return (2);
	}
	return (execute_parsed_line(shell, tokens, line));
}
