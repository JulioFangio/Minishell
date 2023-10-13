/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:37:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 20:56:17 by juduval          ###   ########.fr       */
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
	int				fd;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data
{
	t_env	*env;
	t_env	*export;
	t_token	*token;
	char	**tab;
	pid_t	pid;
	int		check_hdc;
	int		parent;
	int		result;
	int		in;
	int		out;
	int		pipe_in;
	int		pipe_out;
	int		fd_in;
	int		fd_out;
	int		exec;
	int		err_redir;
	int		exit;
	int		end;
}			t_data;

#endif