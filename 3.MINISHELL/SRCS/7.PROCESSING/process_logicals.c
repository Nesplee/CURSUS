/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_logicals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:45:35 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 18:47:26 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	find_top_and - Repère le premier '&&' hors parenthèses
** ============================================================================
**	Parametres:
**		- @s:   chaîne de caractères à scanner.
**		- @pos: adresse pour stocker l’index trouvé.
**
**	Processus:
**		1. Parcourir s[i], maintenir profondeur depth pour '(' et ')'.
**		2. Si depth == 0 et s[i] == '&' && s[i+1] == '&', stocker i.
**
**	Retour:
**		1 si trouvé, 0 sinon.
*/
static int	find_top_and(const char *s, int *pos)
{
	int	depth;
	int	i;

	depth = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			depth++;
		else if (s[i] == ')')
			depth--;
		else if (depth == 0 && s[i] == '&' && s[i + 1] == '&')
		{
			*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** ============================================================================
**	find_top_or - Repère le premier '||' hors parenthèses
** ============================================================================
**	Parametres:
**		- @s:   chaîne de caractères à scanner.
**		- @pos: adresse pour stocker l’index trouvé.
**
**	Processus:
**		1. Parcourir s[i], maintenir profondeur depth pour '(' et ')'.
**		2. Si depth == 0 et s[i] == '|' && s[i+1] == '|', stocker i.
**
**	Retour:
**		1 si trouvé, 0 sinon.
*/
static int	find_top_or(const char *s, int *pos)
{
	int	depth;
	int	i;

	depth = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '(')
			depth++;
		else if (s[i] == ')')
			depth--;
		else if (depth == 0 && s[i] == '|' && s[i + 1] == '|')
		{
			*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** ============================================================================
**	handle_and - Execute deux sous-commandes liées par '&&'
** ============================================================================
**	Parametres:
**		- @input: ligne contenant '&&'.
**		- @shell: contexte du shell pour exit_status.
**
**	Processus:
**		1. Trouver l’opérateur via find_top_and().
**		2. Séparer input en left et right, trim espaces.
**		3. Exécuter left ; si succès, exécuter right.
**		4. Mettre à jour shell->exit_status.
**
**	Retour:
**		1 si prise en charge, 0 sinon.
*/
static int	handle_and(char *input, t_shell *shell)
{
	int		pos;
	char	*left;
	char	*right;
	int		ret;

	if (!find_top_and(input, &pos))
		return (0);
	input[pos] = '\0';
	left = ft_strtrim(input, " \t");
	right = ft_strtrim(input + pos + 2, " \t");
	ret = execute_single_line(left, shell);
	if (ret == EXIT_SUCCESS)
		ret = execute_single_line(right, shell);
	else
		free(right);
	shell->exit_status = ret;
	return (1);
}

/*
** ============================================================================
**	handle_or - Execute deux sous-commandes liées par '||'
** ============================================================================
**	Parametres:
**		- @input: ligne contenant '||'.
**		- @shell: contexte du shell pour exit_status.
**
**	Processus:
**		1. Trouver l’opérateur via find_top_or().
**		2. Séparer input en left et right, trim espaces.
**		3. Exécuter left ; si échec, exécuter right.
**		4. Mettre à jour shell->exit_status.
**
**	Retour:
**		1 si prise en charge, 0 sinon.
*/
static int	handle_or(char *input, t_shell *shell)
{
	int		pos;
	char	*left;
	char	*right;
	int		ret;

	if (!find_top_or(input, &pos))
		return (0);
	input[pos] = '\0';
	left = ft_strtrim(input, " \t");
	right = ft_strtrim(input + pos + 2, " \t");
	ret = execute_single_line(left, shell);
	if (ret != EXIT_SUCCESS)
		ret = execute_single_line(right, shell);
	else
		free(right);
	shell->exit_status = ret;
	return (1);
}

/*
** ============================================================================
**	process_logical - Point d’entrée pour '&&' et '||'
** ============================================================================
**	Parametres:
**		- @input: ligne de commande à traiter.
**		- @shell: contexte du shell pour exécution et status.
**
**	Processus:
**		1. Appeler handle_and() ; si succès, retourner 1.
**		2. Appeler handle_or()  ; si succès, retourner 1.
**		3. Sinon, non pris en charge.
**
**	Retour:
**		1 si un opérateur logique a été exécuté, 0 sinon.
*/
int	process_logical(char *input, t_shell *shell)
{
	if (handle_and(input, shell))
		return (1);
	if (handle_or(input, shell))
		return (1);
	return (0);
}
