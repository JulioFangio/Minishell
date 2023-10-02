/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:31 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/02 18:33:16 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	unset_env(char **arg, t_data *data, int	i)
{
	t_env	*env;
	t_env	*tmp;

	env = data->env;
	if ()
}

int	make_unset(char **arg, t_data *data)
{
	int	i;

	i = 1;
	if (!(arg[i]))
		return (0);
	while (arg[i++])
	{
		unset_env(arg, data, i);
		unset_export(arg, data, i);
	}
	return (0);
}
