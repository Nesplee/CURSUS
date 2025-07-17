/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:21:34 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/04 17:23:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**		ALLOCATE_ARGS - Alloue le tableau d'arguments pour une commande.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command dont le champ args sera alloué.
**
**	Variables locales:
**		- (aucune)
**
**	Processus:
**		1. Calculer le nombre d’éléments : cmd->arg_count + 1.
**		2. Allouer cmd->args avec malloc().
**		3. Si l’allocation échoue, retourner 0.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	allocate_args(t_command *cmd)
{
	cmd->args = (char **)malloc(sizeof(char *) * (cmd->arg_count + 1));
	if (!cmd->args)
		return (0);
	return (1);
}

/*
** ============================================================================
**		FILL_ARGS - Copie les tokens en arguments de la commande.
** ============================================================================
**	Parametres:
**		- @cmd:    pointeur vers t_command à remplir.
**		- @tokens: tableau de t_token* issu du lexer.
**		- @start:  indice de départ dans tokens.
**		- @end_i:  pointeur vers entier mis à jour avec l’indice suivant.
**
**	Variables locales:
**		- i:     indice de parcours dans tokens.
**		- arg_i: compteur d’arguments remplis.
**
**	Processus:
**		1. Initialiser i = start, arg_i = 0.
**		2. Tant que tokens[i] existe et n’est pas opérateur/redir :
**		   a. Si type T_WORD ou T_VAR, dupliquer value dans cmd->args[arg_i].
**		   b. Incrémenter arg_i.
**		   c. Si duplication échoue, libérer via free_args() et retourner 0.
**		   d. Incrémenter i.
**		3. Placer NULL en fin de cmd->args.
**		4. Mettre *end_i = i.
**
**	Retour:
**		1 si succès, 0 sinon.
*/

static char	*get_next_arg(t_token **tokens, int *i)
{
	char	*arg;
	char	*tmp;

	arg = ft_strdup(tokens[*i]->value);
	if (!arg)
		return (NULL);
	while (tokens[*i + 1] && tokens[*i + 1]->merging == 1)
	{
		*i = *i + 1;
		tmp = ft_strjoin(arg, tokens[*i]->value);
		free(arg);
		arg = tmp;
	}
	*i = *i + 1;
	return (arg);
}

/*
** ============================================================================
**   FILL_ARGS - Copie les tokens en args via get_next_arg().
** ============================================================================
*/
static int	fill_args(t_command *cmd, t_token **t, int start, int *end_i)
{
	int		i;
	int		arg_i;
	char	*val;

	i = start;
	arg_i = 0;
	while (t[i] && t[i]->type != T_OPERATOR && t[i]->type != T_REDIR)
	{
		val = get_next_arg(t, &i);
		if (!val)
		{
			free_args(cmd->args, arg_i);
			return (0);
		}
		cmd->args[arg_i] = val;
		arg_i++;
	}
	cmd->args[arg_i] = NULL;
	*end_i = i;
	return (1);
}

/*
** ============================================================================
**		FINALIZE_COMMAND - Finalise la construction de la commande.
** ============================================================================
**	Parametres:
**		- @cmd: pointeur vers t_command à finaliser.
**
**	Variables locales:
**		- (aucune)
**
**	Processus:
**		1. Si cmd->arg_count > 0 :
**		   a. Dupliquer cmd->args[0] dans cmd->name.
**		   b. Déterminer cmd->builtin_id avec is_builtin().
**		   c. Mettre cmd->is_builtin à 1 si builtin, 0 sinon.
**		   d. Si duplication échoue, retourner 0.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	finalize_command(t_command *cmd)
{
	if (cmd->arg_count > 0)
	{
		cmd->name = ft_strdup(cmd->args[0]);
		if (cmd->name == NULL)
			return (0);
		cmd->builtin_id = is_builtin(cmd->name);
		cmd->is_builtin = (cmd->builtin_id != BI_NONE);
	}
	return (1);
}

/*
** ============================================================================
**		PARSE_COMMAND - Point d’entrée du parsing d’une commande.
** ============================================================================
**	Parametres:
**		- @parser: pointeur vers t_parser contenant tokens et position.
**
**	Variables locales:
**		- cmd:   pointeur vers t_command créé.
**		- start: indice de départ dans tokens.
**		- fin_i: indice après traitement des args.
**
**	Processus:
**		1. Récupérer start = parser->current.
**		2. Initialiser cmd via init_command().
**		3. Calculer cmd->arg_count avec count_args().
**		4. Allouer et remplir arguments :
**		   a. allocate_args(), fill_args(), finalize_command().
**		   b. En cas d’erreur, free_command() et retourner NULL.
**		5. Mettre parser->current = fin_i.
**		6. Appeler parse_redirections(cmd, parser) :
**		   en cas d’échec, free_command() et NULL.
**		7. Retourner cmd.
**
**	Retour:
**		Pointeur sur t_command si succès, NULL sinon.
*/
t_command	*parse_command(t_parser *parser)
{
	t_command	*cmd;
	int			start;
	int			fin_i;

	start = parser->current;
	cmd = init_command();
	if (cmd == NULL)
		return (NULL);
	cmd->arg_count = count_args(parser->tokens, start);
	if (!allocate_args(cmd)
		|| !fill_args(cmd, parser->tokens, start, &fin_i)
		|| !finalize_command(cmd))
	{
		free_command(cmd);
		return (NULL);
	}
	parser->current = fin_i;
	if (!parse_redirections(cmd, parser))
	{
		free_command(cmd);
		return (NULL);
	}
	return (cmd);
}
