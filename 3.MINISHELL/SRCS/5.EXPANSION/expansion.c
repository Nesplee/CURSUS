/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:50:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 14:46:20 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	EXPAND_ALL - Applique toutes les expansions sur les tokens.
** ============================================================================
**	Parametres:
**		- @tokens:      tableau de pointeurs t_token* issus du parser.
**		- @env:         tableau de chaînes d'environnement "KEY=VALUE".
**		- @exit_status: code de sortie du dernier builtin.
**
**	Processus:
**		1. Parcourir chaque token de tokens[].
**		2. Si tok->type == T_VAR :
**		   a. Si tok->value == "$?" : appeler replace_exit_status().
**		   b. Sinon : appeler replace_var_token().
**		3. Sinon, si tok->type == T_WORD et tok->quote == DOUBLE_QUOTE :
**		   appeler expand_var_in_dquotes().
**		4. Les autres tokens sont laissés intacts.
**
**	Retour:
**		1 si toutes les expansions ont réussi, 0 sinon.
*/
int	expand_all(t_token **tokens, char **env, int exit_status)
{
	int		i;
	t_token	*tok;

	i = 0;
	while (tokens[i])
	{
		tok = tokens[i];
		if (tok->type == T_VAR)
		{
			if (tok->value[1] == '?' && tok->value[2] == '\0')
				replace_exit_status(tok, exit_status);
			else
				replace_var_token(tok, env);
		}
		else if (tok->type == T_WORD
			&& tok->quote == DOUBLE_QUOTE
			&& ft_strchr(tok->value, '$')
		)
		{
			if (!expand_var_in_dquotes(tok, env, exit_status))
				return (0);
		}
		i++;
	}
	return (1);
}
