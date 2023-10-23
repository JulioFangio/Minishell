/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:38:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/23 12:36:41 by juduval          ###   ########.fr       */
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

# define CHILD 1
# define PARENT 0

# define NO_ARG 0
# define CMD 1
# define ARG 2
# define PIPE 3 // |
# define CHEVRON 4 // >
# define OPEN_CHEVRON 5 // <
# define DOUBLE_CHEVRON 6 // >>
# define HERE_DOC 7 // <<

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define ERR "Error\n"
# define ERR_ARG "Invalid numbers of aguments\n"
# define ERR_INPUT_ARG "The argument is not valid"
# define ERR_ENV "Environnement error\n"
# define ERR_DIR "is a directory\n"
# define ERR_OPEN "No such file or directory\n"
# define ERR_PATH  "Failed to find path\n"
# define ERR_CMD "Command not found\n"
# define ERR_PERM "Permission Denied\n"
# define ERR_MALLOC	"Failed to allocate memory\n"
# define ERR_DUP "Failed to duplicate\n"
# define ERR_SPLIT "Failed to split command\n"
# define ERR_HOME "Failed to set HOME\n"

// ifndef ? comme buffer size GNL? ASK VERIFICATION
# ifndef B_SIZE
#  define B_SIZE 1024
# endif

# ifndef MAX_PATH
#  define MAX_PATH 1024
# endif


		/// -- EXEC_MINISHELL -- ///

/// BUILT_IN
// cd.c
int		new_oldpath(t_env *env);
int		new_path(t_env *env);
int		handle_directory_change(int directory, t_env *env);
int		make_cd(t_data *data, char **arg, t_env *env);
// cd_utils.c
char	*get_path(t_env *env, char *var, size_t len);
char	*get_oldpwd_path(char *path, t_env *env);
// pwd.c
int		make_pwd(t_data *data, t_env *env);
// echo.c
int		is_echo(char *line);
int		handle_echo_options(char **arg, int *cur_pos, int flags);
int		make_echo(t_data *data, char **arg);
// exit.c
int		str_isnum(char *str);
int		make_exit(t_data *data, char **cmd);
// env.c
int		make_env(t_data *data, t_env *env);
// unset.c
int		make_unset(t_data *data, char **cmd);
// export.c
int		make_export(t_data *data, char **cmd);
void	fill_env(t_data *data, t_env *env, char *arg);
t_env	*ft_env_new(char *arg);
void	ft_env_add_back(t_env **env, t_env *new);

		/// ENV
// getenv.c
int		is_env(char *env);
int		len_var_env(char *env);
char	*extract_env_value(char *env);
int		config_env_char_name(int c);
// getenv_bis.c
int		update_env(char *arg, t_env *env);
char	*extract_name_env(char *dest, char *src);
// setenv.c
size_t	env_len(t_env *env);
char	*env_malloc(t_env *env);
void	set_env(t_data *data, char **env);
// doenv.c
char	*dup_env(t_env *env);
int		env_add_value_to_list(char *value, t_env *env);

		/// EXEC
// exec_builtin.c
int		is_builtin(char *cmd);
int		exec_builtin(t_data *data, char **cmd, t_token *token);
// exec_pipe.c
void	do_pipe(t_data *data);
// exec_heredoc.c
char	*strcpy_heredoc(char *dest, const char *src);
char	*strjoin_heredoc(char *s1, char *s2);
char	*get_input_heredoc(char *limiter);
void	open_heredoc(t_data *data);
void	redir_heredoc(t_data *data, t_token *token);
// exec_cmd.c
void	exec_command(t_data *data);
// exec_bin.c
int		child_process(char *path, char **arg, t_data *data, t_env *env);
char	*child_dir(char *bin_cmd, char *cmd);
int		exec_bin(char **arg, t_data *data, t_env *env);
// start_exec.c
void	exec_redir(t_data *data);
void	launch_minishell(t_data *data);

		/// UTILS
