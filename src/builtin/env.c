/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:33:02 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/23 18:16:34 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*displays the values of environment variables
stored in a chained list of t_env structures*/
int	make_env(t_data *data, t_env *env)
{

	if (data->fd_out == -1)
		data->fd_out = 1;
	while (env)
	{
		ft_putendl_fd(env->value, data->fd_out);
		env = env->next;
	}
	return (SUCCESS);
}
