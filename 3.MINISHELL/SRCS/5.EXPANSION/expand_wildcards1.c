/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:36:25 by dinguyen          #+#    #+#             */
/*   Updated: 2025/05/11 21:29:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

/*
** ============================================================================
**	WILDCARD_MATCH - Vérifie si une chaîne correspond à un motif.
** ============================================================================
**	Parametres:
**		- @pat: motif pouvant contenir '*' et '?'.
**		- @str: chaîne à tester.
**
**	Processus:
**		1. Si pat vide, vrai si str vide.
**		2. Si caractère '*' :
**		   a. Ignorer multiples '*' consécutifs.
**		   b. Si fin de motif, toujours vrai.
**		   c. Sinon, tenter récursivement chaque position de str.
**		3. Si '?' et str non vide, ou caractères identiques,
**		   avancer dans pat et str.
**		4. Sinon, non correspondance.
**
**	Retour:
**		1 si correspondance, 0 sinon.
*/
static int	wildcard_match(char *pat, char *str)
{
	if (!*pat)
		return (!*str);
	if (*pat == '*')
	{
		while (pat[1] == '*')
			pat++;
		if (!pat[1])
			return (1);
		while (*str)
			if (wildcard_match(pat + 1, str++))
				return (1);
		return (0);
	}
	if ((*pat == '?' && *str) || (*pat == *str))
		return (wildcard_match(pat + 1, str + 1));
	return (0);
}

/*
** ============================================================================
**	COLLECT_ENTRIES - Parcourt un répertoire et retient les correspondances.
** ============================================================================
**	Parametres:
**		- @d:     pointeur vers DIR ouvert.
**		- @dir:   chemin du répertoire (avec slash final).
**		- @pat:   motif à matcher.
**		- @count: pointeur pour compter les entrées ajoutées.
**
**	Variables locales:
**		- lst: liste de chaînes résultat.
**		- e:   structure dirent pour chaque entrée.
**
**	Processus:
**		1. Initialiser lst à NULL et *count à 0.
**		2. Pour chaque entrée via readdir():
**		   a. Ignorer fichiers cachés si motif ne commence pas par '.'.
**		   b. Si wildcard_match(pat, e->d_name) vrai,
**		      appeler add_match_prefixed(&lst, count, dir, e->d_name).
**		   c. En cas d'erreur d'ajout, arrêter la collecte.
**
**	Retour:
**		Tableau de chaînes alloué ou NULL.
*/
static char	**collect_entries(DIR *d, char *dir,
	char *pat, int *count)
{
	char			**lst;
	struct dirent	*e;

	lst = NULL;
	*count = 0;
	while (1)
	{
		e = readdir(d);
		if (!e)
			break ;
		if (e->d_name[0] == '.' && pat[0] != '.')
			continue ;
		if (wildcard_match(pat, e->d_name))
			if (!add_match_prefixed(&lst, count, dir, e->d_name))
				break ;
	}
	return (lst);
}

/*
** ============================================================================
**	PROCESS_COLLECT - Ouvre le répertoire et gère la mémoire.
** ============================================================================
**	Parametres:
**		- @dir:   chaîne chemin du répertoire.
**		- @pat:   motif à matcher.
**		- @count: pointeur pour recevoir le nombre de matchs.
**
**	Variables locales:
**		- d:   DIR* pour opendir.
**		- lst: résultat de collect_entries().
**
**	Processus:
**		1. Tenter opendir(dir); en cas d'erreur, libérer dir et pat.
**		2. Appeler collect_entries(d, dir, pat, count).
**		3. Fermer le DIR et libérer dir, pat.
**
**	Retour:
**		Tableau de correspondances ou NULL.
*/
static char	**process_collect(char *dir, char *pat, int *count)
{
	DIR		*d;
	char	**lst;

	d = opendir(dir);
	if (!d)
	{
		free(dir);
		free(pat);
		return (NULL);
	}
	lst = collect_entries(d, dir, pat, count);
	closedir(d);
	free(dir);
	free(pat);
	return (lst);
}

/*
** ============================================================================
**	COLLECT_MATCHES - Point d'entrée pour l'expansion des wildcards.
** ============================================================================
**	Parametres:
**		- @pattern: motif complet, incluant chemin relatif.
**		- @count:   pointeur pour stocker le nombre de résultats.
**
**	Processus:
**		1. Séparer pattern en dir et pat via split_dir_pattern().
**		2. Appeler process_collect(dir, pat, count).
**
**	Retour:
**		Tableau de chemins correspondants ou NULL.
*/
char	**collect_matches(char *pattern, int *count)
{
	char	*dir;
	char	*pat;

	split_dir_pattern(pattern, &dir, &pat);
	return (process_collect(dir, pat, count));
}
