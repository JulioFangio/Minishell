/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:14:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/19 16:27:42 by juduval          ###   ########.fr       */
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

typedef struct s_cmd
{
	char			*type;
	char			*elem;
	struct s_cmd	*next;
}					t_cmd;

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
t_cmd	*ft_cmdnew(void);
t_cmd	*make_cmd(char **tab);
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
int		ft_lentab(char **tab);
char	*tronc_optn(char *tab);
int		check_quotes(char *line);
int		check_line(char *line);
int		how_long(char *line, char c);
char	*remake_line(char *line, int n, int l);
char	*remove_spaces(char *line, int i, int j);
char	*keep_spaces(char *line);
int		shorten(char *line);
char	*make_spaces(char *line, char *res);
int		check_end(char *line, int i, char c);
void	free_lst(t_cmd *cmd);
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
t_cmd	*get_cmd(char **tab);
t_cmd	*fill_list(t_cmd *cmd, char **tab, int i, int check);
void	fill_elem(t_cmd *cmd, char *tab, char *str);
void	fill_elem_tronc(t_cmd *cmd, char *tab, char *str);
int		scenario(char *tab, int check);
void	exec_scenario(t_cmd *cmd, char *tab, int nb);
void	exec_scenario_2(t_cmd *cmd, char *tab, int nb);
int		ft_optn(t_cmd *cmd, char *tab, int optn);
int		check_built(char *s1, const char *s2);
int		built_cmp(char *tab);
#endif