/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:46:39 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 01:20:54 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	handle_input_redir - Gère l’ouverture d’un fichier en lecture.
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir contenant redir->file (chemin du
**					fichier).
**
**	Processus:
**		1. open() en O_RDONLY.
**		2. En cas d’erreur, afficher via dis_no_file_err() et retourner 0.
**		3. dup2(fd, STDIN_FILENO) puis close(fd).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	handle_input_redir(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_RDONLY);
	if (fd < 0)
	{
		dis_no_file_err(redir->file);
		return (0);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (1);
}

/*
** ============================================================================
**	handle_output_redir - Gère l’ouverture d’un fichier en écriture (truncate).
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir contenant redir->file (chemin du
**					 fichier).
**
**	Processus:
**		1. open() en O_WRONLY | O_CREAT | O_TRUNC, mode 0644.
**		2. En cas d’erreur, afficher via dis_perm_err() et retourner 0.
**		3. dup2(fd, STDOUT_FILENO) puis close(fd).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	handle_output_redir(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		dis_perm_err(redir->file);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

/*
** ============================================================================
**	handle_append_redir - Gère l’ouverture d’un fichier en écriture (append).
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir contenant redir->file (chemin du
**					fichier).
**
**	Processus:
**		1. open() en O_WRONLY | O_CREAT | O_APPEND, mode 0644.
**		2. En cas d’erreur, afficher via dis_perm_err() et retourner 0.
**		3. dup2(fd, STDOUT_FILENO) puis close(fd).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	handle_append_redir(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		dis_perm_err(redir->file);
		return (0);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

/*
** ============================================================================
**	process_redirection - Applique la redirection selon son type.
** ============================================================================
**	Parametres:
**		- @redir: pointeur vers t_redir à traiter.
**
**	Processus:
**		1. Selon redir->type appeler l’une des fonctions handle_*_redir().
**		2. Retourner leur code de succès (1) ou d’échec (0).
**
**	Retour:
**		1 si pris en charge et réussi, 0 sinon.
*/
static int	process_redirection(t_redir *redir)
{
	if (redir->type == REDIR_HEREDOC)
	{
		dup2(redir->fd, STDIN_FILENO);
		close(redir->fd);
		return (1);
	}
	else if (redir->type == REDIR_INPUT)
		return (handle_input_redir(redir));
	else if (redir->type == REDIR_OUTPUT)
		return (handle_output_redir(redir));
	else if (redir->type == REDIR_APPEND)
		return (handle_append_redir(redir));
	return (0);
}

/*
** ============================================================================
**	setup_redirections - Parcourt et applique toutes les redirections.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command dont redirs[] et redir_count sont
**					définis.
**
**	Processus:
**		1. Boucler i de 0 à cmd->redir_count - 1.
**		2. Appeler process_redirection(cmd->redirs[i]).
**		3. En cas d’échec, retourner 0 immédiatement.
**		4. Continuer jusqu’à épuisement.
**
**	Retour:
**		1 si toutes les redirections ont été appliquées avec succès, 0 sinon.
*/

int	setup_redirections(t_command *cmd, t_shell *shell)
{
	int	i;

	(void)shell;
	i = 0;
	while (i < cmd->redir_count)
	{
		if (!process_redirection(cmd->redirs[i]))
			return (0);
		i++;
	}
	return (1);
}
