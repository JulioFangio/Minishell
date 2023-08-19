/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:14:21 by juduval           #+#    #+#             */
/*   Updated: 2023/08/14 18:10:31 by juduval          ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "libft/libft.h"

// signals
void    sigint_handler(int signum);
void    sigterm_handler(int signum);
void    sigquit_handler(int signum);
void    redir(void);

// other
void	run_shell_loop(void);
char	**get_split(void);
char	*ft_readline(void);
char	*get_prompt(void);

#endif