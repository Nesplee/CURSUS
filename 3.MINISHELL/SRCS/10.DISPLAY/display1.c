/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:36:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:24:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	dis_prompt_err - Affiche le prompt pour les messages d'erreur
** ============================================================================
**	Processus:
**		1. Afficher "minishell: " en bleu gras sur stderr.
**
**	> Préfixe standardisé pour tous les messages d'erreur.
*/
void	dis_prompt_err(void)
{
	ft_putstr_fd(BOLD BLUE "minishell: " RESET, 2);
}

/*
** ============================================================================
**	dis_syntax_err_custom - Affiche une erreur de syntaxe personnalisée
** ============================================================================
**	Paramètres:
**		- @msg: message d'erreur ou NULL pour message par défaut.
**
**	Processus:
**		1. Afficher le prompt d'erreur.
**		2. Afficher "syntax error: " en rouge.
**		3. Si msg non NULL, afficher en italique msg.
**		   Sinon, afficher "unexpected token" en italique.
**		4. Terminer par un saut de ligne.
*/
void	dis_syntax_err_custom(char *msg)
{
	dis_prompt_err();
	ft_putstr_fd(RED "syntax error: " RESET, 2);
	if (msg)
	{
		ft_putstr_fd(ITALIC, 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(RESET "\n", 2);
	}
	else
		ft_putstr_fd(ITALIC "unexpected token\n" RESET, 2);
}

/*
** ============================================================================
**	dis_cmd_not_found_err - Affiche une erreur de commande introuvable
** ============================================================================
**	Paramètres:
**		- @cmd: nom de la commande.
**
**	Processus:
**		1. Si cmd NULL, ne rien faire.
**		2. Afficher le prompt d'erreur.
**		3. Afficher cmd en italique suivi de ": ".
**		4. Afficher "command not found..." en rouge et saut de ligne.
*/
void	dis_cmd_not_found_err(char *cmd)
{
	if (!cmd)
		return ;
	dis_prompt_err();
	ft_putstr_fd(ITALIC, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": " RESET, 2);
	ft_putstr_fd(RED "command not found...\n" RESET, 2);
}

/*
** ============================================================================
**	dis_perm_err - Affiche une erreur de permission
** ============================================================================
**	Paramètres:
**		- @path: chemin du fichier/dossier.
**
**	Processus:
**		1. Si path NULL, ne rien faire.
**		2. Afficher le prompt d'erreur.
**		3. Afficher path en italique suivi de ": ".
**		4. Afficher "permission denied" en rouge et saut de ligne.
*/
void	dis_perm_err(char *path)
{
	if (!path)
		return ;
	dis_prompt_err();
	ft_putstr_fd(ITALIC, 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": " RESET, 2);
	ft_putstr_fd(RED "permission denied\n" RESET, 2);
}
