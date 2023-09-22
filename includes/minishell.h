/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:38:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 14:41:50 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdint.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "structure.h"

# define SUCCESS 0
# define FAILURE 1

# define NO_ARG 0
# define CMD 1
# define ARG 2
# define PIPE 3 // |
# define CHEVRON 4 // >
# define OPEN_CHEVRON 5 // <
# define DOUBLE_CHEVRON 6 // >>
# define DOUBLE_INPUT 7 // <<
# define END 8

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERR "Error\n"
# define ERR_ARG "Invalid numbers of aguments\n"
# define ERR_INPUT_ARG "The argument is not valid"
# define ERR_ENV "Environnement error\n"
# define ERR_OPEN "No such file or directory\n"
# define ERR_PATH  "Failed to find path\n"
# define ERR_MALLOC	"Failed to allocate memory\n"
# define ERR_DUP "Failed to duplicate\n"
# define ERR_SPLIT "Failed to split command\n"
# define ERR_HOME "Failed to set HOME\n"

# define B_SIZE 1024
# define MAX_PATH 1024

		// BUILT_IN
// cd.c
int		new_oldpath(t_env *env);
int		new_path(t_env *env);
int		handle_directory_change(int directory, t_env *env);
int		make_cd(char **arg, t_env *env);
// cd_utils.c
char	*get_path(t_env *env, char *var, size_t len);
char	*get_oldpwd_path(char *path, t_env *env);

// pwd.c
int		make_pwd(t_env *env);

// echo.c
int		is_echo(char *line);
int		handle_echo_options(char **arg, int *cur_pos, int flags);
int		make_echo(char **arg);

// exit.c
int		str_isnum(char *str);
int		make_exit(t_data *data, char **cmd);
// env.c
int		make_env(t_env *env);

// unset.c
// export.c

		// ENV
// getenv.c
int		is_env(char *env);
int		len_var_env(char *env);
char	*extract_env_value(char *env);
char	*get_env_value(char *arg, t_env *env);
int		config_env_char_name(int c);

// getenv_bis.c
int		update_env(char *arg, t_env *env);

// setenv.c
size_t	env_len(t_env *env);
char	*env_malloc(t_env *env);
void	set_env(t_data *data, char **env);
t_env	*export_env(char *value);
char	*clean_env(char *to_find);

// doenv.c
void	bubble_sort_env(char **env_tab, int env_len);
void	putstr_env(char **env);
void	display_env(t_env *env, t_env *export);
char	*dup_env(char *ptr_env, t_env *env);
int		env_add_value_to_list(char *value, t_env *env);

// env.c
char	*extract_name_env(char *dest, char *src);
		// EXEC
// builtin.c
int		is_builtin(char *cmd);
int		exec_builtin(t_data *data, char **cmd, t_token *token);

// exec.c
void	exec_command(t_data *data, t_token *token);
char	**token_cmd_to_tab(t_token *token);

// exec_utils.c
char	**token_to_tab(t_token *token, char **tab);


		// UTILS
// free.c
void	free_env(t_env *env);
void	free_tab(char **tab);
void	*free_token(t_token *token);

// error.c
void	ft_exit(char *error);

// utils.c
size_t	tab_size(char **tab);

		// MAIN
// main.c
void	redir_exec(t_data *data, t_token *token);

#endif