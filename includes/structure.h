/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:37:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/26 16:39:36 by jaristil         ###   ########.fr       */
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
}					t_token;

typedef struct s_data
{
	t_env	*env;
	t_token	*token;
	t_token	*free_token;
	pid_t	pid;
	char	**tab;
	char	*hdcdoc;
	int		check_hdc;
	int		parent;
	int		result;
	int		check_child;
	int		fd_in;
	int		fd_out;
	int		exec;
	int		*pids;
	int		idx_pid;
	int		check;
	int		exit;
	int		err_redir;
	int		end;
	int		hdcfd;
	int		pipefd[2];
}			t_data;

#endif