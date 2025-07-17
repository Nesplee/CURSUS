/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:14:38 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 13:36:49 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/minishell.h"

volatile sig_atomic_t	g_signal = 0;

/*
** ============================================================================
**	signal_handler - Gestionnaire de SIGINT pour readline
** ============================================================================
**	Paramètres:
**		- @sig: code du signal reçu (inutilisé)
**
**	Processus:
**		1. Mettre à jour g_signal = SIG_CTRL_C.
**		2. Écrire un saut de ligne.
**		3. Réinitialiser et rafraîchir la ligne readline.
*/
void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		if (g_signal == 0)
			rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		if (g_signal == 0)
			return ;
		write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
		rl_replace_line("", 0);
		rl_on_new_line();
		if (g_signal == 0)
			rl_redisplay();
	}
}

/*
** ============================================================================
**	init_signals - Initialise les handlers de signaux pour le shell
** ============================================================================
**	Processus:
**		1. Désactiver la gestion automatique par readline.
**		2. Assigner signal_handler à SIGINT.
**		3. Ignorer SIGQUIT.
*/

void	init_signals(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

void	disable_flow_control(void)
{
	struct termios	term;

	if (tcgetattr(STDIN_FILENO, &term) == -1)
		return ;
	term.c_iflag &= ~(IXON | IXOFF);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static char	*compute_new_shlvl(char *entry)
{
	int		level;
	char	*new_lvl_str;
	char	*new_entry;

	level = ft_atoi(entry + ft_strlen("SHLVL="));
	level++;
	new_lvl_str = ft_itoa(level);
	if (!new_lvl_str)
		return (NULL);
	new_entry = ft_strjoin("SHLVL=", new_lvl_str);
	free(new_lvl_str);
	return (new_entry);
}

void	update_shlvl(char ***env)
{
	int		i;
	char	*new_entry;

	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], "SHLVL=", ft_strlen("SHLVL=")) == 0)
		{
			new_entry = compute_new_shlvl((*env)[i]);
			if (new_entry)
			{
				free((*env)[i]);
				(*env)[i] = new_entry;
			}
			return ;
		}
		i++;
	}
}
