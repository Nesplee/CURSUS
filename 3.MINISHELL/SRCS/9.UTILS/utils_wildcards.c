/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:06:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/12 19:20:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	split_dir_pattern - Sépare le chemin et le motif d'un pattern
** ============================================================================
**	Paramètres:
**		- @pattern: chaîne "path/to/dir/pattern" ou "pattern".
**		- @dir:     adresse pour stocker le chemin ("dir/").
**		- @pat:     adresse pour stocker le motif ("pattern").
**
**	Processus:
**		1. Chercher le dernier '/' dans pattern.
**		2. Si absent : *dir = ".", *pat = pattern.
**		3. Sinon :
**		   a. len = position de '/' - début + 1.
**		   b. *dir = ft_substr(pattern, 0, len).
**		   c. *pat = ft_strdup(chaîne après '/').
**
**	Retour:
**		(void)
*/
void	split_dir_pattern(char *pattern,
	char **dir, char **pat)
{
	char	*pos;
	int		len;

	pos = ft_strrchr(pattern, '/');
	if (!pos)
	{
		*dir = ft_strdup(".");
		*pat = ft_strdup(pattern);
	}
	else
	{
		len = pos - pattern + 1;
		*dir = ft_substr(pattern, 0, len);
		*pat = ft_strdup(pos + 1);
	}
}

/*
** ============================================================================
**	realloc_add - Réalloue la liste et ajoute un nom
** ============================================================================
**	Paramètres:
**		- @lst:  adresse du tableau de chaînes NULL-terminé.
**		- @cnt:  adresse du compteur d'éléments.
**		- @name: nom à dupliquer et ajouter.
**
**	Processus:
**		1. realloc(*lst, sizeof(*lst) * (*cnt + 2)).
**		2. Dupliquer name puis l'ajouter à (*lst)[*cnt].
**		3. Incrémenter *cnt, terminer par NULL.
**
**	Retour:
**		1 si succès, 0 sinon.
*/
static int	realloc_add(char ***lst, int *cnt, char *name)
{
	char	**tmp;

	tmp = realloc(*lst, sizeof(*tmp) * (*cnt + 2));
	if (!tmp)
		return (0);
	*lst = tmp;
	(*lst)[*cnt] = ft_strdup(name);
	if (!(*lst)[*cnt])
		return (0);
	(*cnt)++;
	(*lst)[*cnt] = NULL;
	return (1);
}

/*
** ============================================================================
**	add_match_prefixed - Ajoute un nom complet au motif
** ============================================================================
**	Paramètres:
**		- @lst:  adresse du tableau de chaînes.
**		- @cnt:  adresse du compteur d'éléments.
**		- @dir:  chemin du répertoire (ou ".").
**		- @name: nom de fichier à tester contre le motif.
**
**	Processus:
**		1. Si dir == ".", appeler realloc_add(lst, cnt, name).
**		2. Sinon :
**		   a. path = ft_strjoin(dir, name).
**		   b. realloc_add(lst, cnt, path).
**		   c. free(path).
**
**	Retour:
**		1 si succès, 0 sinon.
*/
int	add_match_prefixed(char ***lst, int *cnt,
	char *dir, char *name)
{
	char	*path;
	int		ret;

	if (dir[0] == '.' && dir[1] == '\0')
		return (realloc_add(lst, cnt, name));
	path = ft_strjoin(dir, name);
	if (!path)
		return (0);
	ret = realloc_add(lst, cnt, path);
	free(path);
	return (ret);
}
