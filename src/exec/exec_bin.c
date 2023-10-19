/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:03:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/19 16:37:17 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	dup_files(t_data *data)
{
	if (data->fd_in > -1)
	{
		dup2(data->fd_in, STDIN_FILENO);
		close(data->fd_in);
		data->fd_in = -1;
	}
	if (data->fd_out > -1)
	{
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
		data->fd_out = -1;
	}
}

int	child_process(char *path, char **arg, t_data *data, t_env *env)
{
	int		result;
	char	*tmp;
	char	**env_tab;

	result = 0;
	dup_files(data);
	tmp = env_malloc(env);
	env_tab = ft_split(tmp, '\n');
	if (!env_tab)
		return (ft_exit(ERR_MALLOC), FAILURE);
	ft_memdel(tmp);
	if (ft_strchr(path, '/'))
		execve(path, arg, env_tab);
	result = ret_child(env_tab, path, result);
	clean_child_process(data, env, path, arg);
	// data->pid = fork();
	// if (data->pid == 0)
	// {
	// 	tmp = env_malloc(env);
	// 	env_tab = ft_split(tmp, '\n');
	// 	if (!env_tab)
	// 		return (ft_exit(ERR_MALLOC), FAILURE);
	// 	ft_memdel(tmp);
	// 	if (ft_strchr(path, '/'))
	// 		execve(path, arg, env_tab);
	// 	result = ret_child(env_tab, path, result);
	// 	clean_child_process(data, env, path, arg);
	// }
	// else if (data->check == 0)
	// 	waitpid(data->pid, NULL, 0);
	// else
	// {
	// 	waitpid(data->pid, &result, 0);
	// 	// exit(0);				// Wrong, it appeared you quit later
	// }
	result /= 256;
	// use WEXIT plutot que /256
	data->result = result;
	return (result);
}

char	*child_dir(char *bin_cmd, char *cmd)
{
	char		*path;
	struct stat	file_stat;
	char		*full_path;

	if (!bin_cmd || !cmd)
		return (NULL);
	path = NULL;
	full_path = strjoin_path(bin_cmd, cmd);
	if (!full_path)
		return (NULL);
	if (stat(full_path, &file_stat) == 0)
	{
		if (S_ISREG(file_stat.st_mode))
			path = ft_strdup(full_path);
	}
	ft_memdel(full_path);
	return (path);
}

int	exec_bin(char **arg, t_data *data, t_env *env)
{
	int		i_dir;
	int		ret;
	char	**bin_cmd;
	char	*path;

	i_dir = 0;
	ret = 0;
	//find path
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5) != 0)
		env = env->next;
	//env minimal
	if (!env || !env->next)
		return (child_process(arg[0], arg, data, env));
	bin_cmd = ft_split(env->value, ':');
	if (!bin_cmd || (!arg[0] && !bin_cmd[0]))
		return (FAILURE);
	path = child_dir(bin_cmd[0] + 5, arg[0]);
	i_dir += 1;
	while (arg[0] && bin_cmd[i_dir] && !path)
		path = child_dir(bin_cmd[i_dir++], arg[0]);
	free_tab(bin_cmd);
	// try binary
	//else ->absolut
	if (path)
		ret = child_process(path, arg, data, env);
	else
		ret = child_process(arg[0], arg, data, env);
	ft_memdel(path);
	return (ret);
}
