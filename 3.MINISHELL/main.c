/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:47:44 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/08 18:09:18 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;
	int		saved_stdin;
	int		ret;

	(void)argc;
	(void)argv;
	disable_flow_control();
	init_signals();
	saved_stdin = dup(STDIN_FILENO);
	shell = init_shell(envp);
	if (!shell)
		return (EXIT_FAILURE);
	while (handle_line(shell))
		dup2(saved_stdin, STDIN_FILENO);
	rl_clear_history();
	close(saved_stdin);
	ret = shell->exit_status;
	free_shell(shell);
	return (ret);
}
