/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:16:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/05 20:48:27 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>

//	BONUS
# define HERE_DOC "here_doc"
//	DESCRIPTEURS STANDARDS
# define STDIN 0
# define STDOUT 1
# define STDERR 2
//	INDEX DES FICHIERS
# define INFILE 0
# define OUTFILE 1
//	MODES DES PIPES
# define READ 0
# define WRITE 1

typedef struct s_pipex
{
	//	CONFIGURATION
	int		cmd_count;
	int		pipe_count;
	//	CONNEXIONS
	int		**pipes;
	pid_t	*pids;
	//	ENTREE/SORTIE
	int		infile;
	int		outfile;
	//	BONUS
	int		here_doc;
	char	*limiter;
}		t_pipex;

//	EXECVE
int		wait_children(t_pipex *p);
void	child_process(t_pipex *p, int index, char **av, char **env);
//	FORK
int		execute_cmds(t_pipex *p, char **av, char **env);
//	HERE_DOC
int		handle_here_doc(t_pipex *p);
//	INIT
void	init_pipex(t_pipex *p, int ac, char **av);
//	PARSE
char	**parse_cmds(const char *cmd);
//	PATHS
char	*find_command_from_path(char *cmd, char **env);
//	PIPES
void	create_pipes(t_pipex *p);
void	close_pipes(t_pipex *p);
//	UTILS_ERROR
int		get_exit_status(int status);
void	cleanup_cmd(char **cmd_args, char *cmd_path);
void	error_system(char *msg);
void	error_cmd(char *cmd, char *detail);
void	error_file(char *file, char *detail);
//	UTILS_FREE
void	free_pipex(t_pipex *pipex);

#endif
