/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:37:38 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/22 16:16:51 by jaristil         ###   ########.fr       */
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

// typedef struct s_token
// {
// 	char			*str;
// 	int				type;
// 	struct s_token	*next;
// 	struct s_token	*prev;
// }					t_token;

typedef struct s_token
{
	char			*type;
	char			*elem;
	int				code;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	t_env	*env;
	t_env	*export;
	t_token	*token;
	int		parent;
	int		result;
	int		pipe_in;
	int		pipe_out;
	int		exec;
	int		exit;
	int		end;
}			t_data;

#endif