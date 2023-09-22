/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:59:26 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/19 15:43:22 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*retrieves the path of the current working directory,
updates the "OLDPWD" environment variable with this path
(or adds it if it didn't exist).
It is used to update or add the "OLDPWD" environment variable
when a directory is changed.*/
int	new_oldpath(t_env *env)
{
	char	pwd[MAX_PATH];
	char	*oldpwd;

	if (getcwd(pwd, MAX_PATH) == NULL)
		return (FAILURE);
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	if (update_env(oldpwd, env) == 0)
		upgrade_env(oldpwd, env);
	free(oldpwd);
	oldpwd = NULL;
	return (SUCCESS);
}

/*retrieves the path of the current working directory,
and updates the "PWD" environment variable with this path*/
int	new_path(t_env *env)
{
	char	pwd[MAX_PATH];
	char	*new;

	if (getcwd(pwd, MAX_PATH) == NULL)
		return (FAILURE);
	new = ft_strjoin("PWD=", pwd);
	if (!new)
		return (FAILURE);
	while (ft_strncmp(env->value, "PWD=", 4) && env->next)
		env = env->next;
	free(env->value);
	env->value = new;
	return (SUCCESS);
}

/*handles directory change operations to the HOME directory
or the previous directory depending on the value of directory
0 is HOME and 1 is previous directory*/
int	handle_directory_change(int directory, t_env *env)
{
	int		res;
	char	*path;

	path = NULL;
	if (directory == 0)
	{
		new_oldpath(env);
		path = get_path(env, "HOME", 4);
		if (!path)
			return (ft_putendl_fd(ERR_HOME, STDERR), FAILURE);
	}
	else if (directory == 1)
	{
		path = get_oldpwd_path(path, env);
		if (!path)
			return (FAILURE);
		new_oldpath(env);
	}
	res = chdir(path);
	new_path(env);
	free(path);
	path = NULL;
	return (res);
}

void	show_error(char **arg)
{
	ft_putstr_fd("cd: ", STDERR);
	ft_putstr_fd(args[1], STDERR);
	if (args[2])
		ft_putendl_fd(": string not in pwd", STDERR);
	else
	{
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(strerror(errno), STDERR);
	}
}

/*handles the "cd" command according to the arguments supplied.
It can be used to change directories to the HOME directory,
the previous directory, a specific directory or to display an appropriate
error if the wrong argument is given.
It also updates the "OLDPWD" and "PWD" environment variables accordingly.*/
int	make_cd(char **arg, t_env *env)
{
	int	res;

	if (!arg[1])
		return (handle_directory_change(0, env));
	if (ft_strcmp(arg[1], ".") == 0)
		return (ft_putendl_fd(ERR_ARG, STDERR_FILENO), FAILURE);
	else if (ft_strcmp(arg[1], "-") == 0)
	{
		res = handle_directory_change(1, env);
		make_pwd(env);
	}
	else
	{
		new_oldpath(env);
		res = chdir(arg[1]);
		new_path(env);
		if (res < 0)
			res *= -1;
		if (res != 0)
			show_error(arg);
	}
	return (res);
}
