/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:02:57 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:12:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		exit_status;

	if (check_ac(ac) == -1)
	{
		ft_putstr_fd("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		return (EXIT_FAILURE);
	}
	pipex = init_pipex(ac, av);
	exit_status = fork_processes(pipex, av, envp);
	free_resources(pipex);
	return (exit_status);
}
