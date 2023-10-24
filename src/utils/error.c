/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:15:22 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 18:57:50 by juduval          ###   ########.fr       */
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

int	child_error(char *path)
{
	int			fd;
	t_data		*data;

	data = NULL;
	fd = -1;
	data = recuperate_data(data);
	if (!ft_strchr(path, '/'))
		ft_putendl_fd(ERR_CMD, STDERR);
	if (!ft_strchr(path, '/') || fd == -1)
		data->result = 127;
	else
		data->result = 126;
	ft_close_fd(fd);
	free_token(data->free_token);
	return (free_env(&data->env), data->result);
}
