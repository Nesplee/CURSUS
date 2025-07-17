/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:40:48 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 18:02:03 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			COPY_ENV - Duplique le tableau d'environnement fourni.
** ============================================================================
**	Parametres:
**		- @env: tableau de chaînes C (terminé par NULL) à copier.
**
**	Variables locales :
**		new_env - tableau alloué pour contenir les pointeurs dupliqués.
**		i - compteur d'index lors de la copie.
**
**	Processus :
**		1. Compter le nombre d'entrées dans env.
**		2. Allouer new_env pour (count + 1) pointeurs.
**		3. Pour chaque env[i] :
**			- dupliquer avec ft_strdup()
**			- en cas d'erreur, libérer tout new_env et renvoyer NULL.
**		4. Terminer new_env par NULL.
**
**	Retour :
**		Pointeur vers new_env si succès, NULL sinon.
*/
static char	**copy_env(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			while (i >= 0)
				free(new_env[i--]);
			free(new_env);
			return (NULL);
		}
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

/*
** ============================================================================
**			INIT_SHELLITO - Alloue et initialise partiellement t_shell.
** ============================================================================
**	Parametres:
**		- @env: tableau de chaînes C (terminé par NULL) à copier.
**
**	Variables locales :
**		shell - t_shell nouvellement allouée (partiellement initialisée).
**
**	Processus :
**		1. Allouer shell.
**		2. Initialiser tokens, commands, lexer, parser à NULL.
**		3. Dupliquer env avec copy_env().
**		4. Récupérer cwd via getcwd().
**		5. En cas d'erreur, libérer shell et retourner NULL.
**
**	Retour :
**		Pointeur sur shell si succès, NULL sinon.
*/
static t_shell	*init_shellito(char **env)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->lexer = NULL;
	shell->parser = NULL;
	shell->env = copy_env(env);
	if (!shell->env)
	{
		free(shell);
		return (NULL);
	}
	shell->cwd = getcwd(NULL, 0);
	if (!shell->cwd)
	{
		free_env(shell->env);
		free(shell);
		return (NULL);
	}
	return (shell);
}

/*
** ============================================================================
**			INIT_SHELL - Termine l'initialisation de t_shell.
** ============================================================================
**	Parametres:
**		- @env: tableau de chaînes C (terminé par NULL) à copier.
**
**	Variables locales :
**		shell - t_shell partiellement prêt à compléter.
**
**	Processus :
**		1. Appeler init_shellito().
**		2. Initialiser exit_status à 0.
**		3. Mettre running à 1.
**		4. Initialiser signal_received et in_heredoc à 0.
**
**	Retour :
**		Pointeur sur t_shell entièrement initialisé, NULL sinon.
*/
t_shell	*init_shell(char **env)
{
	t_shell	*shell;

	shell = init_shellito(env);
	if (!shell)
		return (NULL);
	update_shlvl(&shell->env);
	shell->exit_status = 0;
	shell->running = 1;
	shell->signal_received = 0;
	shell->in_heredoc = 0;
	return (shell);
}
