/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:17:14 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/16 15:30:00 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>
c
typedef struct s_pipex
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
}			t_pipex;

//	COMMANDS
char		*find_command_path(char *cmd, char **envp);
void		execute_command(t_pipex *pipex, char *cmd, char **envp);

//	PARSING
int			check_ac(int ac);
int			open_files(t_pipex *pipex, char **av);
int			setup_pipes(t_pipex *pipex);
t_pipex		*init_pipex(int ac, char **av);

//	PROCESSES
void		fork_processes(t_pipex *pipex, char **av, char **envp);

//	UTILS
void		close_pipes(t_pipex *pipex);
void		free_double_ptr(char **ptr);

#endif
