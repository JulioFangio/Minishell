/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:14:21 by juduval           #+#    #+#             */
/*   Updated: 2023/09/10 18:41:13 by marvin           ###   ########.fr       */
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

typedef struct			s_cmd
{
	char			*type;
	char			*elem;
	struct s_cmd	*next;
}						t_cmd;

//	signals
void	sigint_handler(int signum);
void	sigquit_handler(int signum);
int		redir(void);

//	other
void	run_shell_loop(void);
char	**get_split(void);
char	*ft_readline(void);
char	*get_prompt(void);
char	*remake_line(char *line, int n, int l);

//	utils
t_cmd	*ft_cmdnew(void);
t_cmd	*make_cmd(char **tab);
t_cmd	*ft_cmdlast(t_cmd *cmd);
void	ft_cmdadd_back(t_cmd **cmd, t_cmd *new);
int		ft_lentab(char **tab);
char	*tronc_optn(char *tab);
int		check_dquotes(char *line);
int		check_quotes(char *line);
int		check_line(char *line);
int		how_long(char *line, char c);

//	elems + ext
int		is_cmd(t_cmd *cmd, char *tab);
int		is_option(t_cmd *cmd, char *tab);
int		is_redir(t_cmd *cmd, char *tab);
int		is_pipe(t_cmd *cmd, char *tab);
int		is_char(t_cmd *cmd, char *tab, char *str);
int		is_arg(t_cmd *cmd, char *tab);
int		is_builtin(t_cmd*cmd, char *tab);
int		is_esper(t_cmd *cmd, char *tab);
int		whole_count(char *line);
int		ext_filename(t_cmd *cmd, char *tab);
int		dollar(t_cmd *cmd, char *tab);
int		ext_tilde(t_cmd *cmd, char *tab);
int		ext_bracers(t_cmd *cmd, char *tab);

// cmd
t_cmd	*get_cmd(char **tab);
int		parse_split(t_cmd *cmd, char *tab, int check);
int		parse_split_2(t_cmd *cmd, char *tab);

#endif