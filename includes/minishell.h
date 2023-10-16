/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:38:32 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/16 19:49:12 by jaristil         ###   ########.fr       */
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
// int		unset_export(char **arg, t_data *data, int i);
// int		unset_env(char **arg, t_data *data, int i);
int		make_unset(t_data *data, char **cmd);
// unset_utils.c
int		len_to_equal(char *env);
char	*ft_strchr_minishell(const char *str, char c);
int		comp_len_val(char *arg, char *value);
void	free_export(t_data *data, t_env *export);
int		remove_export(t_data *data, char **arg, int i);
// export.c
int		make_export(t_data *data, char **cmd);

		/// ENV
// getenv.c
int		is_env(char *env);
int		len_var_env(char *env);
char	*extract_env_value(char *env);
char	*get_env_value(char *arg, t_env *env);
int		config_env_char_name(int c);
// getenv_bis.c
int		update_env(char *arg, t_env *env);
char	*extract_name_env(char *dest, char *src);
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
//char	*dup_env(char *ptr_env, t_env *env);
char	*dup_env(t_env *env);
int		env_add_value_to_list(char *value, t_env *env);

		/// EXEC
// exec_builtin.c
int		is_builtin(char *cmd);
int		exec_builtin(t_data *data, char **cmd, t_token *token);
// exec_pipe.c
void	do_pipe(t_data *data);
// exec_redir
void	do_redir(t_data *data);
void	redir_chev(t_data *dat, t_token *token);
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
void	free_env(t_env *env);
void	free_tab(char **tab);
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

//	signals
void	sigint_handler(int signum);
void	sigquit_handler(int signum);
void	sigquit_handler_hd(int signum);
void	sigint_handler_hd(int signum);
void	redir_hd(t_data *data);
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
char	*tronc_optn(t_data *data, char *tab, int nb);
int		check_quotes(char *line);
int		check_line(char *line);
int		how_long(char *line, char c, int count, size_t i);
char	*remake_line(char *line, int n, int l);
char	*remove_spaces(char *line, int i, int j);
char	*keep_spaces(char *line);
int		shorten(char *line);
char	*make_spaces(char *line, char *res, size_t i, int j);
int		check_end(char *line, int i, char c);
char	*pick_env(t_data *data, char *tab);
char	*check_for_var(t_data *data, char *tronc, int nb);
char	*get_new_line(char *res, char *tronc, char *gvar, int lv);
char	*extract_var(t_data *data, char *tronc, char *var);
char	*get_var(char *tronc);
int		skip_quotes(char *line, size_t i);
char	*ft_dupquotes(const char *str, char q);
// void	free_tab(char **tab);

//	elems + ext
int		is_redir(char *tab);
int		is_pipe(char *tab);
int		is_char(char *tab);
int		is_a_builtin(char *tab);
int		is_heredoc(char *tab);
int		whole_count(char *line);
int		ext_filename(char *tab);
int		ext_dollar(char *tab);
int		ext_tilde(char *tab);
int		ext_bracers(char *tab);

// cmd
void	get_token(t_data *data);
void	fill_list(t_data *data, int check);
void	fill_elem(t_token *cmd, char *tab, int nb);
void	fill_elem_tronc(t_data *data, t_token *cmd, char *tab);
void	fill_elem_var(t_data *data, t_token *cmd, char *tab, int nb);
void	fill_elem_redir(t_token *cmd, char *tab);
int		scenario(char *tab, int check);
void	exec_scenario(t_data *data, t_token *cmd, char *tab, int nb);
int		ft_optn(t_token *cmd, char *tab, int optn);
int		check_built(char *s1, const char *s2);
int		built_cmp(char *tab);

//parse_line
int		parse_line(t_data *data);
int		parse_ls(t_data *data, int check_ls);
int		parse_first_token(t_token *token);
int		find_intruder(t_token *token, char c);
int		parse_heredoc(t_token *token);
int		parse_pipe(t_token *cmd);
int		parse_pipe_while(t_token *cmd);
int		parse_redir(t_token *cmd);
t_data	*recuperate_data(t_data *data);
void	check_heredoc(t_data *data);
char	*get_prompt_heredoc(void);
int		is_there_a_pipe(t_token *token);

//split mini
char	**split_mini(char const *s, char c);

#endif