/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:37:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/23 11:07:45 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_env	t_env;
typedef struct s_token	t_token;
typedef struct s_data	t_data;
typedef struct s_tronc	t_tronc;

typedef struct s_tronc
{
	char			*str;
	int				nb;
	struct s_tronc	*next;
}				t_tronc;

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
	t_token	*token;
	pid_t	pid;
	char	**tab;
	int		check_hdc;
	int		parent;
	int		result;
	int		in;
	int		out;
	int		check_child;
	int		fd_in;
	int		fd_out;
	int		exec;
	int		*pids;
	int		idx_pid;
	int		check;
	int		exit;
	int		end;
	int		hdcfd[2];
	int		pipefd[2];
}			t_data;

#endif