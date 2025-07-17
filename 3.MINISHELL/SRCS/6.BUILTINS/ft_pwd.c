/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:39:17 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 14:49:57 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
** ft_pwd
** ============================================================================
** Description:
**   Affiche le répertoire de travail courant en appelant getcwd() pour
**   l'obtenir dynamiquement.
**
** Appels Système:
**   - getcwd(NULL, 0) : Alloue une chaîne contenant le chemin complet.
**   - ft_putendl_fd() : Affiche la chaîne avec un retour ligne.
**
** Processus:
**   1. Récupère le chemin courant avec getcwd(NULL, 0) dans "cwd".
**   2. Si getcwd échoue, appelle dis_memory_err() et retourne
**      EXIT_FAILURE.
**   3. Affiche "cwd" puis libère la mémoire.
**
** Paramètres:
**   Aucun.
**
** Retour:
**   EXIT_SUCCESS en cas de succès, EXIT_FAILURE sinon.
*/

int	ft_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		dis_memory_err();
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(cwd, STDOUT);
	free(cwd);
	return (EXIT_SUCCESS);
}
