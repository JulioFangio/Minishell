/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:15:22 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/21 18:42:06 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char *error)
{
	if (error)
		ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	error_cd(char **args)
{
	ft_putstr_fd("cd: ", STDERR);
	ft_putstr_fd(args[1], STDERR);
	if (args[2])
	{
		ft_putendl_fd(": string not in pwd", STDERR);
	}
	else
	{
		ft_putendl_fd("", STDERR);
		perror("");
	}
}

// n'y vas pas quand pas une cmd mais /
int	child_error(char *path)
{
	struct stat	path_stat;
	int			fd;
	t_data		*data;

	data = NULL;
	fd = -1;
	data = recuperate_data(data);
	if (path)
		fd = open(path, O_WRONLY);
	if (stat(path, &path_stat) == 0)
	{
		if (S_ISDIR(path_stat.st_mode))
			ft_putendl_fd(ERR_DIR, STDERR);
		else if (fd != -1)
			ft_putendl_fd(ERR_OPEN, STDERR);
		else if (fd != -1)
			ft_putendl_fd(ERR_PERM, STDERR);
	}
	if (!ft_strchr(path, '/'))
		ft_putendl_fd(ERR_CMD, STDERR);
	if (!ft_strchr(path, '/') || fd == -1)
		data->result = 127;
	else
		data->result = 126;
	ft_close_fd(fd);
	free_and_close_data(data, 66);
	free_env(&data->env);
	return (data->result);
}