// token.c
t_token	*get_prev_token(t_token *token, int prev);
int		token_is_pipe(t_token *token);
int		check_token(t_token *token, int type);
int		is_def_type(t_token *token, int type);
t_token	*iter_token_cmd(t_token *token, int iter);
// free.c
void	free_env(t_env **env);
void	free_tab(char **tab);
void	free_tronc(t_tronc *tronc);
// void	free_tab_2(char **tab, t_token *token);
void	free_token(t_token *token);
void	free_and_close_data(t_data *data, int nb);
void	free_env_unset(t_data *data, t_env *env);
void	free_data(t_data *data);
// child.c
void	clean_child_process(t_data *data, t_env *env, char *path, char **arg);
int		ret_child(char **env_tab, char *path, int result);
char	*strjoin_path(const char *s1, const char *s2);
// error.c
void	ft_exit(char *error);
void	error_cd(char **args);
int		child_error(char *path);
// tab.c
char	**token_to_tab(t_token *token, char **tab);
char	**token_cmd_to_tab(t_token *token);
size_t	tab_size(char **tab);
// fd.c
void	ft_close_fd(int fd);
void	ft_close_all_fd(t_data *data);
void	reset_to_initial_fd(t_data *data);

		/// -- PARSING_MINISHELL -- ///

//Signals
void	sigint_handler(int signum);
void	sigquit_handler(int signum);
void	sigquit_handler_hd(int signum);
void	sigint_handler_hd(int signum);
void	redir_hd(t_data *data);
void	redir(t_data *data);

//Token
t_token	*ft_tokennew(void);
t_token	*make_cmd(char **tab);
t_token	*ft_tokenlast(t_token *cmd);
void	ft_tokenadd_back(t_token **cmd, t_token *new);

//Troncate and expand
t_tronc	*ft_trclast(t_tronc *tmp);
t_tronc	*ft_troncnew(char *str);
void	ft_trc_add_back(t_tronc **tronc, t_tronc *new);
char	*tronc_optn(t_data *data, char *tab, int nb);
char	*troncate(char *str);
char	*check_for_var(t_data *data, char *tronc, int nb);
char	*extract_var(t_data *data, char *tronc, char *var);
char	*get_var(char *tronc);
void	get_new_line(char *res, char *tronc, char *gvar, int lv);
char	*pick_env(t_data *data, char *tab);

//Parse
int		ft_lentab(char **tab);
int		check_quotes(char *line);
int		check_line(char *line);
int		how_long(char *line, char c, int count, size_t i);
char	*remake_line(char *line, int n, int l);
char	*make_spaces(char *line, char *res, size_t i, int j);
int		check_end(char *line, int i, char c);
int		skip_quotes(char *line, size_t i);
void	print_err_msg(char c);
int		whole_count(char *line);

//Elems
int		is_redir(char *tab);
int		is_pipe(char *tab);
int		is_char(char *tab);
int		is_a_builtin(char *tab);
int		is_heredoc(char *tab);

//Command
int		start(char *line, t_data *data);
void	run_shell_loop(t_data *data);
char	**get_split(char *line);
char	*ft_readline(void);
char	*get_prompt(void);
void	get_token(t_data *data);
void	fill_list(t_data *data, int check);
void	fill_elem(t_token *cmd, char *tab, int nb);
void	fill_elem_tronc(t_data *data, t_token *cmd, char *tab, int nb);
void	fill_elem_var(t_data *data, t_token *cmd, char *tab, int nb);
void	fill_elem_redir(t_token *cmd, char *tab);
int		scenario(char *tab, int check);
void	exec_scenario(t_data *data, t_token *cmd, char *tab, int nb);
int		ft_optn(t_token *cmd, char *tab, int optn);
int		check_built(char *s1, const char *s2);
int		built_cmp(char *tab);

//Parse_line
t_data	*recuperate_data(t_data *data);
int		parse_line(t_data *data);
int		parse_first_token(t_token *token);
int		find_intruder(t_token *token, char c);
int		parse_heredoc(t_token *token);
int		parse_pipe(t_token *cmd);
int		parse_pipe_while(t_token *cmd);
int		parse_redir(t_token *cmd);
void	check_heredoc(t_data *data);
void	create_heredoc(t_data *data, t_token *token);
void	get_out_of_heredoc(t_data *data, t_token *token, char *line);
int		is_there_a_pipe(t_token *token);

//Split mini
int		ft_isseparator(char c, char sep);
int		ft_countwords(const char *str, char sep, int i, int count);
char	**split_mini(char const *s, char c);

#endif