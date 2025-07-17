/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:23:23 by dinguyen          #+#    #+#             */
/*   Updated: 2025/06/06 01:38:14 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../LIBFT/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <termios.h>

extern volatile sig_atomic_t	g_signal;

/* ======================================================== */
/* 					MESSAGES D'ERREURS						*/
/*															*/
/* Ces définitions permettent de gérer les codes de retour	*/
/* et les descripteurs de fichiers standards du shell.		*/
/* Utilisés pour la gestion des erreurs et les redirections	*/
/* ======================================================== */

# define EXIT_SUCCESS 0		// Valeur de retour en cas de succès
# define EXIT_FAILURE 1		// Valeur de retour en cas d'échec
# define STDIN  0			// Entrée standard
# define STDOUT 1			// Sortie standard
# define STDERR 2			// Sortie d'erreur

/* ======================================================== */
/* 						COULEURS							*/
/* ======================================================== */

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define ORANGE		"\033[38;5;208m"
# define PURPLE		"\033[38;5;129m"
# define BOLD		"\033[1m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

/* ======================================================== */
/* 						ENUMERATIONS						*/
/* ======================================================== */

//	GESTION DES TYPES DE QUOTES
typedef enum e_quote_type
{
	NO_QUOTE,			// pas de quotes	-> echo hello
	SINGLE_QUOTE,		// quotes simples	-> echo 'hello $USER' (no expanse)
	DOUBLE_QUOTE,		// quotes doubles	-> echo "hello $USER" (w/ expanse)
}		t_quote_type;

//	GESTION DES REDIRS
typedef enum e_redirection_type
{
	REDIR_INPUT,		// redirection d'entrée :	<
	REDIR_OUTPUT,		// redirection de sortie :	>
	REDIR_APPEND,		// mode append :			>>
	REDIR_HEREDOC,		// mode heredoc :			<<
}		t_redirection_type;

//	GESTION DES OPERATEURS
typedef enum e_operator_type
{
	OP_PIPE,			// pipe	-> connecte la sortie à l'entrée
	OP_AND,				// and	-> exécute si précédent réussi
	OP_OR,				// ou	-> exécute si précédent échoué
	OP_LPAR,			// parenthèse gauche -> groupe de commandes
	OP_RPAR,			// parenthèse droite -> groupe de commandes
}		t_operator_type;

//	GESTION DES BUILTINS
typedef enum e_builtin_cmd
{
	BI_NONE = -1,		// commande introuvable
	BI_ECHO,			// commande built-in echo	-> affiche du texte
	BI_CD,				// commande built-in cd		-> change de repertoire
	BI_PWD,				// commande built-in pwd	-> repertoire courant
	BI_EXPORT,			// commande built-in export	-> définit les var d'env
	BI_UNSET,			// commande built-in unset	-> supp les var d'env
	BI_ENV,				// commande built-in env	-> affiche les var d'env
	BI_EXIT,			// commande built-in exit	-> quitte le shell
}		t_builtin_cmd;

//	GESTION DES ERREURS
typedef enum e_error
{
	SUCCESS,			// execution réussie
	ERR_SYNTAX,			// erreur de syntaxe
	ERR_CMD_NOT_FOUND,	// commande introuvable
	ERR_PERMISSION,		// droits insuffisants
	ERR_MEMORY,			// erreur allocation
	ERR_PIPE,			// erreur de pipe
	ERR_FORK,			// erreur de fork
	ERR_FILE_NOT_FOUND,	// fichier introuvable
	ERR_QUOTE_UNCLOSED,	// guillemet non fermé
	ERR_PIPE_SYNTAX,	// erreur syntaxe pipe
	ERR_VAR_NOT_FOUND,	// variable introuvable
	ERR_VAR_SYNTAX,		// variable incorrecte
	ERR_HEREDOC_EOF,	// EOF dans heredoc
	ERR_PAREN_MISMATCH,	// parenthèse non fermée
	ERR_PAREN_EMPTY,	// parenthèse vide
}	t_error;

typedef enum e_signal
{
	SIG_CTRL_C,			// interruption (^C)
	SIG_CTRL_D,			// EOF (^D)
	SIG_CTRL_SLASH,		// Exit (^\)
}		t_signal;

//	GESTION GENERALE DES TOKENS
typedef enum e_token_type
{
	T_WORD,				// mot simple
	T_OPERATOR,			// opérateur
	T_REDIR,			// redirection
	T_VAR,				// variable
	T_EOF,				// fin de fichier
}		t_token_type;

/* ======================================================== */
/* 						STRUCTURES							*/
/* ======================================================== */

typedef struct s_redir
{
	t_redirection_type	type;		// type de redirection
	char				*file;		// fichier si redirection
	int					fd;
}		t_redir;

