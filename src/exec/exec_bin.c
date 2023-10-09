/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:03:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/08 19:50:42 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*struct signal jules avec exit_code? have to handle signal in child (cf tiff)*/
int	child_process(char *path, char **arg, t_data *data, t_env *env)
{
	int		result;
	char	*tmp;
	char	**env_tab;

	result = 0;
	data->pid = fork();
	if (data->pid == 0)
	{
		tmp = env_malloc(env);
		env_tab = ft_split(tmp, '\n');
		if (!env_tab)
			return (ft_exit(ERR_MALLOC), FAILURE);
		ft_memdel(tmp);
		if (ft_strchr(path, '/'))
			execve(path, arg, env_tab);
		result = ret_child(env_tab, path, result);
		clean_child_process(data, env, path, arg);
		exit(result);
	}
	else
		waitpid(data->pid, &result, 0);
	if (igint == 1 || sigquit == 1)
		return (sign.exit_code);
	result /= 256;
	return (result);
}


char	*child_dir(char *bin_cmd, char *cmd)
{
	char	*path;

	path = NULL;
	return (path);
}

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
		return (child_process(arg[0], arg, data, env)); 
	bin_cmd = ft_split(env->value, ':');
	if (!bin_cmd)
		return (ft_exit(ERR_SPLIT), FAILURE); // ptrt exit_failure
	if (!arg[0] && !bin_cmd[0])
		return (FAILURE);
	path = child_dir(bin_cmd[0] + 5, arg[0]);
	i_dir += 1;
	while (arg[i])
	
}
