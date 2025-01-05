/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:50:53 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 20:50:32 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		exit_status;
	int		min_args;

	min_args = 5;
	if (ac > 1 && !ft_strcmp(av[1], HERE_DOC))
		min_args = 6;
	if (ac < min_args)
		error_file("pipex", "Us:./pipex h_doc ifl/LIM cmd1 cmd2 otfl");
	init_pipex(&pipex, ac, av);
	exit_status = execute_cmds(&pipex, av, env);
	free_pipex(&pipex);
	return (exit_status);
}