typedef struct s_command		t_command;
typedef struct s_command
{
	t_redir			**redirs;		// tableau de redirections
	t_builtin_cmd	builtin_id;		// ID si commande built-in
	char			*name;			// nom de la commande
	char			**args;			// arguments de la commande
	int				arg_count;		// nombre d'arguments
	int				redir_count;	// nombre de redirections
	int				is_builtin;		// flag si built-in
	pid_t			pid;			// pid du processus
	int				pipe_fd[2];		// file descriptors du pipe
	int				status;			// code de retour
	t_command		**sub_commands;	// commandes entre parentheses
	t_operator_type	*sub_ops;		// type d'operateur
	int				sub_op_count;	// nombre d'opérateur
	int				is_subshell;	// flag si parentheses
}		t_command;

typedef struct s_token
{
	t_token_type		type;		// type du token
	t_quote_type		quote;		// type de guillemet
	t_redirection_type	redir;		// type de redirection
	t_operator_type		ope;		// type d'opérateur
	char				*value;		// valeur du token
	int					merging;

}		t_token;

typedef struct s_lexer
{
	char		*input;				// ligne de commande brut
	int			position;			// position courante dans l'input
	t_token		**tokens;			// tableau de tokens
	int			token_count;		// nombre de tokens
}		t_lexer;

typedef struct s_parser
{
	t_token		**tokens;			// tokens à analyser
	int			current;			// index du token courant
	t_command	**commands;			// tableau de commandes
	int			cmd_count;			// nombre de commandes
}		t_parser;

typedef struct s_shell
{
	t_token		**tokens;			// tokens de la cmmande courante
	t_command	**commands;			// commandes à exécuter
	t_lexer		*lexer;				// analyseur lexical
	t_parser	*parser;			// analyseur syntaxique
	char		**env;				// variables d'environnement
	char		*cwd;				// repertoire courant
	int			exit_status;		// code de retour
	int			running;			// état du shell
	int			signal_received;	// signal reçu
	int			in_heredoc;			// flag heredoc en cours
}		t_shell;

/* ======================================================== */
/* 						PROTOTYPES							*/
/* ======================================================== */

/* ==================================================== */
/*				1. INITIALISATION						*/
/* ==================================================== */
//			INIT_GLOBAL
t_shell					*init_shell(char **env);
//			INIT_LEXING
t_token					*init_token(void);
t_lexer					*init_lexer(char *input);
//			INIT_OPERATORS
t_redir					*init_redir(void);
//			INIT_PARSING
t_parser				*init_parser(void);
t_command				*init_command(void);

/* ==================================================== */
/*				2. LEXING								*/
/* ==================================================== */
//			TOKEN_OPERATOR
int						handle_operator(t_lexer *lexer);
//			TOKEN_QUOTE
int						handle_quote(t_lexer *lexer);
//			TOKEN_REDIR
int						handle_redirection(t_lexer *lexer);
//			TOKEN_VAR
int						handle_variable(t_lexer *lexer);
//			TOKEN_WORD
int						handle_word(t_lexer *lexer);
//			TOKENIZATION
t_token					**tokenize(char *input);

/* ==================================================== */
/*				3.CHECKING								*/
/* ==================================================== */
//		VERIFY_OPERATORS
int						check_operators_syntax(t_lexer *lexer);
//		VERIFY_PARENTHESES
int						check_parentheses_syntax(t_lexer *lexer);
//		VERIFY_QUOTES
int						check_quotes_syntax(t_lexer *lexer);
//		VERIFY_REDIRS
int						check_redirs_syntax(t_lexer *lexer);
//		VERIFY_VARIABLES
int						check_var_syntax(t_lexer *lexer);
//		VERIFY
int						check_syntax(t_lexer *lexer);

/* ==================================================== */
/*				4.PARSING								*/
/* ==================================================== */
//		PARSER_COMMANDS
t_command				*parse_command(t_parser *parser);
//		PARSER_LOGICALS
int						count_logicals(t_token **tokens);
t_command				**parse_logicals(t_parser *parser, int logical_count);
//		PARSER_PARENTHESES
t_command				*parse_group_or_command(t_parser *prs);
//		PARSER_PIPES
int						parse_pipes(t_parser *parser);
//		PARSER_REDIRS
int						parse_redirections(t_command *cmd, t_parser *parser);
//		PARSER
t_command				**parser(t_token **tokens);

/* ==================================================== */
/*				5.EXPANSION								*/
/* ==================================================== */
//		EXPAND_DQUOTES1
int						expand_var_in_dquotes(t_token *tok, char **env,
							int exit_status);
