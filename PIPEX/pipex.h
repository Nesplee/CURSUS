/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:06:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/08 14:36:18 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <stdio.h>

# define ERR_ARGS "Error: Invalid number of arguments\n"
# define ERR_PIPE "Error: Pipe failed\n"
# define ERR_FORK "Error: Fork failed\n"
# define ERR_CMD "Error: Command not fount\n"
# define ERR_FILE "Error: File error\n"
# define ERR_MEM "Error: Memory allocation failed\n"
# define ERR_PERM "Error: Permission denied\n"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

//	PARSE
char	**parse_cmds(const char *cmd);
//	PATHS
char	*find_command_from_path(char *cmd, char **env);
//	UTILS
void	free_array(char **arr);
void	error_exit(char *msg);
void	close_fds(int fd1, int fd2);

#endif
