/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:45:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 14:50:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
** ft_env
** ============================================================================
** Description:
**   Affiche toutes les variables d'environnement. La fonction parcourt le
**   tableau env et affiche chaque chaîne suivie d'un saut de ligne.
**
** Processus:
**   1. Initialise l'indice à 0.
**   2. Parcourt le tableau env avec une boucle while.
**   3. Affiche chaque variable avec ft_putendl_fd().
**
** Paramètres:
**   env : Tableau de chaînes (variables d'environnement).
**
** Retour:
**   EXIT_SUCCESS en cas de succès.
*/

int	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], STDOUT);
		i = i + 1;
	}
	return (EXIT_SUCCESS);
}
