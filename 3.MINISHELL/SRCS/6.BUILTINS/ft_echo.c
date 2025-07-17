/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:37:30 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 13:37:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

static int	parse_flags(char **args, int *i)
{
	int	j;
	int	nl;

	nl = 1;
	while (args[*i] && args[*i][0] == '-' && args[*i][1] == 'n')
	{
		j = 2;
		while (args[*i][j] == 'n')
			j++;
		if (args[*i][j] != '\0')
			break ;
		nl = 0;
		(*i)++;
	}
	return (nl);
}
/*
** ============================================================================
** ft_echo
** ============================================================================
** Description:
**   Imitation de la commande shell "echo". Affiche les arguments fournis
**   séparés par un espace. Si le premier argument est "-n", n'ajoute pas
**   de saut de ligne final.
**
** Processus:
**   1. Initialise "nl" (flag newline) à 1 et démarre à l'index 1 (nom exclu).
**   2. Si args[1] vaut "-n", met nl à 0 et incrémente l'index.
**   3. Parcourt les arguments restants, les affiche avec ft_putstr_fd()
**      et ajoute un espace entre eux.
**   4. Si nl est 1, affiche un saut de ligne à la fin.
**
** Paramètres:
**   args : Tableau de chaînes de caractères (arguments).
**
** Retour:
**   EXIT_SUCCESS en cas de succès.
*/

static void	print_args(char **args, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT);
		i++;
	}
}

int	ft_echo(char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = parse_flags(args, &i);
	print_args(args, i);
	if (nl)
		ft_putstr_fd("\n", STDOUT);
	return (EXIT_SUCCESS);
}
