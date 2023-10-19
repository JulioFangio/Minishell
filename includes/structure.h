/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:37:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/19 14:34:59 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_env	t_env;
typedef struct s_token	t_token;
typedef struct s_data	t_data;

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_token
{	
	char			*str;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data
{
	t_env	*env;
	t_env	*export;
	t_token	*token;
	t_token	*token_forfree;
	char	**tab;
	pid_t	pid;
	int		check_hdc;
	int		parent;
	int		result;
	int		in;
	int		out;
	// int		pipe_in;
	// int		pipe_out;
	int		error_code;
	int		fd_in;
	int		fd_out;
	int		exec;
	int		*pids;
	int		idx_pid;
	int		check;
	int		err_redir;
	int		exit;
	int		end;
	int		pipefd[2];
}			t_data;

#endif