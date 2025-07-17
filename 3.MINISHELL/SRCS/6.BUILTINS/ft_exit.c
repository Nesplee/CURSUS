/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:59:00 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/05 21:04:07 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
** ft_exit
** ============================================================================
** Description:
**   Quitte le shell en libérant toutes les ressources associées à l'instance
**   du shell, puis termine le processus avec un code de retour. Si aucun code
**   n'est fourni dans args[1], le code 0 est utilisé par défaut.
**
** Processus:
**   1. Déclare la variable exit_code.
**   2. Si args[1] existe, convertit sa valeur en entier avec ft_atoi,
**      sinon, utilise 0.
**   3. Libère les ressources du shell via free_shell.
**   4. Termine le processus en appelant exit(exit_code).
**
** Paramètres:
**   shell : Pointeur sur l'instance du shell à libérer.
**   args  : Tableau de chaînes d'arguments, args[1] contenant le code
**           de retour souhaité (optionnel).
**
** Retour:
**   Ne retourne pas, la fonction termine le processus.
*/
static int	is_numeric(const char *s)
{
	if (!*s)
		return (0);
	if ((*s == '+' || *s == '-') && s[1])
		s++;
	while (*s)
	{
		if (!ft_isdigit((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

int	ft_exit(t_shell *shell, char **args)
{
	int	exit_code;

	if (args[1] && args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (shell->exit_status = 1);
	}
	if (args[1] && !is_numeric(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		free_shell(shell);
		exit(2);
	}
	if (args[1])
		exit_code = ft_atoi(args[1]);
	else
		exit_code = shell->exit_status;
	free_shell(shell);
	exit(exit_code);
}
