/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:33:02 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/17 15:27:39 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*displays the values of environment variables
stored in a chained list of t_env structures*/
int	make_env(t_data *data, t_env *env)
{
	int	fd;

	if (data->fd_out == -1)
		fd = 1;
	else
		fd = data->fd_out;
	while (env)
	{
		ft_putendl_fd(env->value, fd);
		env = env->next;
	}
	return (SUCCESS);
}
