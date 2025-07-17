/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:09:40 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/07 20:33:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	GET_TOKENS - Initialise le lexer et tokenize la ligne.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell contenant le contexte.
**		- @input: chaîne de caractères saisie.
**
**	Variables locales:
**		- tokens: tableau de t_token* retourné par le lexer.
**
**	Processus:
**		1. Appeler init_lexer(input) et stocker dans shell->lexer.
**		2. Si échec, retourner NULL.
**		3. Appeler tokenize(input) pour obtenir tokens.
**		4. Vérifier syntaxe avec check_syntax().
**		5. En cas d'erreur, libérer lexer et retourner NULL.
**
**	Retour:
**		Tableau de tokens valide ou NULL.
*/
t_token	**get_tokens(t_shell *shell, char *input)
{
	t_token	**tokens;

	shell->lexer = init_lexer(input);
	if (!shell->lexer)
		return (NULL);
	tokens = tokenize(input);
	if (!tokens || check_syntax(shell->lexer) != SUCCESS)
	{
		free_lexer(shell->lexer);
		shell->lexer = NULL;
		return (NULL);
	}
	return (tokens);
}

/*
** ============================================================================
**	GET_INPUT - Lit une ligne de stdin ou via readline selon tty.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell contenant le flag running.
**
**	Variables locales:
**		- prompt: chaîne du prompt formatée.
**		- line:   ligne lue.
**
**	Processus:
**		1. Définir prompt avec couleurs si isatty().
**		2. Si tty, appeler readline(prompt) et add_history().
**		3. Sinon, lire avec get_next_line() et retirer '\n'.
**		4. Si fin de fichier (line NULL), shell->running = 0.
**
**	Retour:
**		Chaîne lue ou NULL.
*/
static char	*get_input(t_shell *shell)
{
	const char	*prompt;
	char		*line;

	prompt = "\001" BOLD BLUE "\002minishell$ \001" RESET "\002";
	if (isatty(STDIN_FILENO))
	{
		line = readline(prompt);
		if (line && *line)
			add_history(line);
	}
	else
	{
		line = get_next_line(STDIN_FILENO);
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
	}
	if (!line)
		shell->running = 0;
	return (line);
}

/*
** ============================================================================
**	PROCESS_INPUT - Gère les cas vides, espaces ou affichage de $?.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell pour exit_status.
**		- @input: ligne lue.
**
**	Variables locales:
**		- i: index de parcours dans input.
**
**	Processus:
**		1. Si input vide, libérer et retourner 1.
**		2. Ignorer espaces initiaux; si ligne vide, libérer et 1.
**		3. Si input == "$?", afficher shell->exit_status et 1.
**		4. Sinon, retourner 0 pour continuer le traitement.
**
**	Retour:
**		1 si on interrompt la boucle de lecture, 0 sinon.
*/
static int	process_input(t_shell *shell, char *input)
{
	int	i;

	if (input[0] == '\0')
		return (free(input), 1);
	i = 0;
	while (input[i] && ft_isspace((unsigned char)input[i]))
		i++;
	if (!input[i])
		return (free(input), 1);
	if (ft_strcmp(input, "$?") == 0)
	{
		ft_putnbr_fd(shell->exit_status, STDOUT);
		ft_putchar_fd('\n', STDOUT);
		free(input);
		return (1);
	}
	return (0);
}

/*
** ============================================================================
**	HANDLE_LINE - Point d'entrée : boucle de lecture et exécution.
** ============================================================================
**	Parametres:
**		- @shell: pointeur vers t_shell contenant le contexte global.
**
**	Variables locales:
**		- input: ligne saisie.
**		- lexer: pointeur vers t_lexer pour vérification.
**
**	Processus:
**		1. Appeler get_input(); si shell->running == 0, retourner 0.
**		2. Si process_input() retourne 1, continuer la boucle.
**		3. Initialiser et vérifier lexer sur input.
**		4. Libérer lexer puis tester process_parentheses ou process_logical.
**		5. Si aucune route, exécuter via execute_single_line().
**
**	Retour:
**		1 pour continuer la boucle, 0 pour quitter.
*/
int	handle_line(t_shell *shell)
{
	char	*input;
	t_lexer	*lexer;

	input = get_input(shell);
	if (!shell->running)
		return (0);
	if (process_input(shell, input))
		return (1);
	lexer = init_lexer(input);
	if (!lexer || check_syntax(lexer) != SUCCESS)
	{
		if (lexer)
			free_lexer(lexer);
		free(input);
		shell->exit_status = 2;
		return (1);
	}
	free_lexer(lexer);
	if (process_parentheses(input, shell) || process_logical(input, shell))
	{
		free(input);
		return (1);
	}
	shell->exit_status = execute_single_line(input, shell);
	return (1);
}
