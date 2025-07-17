/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:40:41 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 21:20:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	COUNT_REDIRS - Compte les redirections jusqu'au prochain opérateur.
** ============================================================================
**	Parametres:
**		- @tokens: tableau de t_token* issu du lexer.
**		- @start:  indice de départ dans le tableau.
**
**	Variables locales:
**		- count: compteur de redirections.
**		- i:     index courant dans tokens.
**
**	Processus:
**		1. Initialiser count = 0 et i = start.
**		2. Parcourir tokens[i] tant que non NULL et pas d'opérateur:
**		   a. Si tokens[i]->type == T_REDIR, incrémenter count.
**		   b. Incrémenter i.
**		3. Retourner count.
**
**	Retour:
**		Nombre de redirections trouvées.
*/
static int	count_redirs(t_token **tokens, int start)
{
	int	count;
	int	i;

	count = 0;
	i = start;
	while (tokens[i] && tokens[i]->type != T_OPERATOR)
	{
		if (tokens[i]->type == T_REDIR)
			count++;
		i++;
	}
	return (count);
}

/*
** ============================================================================
**	INIT_REDIRS - Alloue et initialise le tableau de redirections.
** ============================================================================
**	Parametres:
**		- @cmd:   pointeur vers t_command.
**		- @count: nombre de redirections à allouer.
**
**	Processus:
**		1. Allouer cmd->redirs pour (count + 1) pointeurs.
**		2. Initialiser la mémoire à 0 via ft_memset().
**		3. Affecter count à cmd->redir_count.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	init_redirs(t_command *cmd, int count)
{
	cmd->redirs = (t_redir **)malloc(sizeof(t_redir *) * (count + 1));
	if (!cmd->redirs)
		return (0);
	ft_memset(cmd->redirs, 0, sizeof(t_redir *) * (count + 1));
	cmd->redir_count = count;
	return (1);
}

/*
** ============================================================================
**	ADD_REDIR - Crée et ajoute une redirection à la commande.
** ============================================================================
**	Parametres:
**		- @cmd:    pointeur vers t_command.
**		- @tokens: tableau de t_token*.
**		- @pos:    pointeur vers l'indice courant dans tokens.
**
**	Variables locales:
**		- redir:         pointeur vers t_redir alloué.
**		- current_token: token de redirection.
**		- next_token:    token suivant pour le fichier.
**		- i:             index pour cmd->redirs.
**
**	Processus:
**		1. Allouer redir via init_redir().
**		2. Récupérer current_token et next_token.
**		3. Vérifier next_token valide et type T_WORD.
**		4. Dupliquer le nom de fichier dans redir->file.
**		5. Trouver la prochaine position libre dans cmd->redirs.
**		6. Ajouter redir, terminer par NULL et mettre à jour cmd->redir_count.
**		7. Incrementer *pos de 2.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	add_redir(t_command *cmd, t_token **tokens, int *pos)
{
	t_redir		*redir;
	t_token		*current_token;
	t_token		*next_token;
	int			i;

	redir = init_redir();
	if (!redir)
		return (0);
	current_token = tokens[*pos];
	next_token = tokens[*pos + 1];
	redir->type = current_token->redir;
	if (!next_token || next_token->type != T_WORD)
		return (0);
	redir->file = ft_strdup(tokens[*pos + 1]->value);
	if (!redir->file)
		return (0);
	i = 0;
	while (cmd->redirs[i])
		i++;
	cmd->redirs[i] = redir;
	cmd->redirs[i + 1] = NULL;
	cmd->redir_count = i + 1;
	*pos += 2;
	return (1);
}

/*
** ============================================================================
**	PARSE_REDIRS - Traite les redirections pour une commande.
** ============================================================================
**	Parametres:
**		- @cmd:    pointeur vers t_command.
**		- @parser: pointeur vers t_parser contenant tokens et position.
**
**	Variables locales:
**		- start:       position initiale du parser.
**		- redir_count: nombre de redirections à traiter.
**
**	Processus:
**		1. Déterminer redir_count via count_redirs().
**		2. Si redir_count == 0, retourner 1.
**		3. Appeler init_redirs() pour allouer cmd->redirs.
**		4. Parcourir tokens tant que non opérateur:
**		   a. Si token == T_REDIR, appeler add_redir().
**		   b. Sinon, parser->current++.
**		5. Retourner 1 si tout s'est bien passé.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	parse_redirections(t_command *cmd, t_parser *parser)
{
	int	start;
	int	redir_count;

	start = parser->current;
	redir_count = count_redirs(parser->tokens, start);
	if (redir_count == 0)
		return (1);
	if (!init_redirs(cmd, redir_count))
		return (0);
	while (parser->tokens[parser->current]
		&& parser->tokens[parser->current]->type != T_OPERATOR)
	{
		if (parser->tokens[parser->current]->type == T_REDIR)
		{
			if (!add_redir(cmd, parser->tokens, &parser->current))
				return (0);
		}
		else
			parser->current++;
	}
	return (1);
}
