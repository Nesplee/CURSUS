/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:17:14 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 13:01:54 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>

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
void		handle_command_error(char **args, t_pipex *pipex, char *cmd_path);

void		execute_command(t_pipex *pipex, char *cmd, char **envp);
//	COMMANDS_UTILS
char		*try_paths(char **paths, char *cmd);
char		*construct_cmd_path(char *path, char *cmd);

//	PARSING
int			check_ac(int ac);
int			open_files(t_pipex *pipex, char **av);
int			setup_pipes(t_pipex *pipex);
t_pipex		*init_pipex(int ac, char **av);

//	PROCESS
void		execute_first_command(t_pipex *pipex, char **av, char **envp);
void		execute_second_command(t_pipex *pipex, char **av, char **envp);

//	PROCESS_UTILS
int			fork_processes(t_pipex *pipex, char **av, char **envp);

//	UTILS
void		close_pipes(t_pipex *pipex);
void		free_double_ptr(char **ptr);
void		free_resources(t_pipex *pipex);

#endif