//		EXPAND_VARIABLES
char					*get_var_value(char *name, char **env);
int						replace_var_token(t_token *tok, char **env);
int						replace_exit_status(t_token *tok, int exit_status);
//		EXPAND_WILDCARDS1
char					**collect_matches(char *pattern, int *count);
//		EXPAND_WILDCARDS2
int						expand_wildcards(t_token ***tokens);
//		EXPANSION
int						expand_all(t_token **tokens, char **env,
							int exit_status);

/* ==================================================== */
/*				6.BUILTINS								*/
/* ==================================================== */
//		FT_CD
int						ft_cd(char **args, char **env);
//		FT_ECHO
int						ft_echo(char **args);
//		FT_ENV
int						ft_env(char **env);
//		FT_EXIT
int						ft_exit(t_shell *shell, char **args);
//		FT_EXPORT
int						ft_export(char **args, char ***env);
//		FT_PWD
int						ft_pwd(void);
//		FT_UNSET
int						ft_unset(char **args, char ***env);

/* ==================================================== */
/*				7.PROCESSING							*/
/* ==================================================== */
//		PROCESS_COMMAND_LINE
t_token					**get_tokens(t_shell *shell, char *input);
int						handle_line(t_shell *shell);
//		PROCESS_HEREDOC
int						handle_heredoc(t_redir *redir, char **env,
							int exit_status);
//		PROCESS_LOGICALS
int						process_logical(char *input, t_shell *shell);
//		PROCESS_REDIRECTIONS
int						setup_redirections(t_command *cmd, t_shell *shell);

//		PROCESS_SUBSHELLS
int						process_parentheses(char *input, t_shell *shell);

/* ==================================================== */
/*				8.EXECUTION								*/
/* ==================================================== */
//		EXEC_BUILTINS
int						execute_builtin_with_redir(t_command *cmd,
							t_shell *shell, char **env);
//		EXEC_EXTERNAL
int						execute_external_command(t_command *cmd, char **env);
//		EXEC_PATHS
char					*find_executable(char *cmd, char **env);
//		EXEC_PIPELINE
int						process_command_iteration(int idx, t_command **cmds,
							int *prev_fd, t_shell *shell);
int						execute_commands(t_command **cmds, t_shell *shell,
							char **env);
//		EXEC_SUBSHELLS
int						execute_subshell(t_command *cmd, t_shell *shell,
							char **env);
//		EXEC_COMMANDS
int						execute_command(t_command *cmd, t_shell *shell,
							char **env);
int						execute_single_line(char *line, t_shell *shell);

/* ==================================================== */
/*				9.UTILS									*/
/* ==================================================== */
//		FREE_COMMANDS
void					free_token(t_token *token);
void					free_command(t_command *command);
void					free_command_list(t_command **commands);
//		FREE_LEXER_PARSER
void					free_lexer(t_lexer *lexer);
void					free_parser(t_parser *parser);
//		FREE_SHELL
void					free_env(char **env);
void					free_shell(t_shell *shell);
//		UTILS_BUILTINS
int						ft_count_env(char **env);
int						ft_update_env(char *new_var, char ***env);
//		UTILS_EXECUTION
int						process_heredocs(t_command **cmds,
							t_shell *shell, char **envp);
int						spawn_pipeline(t_command **cmds, t_shell *shell);
int						collect_exit_status(t_shell *shell);
//		UTILS_LEXING
void					ft_skip_spaces(t_lexer *lexer);
void					add_token(t_lexer *lexer, t_token *token);
void					print_lexer_error(int error_type, char *token);
//		UTILS_PARSING
t_builtin_cmd			is_builtin(char *cmd_name);
int						count_args(t_token **tokens, int start);
void					free_args(char **args, int count);
t_command				**cleanup_parser(t_parser *parser);
void					cleanup_line(t_shell *shell, char *input,
							t_token **tokens, t_command **cmds);
//		UTILS_SIGNALS
void					signal_handler(int signo);
void					init_signals(void);
void					disable_flow_control(void);
void					update_shlvl(char ***env);
//		UTILS_WILDCARDS
void					split_dir_pattern(char *pattern,
							char **dir, char **pat);
int						add_match_prefixed(char ***lst, int *cnt,
							char *dir, char *name);

/* ==================================================== */
/*				10.DISPLAY								*/
/* ==================================================== */
//		DISPLAY1
void					dis_prompt_err(void);
void					dis_syntax_err_custom(char *msg);
void					dis_cmd_not_found_err(char *cmd);
void					dis_perm_err(char *path);
//		DISPLAY2
void					dis_no_file_err(char *path);
void					dis_memory_err(void);
void					dis_fork_err(void);
void					dis_pipe_err(void);
//		DISPLAY3
void					dis_var_syntax_err(char *token);
void					dis_heredoc_eof_err(void);
void					dis_paren_mismatch_err(void);
void					dis_paren_empty_err(void);
void					dis_is_directory_err(char *path);

t_token					**merge_adjacent_tokens(t_token **tokens);

#endif
