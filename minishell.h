/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:14:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/22 16:02:34 by juduval          ###   ########.fr       */
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
# include <stdint.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_token
{
	char			*type;
	char			*elem;
	int				code;
	struct s_token	*next;
}					t_token;

//	signals
void	sigint_handler(int signum);
void	sigquit_handler(int signum);
void	redir(void);

//	other
int		start(char *line);
void	run_shell_loop(void);
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