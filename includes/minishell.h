/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:38:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 17:23:11 by jaristil         ###   ########.fr       */
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

void	redir_exec(t_data *data, t_token *token);



//	signals
void	sigint_handler(int signum);
void	sigquit_handler(int signum);
void	redir(void);

//	other
int		start(char *line, t_data *data);
void	run_shell_loop(t_data *data);
char	**get_split(char *line);
char	*ft_readline(void);
char	*get_prompt(void);

//	utils
t_token	*ft_tokennew(void);
t_token	*make_cmd(char **tab);
t_token	*ft_tokenlast(t_token *cmd);
void	ft_tokenadd_back(t_token **cmd, t_token *new);
int		ft_lentab(char **tab);
char	*tronc_optn(char *tab);
int		check_quotes(char *line);
int		check_line(char *line);
int		how_long(char *line, char c);
char	*remake_line(char *line, int n, int l);
char	*remove_spaces(char *line, int i, int j);
char	*keep_spaces(char *line);
int		shorten(char *line);
char	*make_spaces(char *line, char *res, size_t i, int j);
int		check_end(char *line, int i, char c);
void	free_lst(t_token *cmd);
void	free_tab(char **tab);

//	elems + ext
int		is_redir(char *tab);
int		is_pipe(char *tab);
int		is_char(char *tab);
int		is_builtin(char *tab);
int		is_heredoc(char *tab);
int		whole_count(char *line);
int		ext_filename(char *tab);
int		ext_dollar(char *tab);
int		ext_tilde(char *tab);
int		ext_bracers(char *tab);

// cmd
t_token	*get_token(char **tab);
t_token	*fill_list(t_token *cmd, char **tab, int i, int check);
void	fill_elem(t_token *cmd, char *tab, char *str, int nb);
void	fill_elem_tronc(t_token *cmd, char *tab, char *str);
void	fill_elem_var(t_token *cmd, char *tab, char *str, int nb);
int		scenario(char *tab, int check);
void	exec_scenario(t_token *cmd, char *tab, int nb);
void	exec_scenario_2(t_token *cmd, char *tab, int nb);
int		ft_optn(t_token *cmd, char *tab, int optn);
int		check_built(char *s1, const char *s2);
int		built_cmp(char *tab);

//parse_line
int		parse_line(t_token *cmd);
int		parse_redir(t_token *cmd);
//split mini
char	**split_mini(char const *s, char c);

#endif