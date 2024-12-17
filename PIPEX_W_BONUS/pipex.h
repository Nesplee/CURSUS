/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:17:14 by dinguyen          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:56 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define HERE_DOC "here_doc"

# include "Libft/libft.h"
# include <stdio.h>

typedef struct s_pipex
{
	int		pipe_count;
	int		cmd_count;
	int		**pipes;
	int		infile;
	int		outfile;
	pid_t	*pids;
	int		here_doc;
	char	*limiter;
}		t_pipex;

//	COMMANDS
char	*find_command_path(char *cmd, char **envp);
void	handle_command_error(char **args, t_pipex *pipex, char *cmd_path);
void	execute_command(t_pipex *pipex, char *cmd, char **envp);

//	COMMANDS_UTILS
char	*try_paths(char **paths, char *cmd);
char	*construct_cmd_path(char *path, char *cmd);

//	FORK_UTILS
int		fork_processes(t_pipex *pipex, char **av, char **envp);

//	PARSING
int		check_ac(int ac);
int		open_files(t_pipex *pipex, char **av);
t_pipex	*init_pipex(int ac, char **av);

//	PROCESS
void	execute_first_command(t_pipex *pipex, char **av, char **envp);
void	execute_second_command(t_pipex *pipex, char **av, char **envp);
void	execute_middle_commands(t_pipex *pipex, char **av, char **envp, int i);

//	PROCESS_UTILS
void	handle_fork_error(t_pipex *pipex);
int		get_exit_status(int status, t_pipex *pipex);

//	UTILS
void	free_double_ptr(char **ptr);
void	free_resources(t_pipex *pipex);
void	create_pipes(t_pipex *pipex);
void	close_all_pipes(t_pipex *pipex);
int		init_memory(t_pipex *pipex);

//	HERE_DOC
int		handle_here_doc(char *limiter, int write_fd);

#endif
