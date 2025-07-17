/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:43:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 18:29:02 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**			INIT_REDIR - Alloue et initialise une structure t_redir.
** ============================================================================
**	Parametres:
**		(aucun)
**
**	Variables locales :
**		redir  - pointeur sur t_redir alloué.
**
**	Processus :
**		1. Allouer la structure t_redir.
**		2. Initialiser type à REDIR_INPUT.
**		3. Initialiser file à NULL.
**
**	Retour :
**		Pointeur sur t_redir si succès, NULL sinon.
*/
t_redir	*init_redir(void)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = REDIR_INPUT;
	redir->file = NULL;
	return (redir);
}
