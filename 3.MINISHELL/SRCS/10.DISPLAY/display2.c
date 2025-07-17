/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:38:22 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:25:42 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	dis_no_file_err - Affiche une erreur de fichier inexistant
** ============================================================================
**	Paramètres:
**		- @path: chemin du fichier non trouvé.
**
**	Processus:
**		1. Si path NULL, return.
**		2. Appeler dis_prompt_err().
**		3. Afficher path en italique suivi de ": ".
**		4. Afficher "no such file or directory" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_no_file_err(char *path)
{
	if (!path)
		return ;
	dis_prompt_err();
	ft_putstr_fd(ITALIC, 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": " RESET, 2);
	ft_putstr_fd(RED "no such file or directory\n" RESET, 2);
}

/*
** ============================================================================
**	dis_no_file_err - Affiche une erreur de fichier inexistant
** ============================================================================
**	Paramètres:
**		- @path: chemin du fichier non trouvé.
**
**	Processus:
**		1. Si path NULL, return.
**		2. Appeler dis_prompt_err().
**		3. Afficher path en italique suivi de ": ".
**		4. Afficher "no such file or directory" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_memory_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "memory allocation failed\n" RESET, 2);
}

/*
** ============================================================================
**	dis_fork_err - Affiche une erreur de fork
** ============================================================================
**	Paramètres:
**		(void)
**
**	Processus:
**		1. Appeler dis_prompt_err().
**		2. Afficher "fork failed" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_fork_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "fork failed\n" RESET, 2);
}

/*
** ============================================================================
**	dis_pipe_err - Affiche une erreur de création de pipe
** ============================================================================
**	Paramètres:
**		(void)
**
**	Processus:
**		1. Appeler dis_prompt_err().
**		2. Afficher "pipe failed" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_pipe_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "pipe failed\n" RESET, 2);
}
