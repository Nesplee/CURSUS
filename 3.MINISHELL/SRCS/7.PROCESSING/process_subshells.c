/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_subshells.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:53:47 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 02:16:20 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	PROCESS_PIPELINE - Exécute une ligne sans subshell logique.
** ============================================================================
**	Parametres:
**		- @shell: contexte global du shell (t_shell*).
**		- @input: ligne de commande à traiter.
**
**	Processus:
**		1. Tenter process_logical(); si pris en charge, libérer input.
**		2. Obtenir tokens via get_tokens().
**		3. Appliquer expand_all(), expand_wildcards().
**		4. Initialiser parser et parser les tokens.
**		5. Exécuter commandes via execute_commands().
**		6. Libérer ressources et retourner le code.
**
**	Retour:
**		Code retour de l’exécution.
*/
static int	process_pipeline(t_shell *shell, char *input)
{
	t_token		**tokens;
	t_command	**cmds;
	int			ret;

	if (process_logical(input, shell))
	{
		free(input);
		return (shell->exit_status);
	}
	tokens = get_tokens(shell, input);
	if (!tokens)
		return (free(input), 1);
	if (!expand_all(tokens, shell->env, shell->exit_status))
		return (cleanup_line(shell, input, tokens, NULL), 1);
	tokens = merge_adjacent_tokens(tokens);
	expand_wildcards(&tokens);
	shell->parser = init_parser();
	cmds = parser(tokens);
	if (!cmds)
		return (free_parser(shell->parser), shell->parser = NULL,
			cleanup_line(shell, input, tokens, NULL), 1);
	ret = execute_commands(cmds, shell, shell->env);
	cleanup_line(shell, input, tokens, cmds);
	shell->exit_status = ret;
	return (ret);
}

/*
** ============================================================================
**	IS_WRAPPED_PARENTHESES - Vérifie que input est enveloppé par ().
** ============================================================================
**	Parametres:
**		- @input:     ligne de commande.
**		- @inner_len: adresse pour stocker la longueur sans ().
**
**	Processus:
**		1. Si input[0] != '(' ou taille < 2, échec.
**		2. Parcourir en maintenant depth pour '(' et ')'.
**		3. Si depth retombe à 0 avant la fin, vérifier position de fin.
**		4. Calculer *inner_len = len(input) - 2.
**
**	Retour:
**		1 si enveloppé correctement, 0 sinon.
*/
static int	is_wrapped_parentheses(char *input, int *inner_len)
{
	int	len;
	int	depth;
	int	i;

	len = ft_strlen(input);
	if (len < 2 || input[0] != '(')
		return (0);
	depth = 0;
	i = -1;
	while (++i < len)
	{
		if (input[i] == '(')
			depth++;
		else if (input[i] == ')')
			depth--;
		if (depth == 0)
			break ;
	}
	if (depth != 0 || i != len - 1)
		return (0);
	*inner_len = len - 2;
	return (1);
}

/*
** ============================================================================
**	RUN_SUBSHELL - Exécute un bloc () dans un sous-processus.
** ============================================================================
**	Parametres:
**		- @inner: ligne interne sans parenthèses.
**		- @shell: contexte du shell (t_shell*).
**
**	Processus:
**		1. Appeler process_logical(inner, shell).
**		2. Si pris en charge, retourner shell->exit_status.
**		3. Sinon, appeler process_pipeline(shell, inner).
**
**	Retour:
**		Code retour de l’exécution interne.
*/
static int	run_subshell(char *inner, t_shell *shell)
{
	if (process_logical(inner, shell))
		return (shell->exit_status);
	return (process_pipeline(shell, inner));
}

/*
** ============================================================================
**	PROCESS_PARENTHESES - Point d’entrée pour un subshell enveloppé.
** ============================================================================
**	Parametres:
**		- @input: ligne potentiellement "(...)".
**		- @shell: contexte global du shell.
**
**	Processus:
**		1. Vérifier enveloppement via is_wrapped_parentheses().
**		2. Extraire inner = ft_substr(input,1,*inner_len).
**		3. Forker et, dans l’enfant, exit(run_subshell()).
**		4. Dans le parent, attendre child et mettre à jour exit_status.
**
**	Retour:
**		1 si pris en charge, 0 sinon.
*/
int	process_parentheses(char *input, t_shell *shell)
{
	int		inner_len;
	char	*inner;
	pid_t	pid;
	int		status;

	if (!is_wrapped_parentheses(input, &inner_len))
		return (0);
	inner = ft_substr(input, 1, inner_len);
	if (!inner)
		return (0);
	pid = fork();
	if (pid < 0)
		return (free(inner), dis_fork_err(), 1);
	if (pid == 0)
		exit(run_subshell(inner, shell));
	free(inner);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
	return (1);
}
