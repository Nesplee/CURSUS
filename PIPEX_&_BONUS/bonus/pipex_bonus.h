/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:17:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/13 19:58:01 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <stdio.h>

# define ERR_ARGS "Error: Invalid number of arguments\n"
# define ERR_PIPE "Error: Pipe failed\n"
# define ERR_FORK "Error: Fork failed\n"
# define ERR_CMD "Error: Command not fount\n"
# define ERR_FILE "Error: File error\n"
# define ERR_MEM "Error: Memory allocation failed\n"
# define ERR_PERM "Error: Permission denied\n"
# define ERR_HEREDOC "Error: Here_doc error\n"
# define HEREDOC "here_doc"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**env;
}	t_data;

//	HERE_DOC
int		is_here_doc(char *arg);
void	handle_here_doc(char *limiter, int *fd_in);
//	PARSE
char	**parse_cmds(const char *cmd);
//	PATHS
char	*find_command_from_path(char *cmd, char **env);
//	UTILS
void	free_array(char **arr);
void	error_exit(char *msg);
void	close_fds(int fd1, int fd2);

#endif
