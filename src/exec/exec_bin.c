/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:03:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/09 19:33:41 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	child_process(char *path, char **arg, t_data *data, t_env *env)
{
	int		result;
	char	*tmp;
	char	**env_tab;

	result = 0;
	int i = 0;
	while (arg[i])
	{
		printf("THE RG %s\n", arg[i]);
		i++;
	}

	data->pid = fork();
	if (data->pid == 0)
	{
		tmp = env_malloc(env);
		//printf("THE TMP: \n%s\n", tmp);
		env_tab = ft_split(tmp, '\n');
//		int i = 0;
//		while (env_tab[i] != NULL)
//		{
//			printf("ENV_TAB:\n %s\n", env_tab[i]);
//			i++;
//		}
		if (!env_tab)
			return (ft_exit(ERR_MALLOC), FAILURE);
		ft_memdel(tmp);
		//printf("EXEC PATH\n: %s\n", path);
		// contient cat ici au lieu de contenir le chemin complet sans /
		if (ft_strchr(path, '/'))
		{
//			int i = 0;
//			while (arg[i])
//			{
//				printf("THE RG %s\n", arg[i]);
//				i++;
//			}
			printf("okkkkkk\n");
			execve(path, arg, env_tab);
		}
		result = ret_child(env_tab, path, result);
		clean_child_process(data, env, path, arg);
		exit(result);
	}
	else
		waitpid(data->pid, &result, 0);
	result /= 256;
	return (result);
}

char	*child_dir(char *bin_cmd, char *cmd)
{
	char		*path;
	struct stat	file_stat;
	char		*full_path;

	if (!bin_cmd || !cmd)
		return (NULL);
	//printf("BIN CMD THERE : %s\n", bin_cmd);
	//printf("CMD : %s\n", cmd);
	path = NULL;
	full_path = strjoin_path(bin_cmd, cmd);
	//printf("TRY PATH %s\n", full_path);
	if (!full_path)
		return (NULL);
	//printf("1st PATH %s\n", full_path);
	if (stat(full_path, &file_stat) == 0)
	{
	// check if file exist and if it's a regular file
		if (S_ISREG(file_stat.st_mode))
		{
			path = ft_strdup(full_path);
			//printf("2nd PATH %s\n", path);
		}
	}
	else
		ft_memdel(full_path);
	//printf("3rd PATH %s\n", path);
	return (path);
}

int	exec_bin(char **arg, t_data *data, t_env *env)
{
	int		i_dir;
	int		ret;
	char	**bin_cmd;
	char	*path;
	int		i;

	i_dir = 0;
	ret = 0;
	i = 0;
	while (env && env->value && ft_strncmp(env->value, "PATH=", 5 != 0))
		env = env->next;
	if (!env || !env->next)
		return (child_process(arg[0], arg, data, env));
	bin_cmd = ft_split(env->value, ':');
//	while (bin_cmd[i])
//	{
//		printf("THE VALUE : %s\n", bin_cmd[i]);
//		i++;
//	}
	if (!bin_cmd)
		return (ft_exit(ERR_SPLIT), FAILURE);
	if (!arg[0] && !bin_cmd[0])
		return (FAILURE);
	path = child_dir(bin_cmd[0] + 5, arg[0]);
	//printf("The PATH : %s\n", path);
	i_dir += 1;
	while (arg[0] && bin_cmd[i_dir] && !path)
	{
		path = child_dir(bin_cmd[i_dir++], arg[0]);
		//printf("THIS IS LAST PATH %s\n", path);
	}
	free_tab(bin_cmd);
	printf("PATH RECEIVED WHEN OK %s\n", path);
	if (path)
	{
		printf("PATH RECEIVED WHEN OK %s\n", path);
		ret = child_process(path, arg, data, env);
	}
	else
	{
		//printf("PATH RECEIVED WHEN OK %s\n", arg[0]);
		ret = child_process(arg[0], arg, data, env);
	}
	ft_memdel(path);
	return (ret);
}
