/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:15:22 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/11 16:20:07 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char *error)
{
	if (error)
		ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	child_error(char *path)
{
	struct stat	path_stat;
	int			fd;
	int			result;
	t_data		*data;

	data = NULL;
	data = recuperate_data(data);
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
	else if (!ft_strchr(path, '/'))
		ft_putendl_fd(ERR_CMD, STDERR);
	if (!ft_strchr(path, '/') || fd == -1)
		result = 127;
	else
		result = 126;
	ft_close_fd(fd);
	free_and_close_data(data, 35);
	free_env(data->env);
	return (result);
}
