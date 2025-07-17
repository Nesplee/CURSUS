/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:04:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 21:33:38 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

char	*expand_heredoc_line(const char *line, char **env, int exit_status)
{
	t_token	temp;
	char	*expanded_line;

	temp.value = ft_strdup(line);
	if (!temp.value)
		return (NULL);
	temp.quote = DOUBLE_QUOTE;
	if (!expand_var_in_dquotes(&temp, env, exit_status))
	{
		free(temp.value);
		return (NULL);
	}
	expanded_line = temp.value;
	return (expanded_line);
}
/*
** ============================================================================
**	GO_HEREDOC - Lit les lignes jusqu’au délimiteur et écrit dans le pipe.
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir contenant redir->file (délimiteur).
**		- @wfd:   descripteur d’écriture du pipe.
**
**	Processus:
**		1. Afficher le prompt “> ” et lire une ligne via readline().
**		2. Tant que line != NULL :
**		   a. Si line == redir->file, free(line) et break.
**		   b. Sinon, write(wfd, line, strlen(line)) + '\n', free(line).
**		   c. Lire la ligne suivante.
**
**	Retour:
**		(void) – sortie via break ou EOF.
*/

static void	go_heredoc(t_redir *redir, int wfd, char **env, int exit_status)
{
	char	*line;
	char	*expanded;

	line = readline("> ");
	while (line != NULL)
	{
		if (strcmp(line, redir->file) == 0)
		{
			free(line);
			break ;
		}
		if (ft_strchr(line, '$'))
		{
			expanded = expand_heredoc_line(line, env, exit_status);
			free(line);
			if (expanded)
				line = expanded;
		}
		write(wfd, line, ft_strlen(line));
		write(wfd, "\n", 1);
		free(line);
		line = readline("> ");
	}
}

/*
** ============================================================================
**	INIT_HEREDOC - Prépare le pipe et fork pour le heredoc.
** ============================================================================
**	Parametres:
**		- @pipefd:       tableau de 2 int pour pipe().
**		- @saved_stdin:  adresse pour stocker la copie de STDIN.
**
**	Processus:
**		1. Dupliquer STDIN_FILENO dans *saved_stdin.
**		2. Créer un pipe(pipefd).
**		3. Forker un processus enfant.
**		4. En cas d’erreur sur dup, pipe ou fork, afficher erreur et
**			retourner -1.
**
**	Retour:
**		pid du processus enfant, 0 dans l’enfant, <0 en cas d’erreur.
*/

static pid_t	init_heredoc_pipe(int pipefd[2])
{
	pid_t	pid;

	if (pipe(pipefd) < 0)
		return (dis_pipe_err(), -1);
	pid = fork();
	if (pid < 0)
	{
		dis_fork_err();
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	return (pid);
}

/*
** ============================================================================
**	PARENT_HEREDOC - Gère le parent après fork pour le heredoc.
** ============================================================================
**	Parametres:
**		- @pipefd:       tableau de 2 int du pipe.
**		- @saved_stdin:  copie de l’ancien STDIN à restaurer si besoin.
**		- @pid:          PID de l’enfant heredoc.
**
**	Processus:
**		1. Ignorer SIGINT dans le parent.
**		2. Fermer l’extrémité write du pipe.
**		3. waitpid(pid) et récupérer status.
**		4. Restaurer handlers de signaux initiaux.
**		5. Si enfant a réussi, dup2(pipefd[0], STDIN_FILENO).
**		   Sinon, afficher erreur EOF et dup2(saved_stdin, STDIN_FILENO).
**		6. Fermer pipefd[0] et saved_stdin.
**
**	Retour:
**		1 si le heredoc est prêt, 0 sinon (jamais ici).
*/

static int	parent_heredoc(int pipefd[2], pid_t pid, t_redir *redir)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	close(pipefd[1]);
	waitpid(pid, &status, 0);
	init_signals();
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
	{
		redir->fd = pipefd[0];
		return (1);
	}
	close(pipefd[0]);
	dis_heredoc_eof_err();
	return (0);
}

/*
** ============================================================================
**	HANDLE_HEREDOC - Point d’entrée pour le traitement d’un heredoc.
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir définissant le heredoc.
**
**	Processus:
**		1. Appeler init_heredoc() pour préparer pipe et fork.
**		2. Si pid < 0, retourner 0 (erreur).
**		3. Si pid == 0 (enfant) :
**		   a. Restaurer SIGINT par défaut.
**		   b. Fermer pipefd[0] et appeler go_heredoc().
**		   c. Fermer pipefd[1] et exit(EXIT_SUCCESS).
**		4. Sinon (parent), appeler parent_heredoc().
**
**	Retour:
**		1 si succès, 0 sinon.
*/

int	handle_heredoc(t_redir *redir, char **env, int exit_status)
{
	pid_t	pid;
	int		pipefd[2];

	pid = init_heredoc_pipe(pipefd);
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(pipefd[0]);
		go_heredoc(redir, pipefd[1], env, exit_status);
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	return (parent_heredoc(pipefd, pid, redir));
}
