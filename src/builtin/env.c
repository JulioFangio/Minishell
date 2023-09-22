/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:33:02 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/08 15:43:14 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*displays the values of environment variables
stored in a chained list of t_env structures*/
int	make_env(t_env *env)
{
	while (env)
	{
		ft_putendl_fd(env->value, STDOUT_FILENO);
		env = env->next;
	}
	return (SUCCESS);
}
