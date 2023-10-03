/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:03:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/03 16:54:08 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec_binary(char **arg, t_data *data, t_env *env)
{
	int		i_dir; //i[0]
	int		ret; // i[1]
	char	**bin_cmd;
	char	*path;

	i_dir = 0;
	ret = 0;
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5 != 0))
		env = env->next;
	if (!env || !env->next)
		// dois je ajouter un access ici?
		return (ft_child(arg[0], arg, data, env)); 
	bin_cmd = ft_split(env->value, ':');
	if (!bin_cmd)
		return (ft_exit(ERR_SPLIT), FAILURE); // ptrt exit_failure
	if (!arg[0] && !bin_cmd[0])
		return (FAILURE);
	path = 
}
