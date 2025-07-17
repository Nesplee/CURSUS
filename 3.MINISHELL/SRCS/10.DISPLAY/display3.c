/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:10:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:27:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	dis_var_syntax_err - Affiche une erreur de syntaxe pour une variable
** ============================================================================
**	Paramètres:
**		- @token: token ayant une erreur de syntaxe.
**
**	Processus:
**		1. Afficher le prompt d'erreur.
**		2. Afficher "variable syntax error: " en rouge.
**		3. Si token non NULL, afficher en italique token suivi d'un saut de
**				ligne.
**		   Sinon, afficher "unexpected variable token" en italique.
**
**	Retour:
**		(void)
*/
void	dis_var_syntax_err(char *token)
{
	dis_prompt_err();
	ft_putstr_fd(RED "variable syntax error: " RESET, 2);
	if (token)
	{
		ft_putstr_fd(ITALIC, 2);
		ft_putstr_fd(token, 2);
		ft_putstr_fd("\n" RESET, 2);
	}
	else
		ft_putstr_fd(ITALIC "unexpected variable token\n" RESET, 2);
}

/*
** ============================================================================
**	dis_heredoc_eof_err - Affiche un avertissement EOF inattendu en heredoc
** ============================================================================
**	Paramètres:
**		(void)
**
**	Processus:
**		1. Afficher le prompt d'erreur.
**		2. Afficher "warning: here-document delimited by end-of-file" en rouge.
**		3. Ajouter un saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_heredoc_eof_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "warning: here-document delimited by end-of-file\n"
		RESET, 2);
}

/*
** ============================================================================
**	dis_paren_mismatch_err - Affiche une erreur de parenthèses non appariées
** ============================================================================
**	Paramètres:
**		(void)
**
**	Processus:
**		1. Afficher le prompt d'erreur.
**		2. Afficher "mismatched parentheses" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_paren_mismatch_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "mismatched parentheses\n" RESET, 2);
}

/*
** ============================================================================
**	dis_paren_empty_err - Affiche une erreur pour des parenthèses vides
** ============================================================================
**	Paramètres:
**		(void)
**
**	Processus:
**		1. Afficher le prompt d'erreur.
**		2. Afficher "empty parentheses not allowed" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_paren_empty_err(void)
{
	dis_prompt_err();
	ft_putstr_fd(RED "empty parentheses not allowed\n" RESET, 2);
}

/*
** ============================================================================
**	dis_is_directory_err - Affiche une erreur de type « is a directory »
** ============================================================================
**	Paramètres:
**		- @path: chemin du fichier/dossier.
**
**	Processus:
**		1. Si path NULL, return.
**		2. Afficher le prompt d'erreur.
**		3. Afficher path en italique suivi de ": ".
**		4. Afficher "is a directory" en rouge et saut de ligne.
**
**	Retour:
**		(void)
*/
void	dis_is_directory_err(char *path)
{
	if (!path)
		return ;
	dis_prompt_err();
	ft_putstr_fd(ITALIC, STDERR);
	ft_putstr_fd(path, STDERR);
	ft_putstr_fd(": " RESET, STDERR);
	ft_putstr_fd(RED "is a directory\n" RESET, STDERR);
}
