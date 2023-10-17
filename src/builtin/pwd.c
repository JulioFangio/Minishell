/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:19 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/17 15:53:15 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	make_pwd(t_data *data, t_env *env)
{
	char	pwd[MAX_PATH];
	int		fd;

	if (data->fd_out == -1)
		fd = 1;
	else
		fd = data->fd_out;
	(void)env;
	if (getcwd(pwd, MAX_PATH))
		return (ft_putendl_fd(pwd, fd), SUCCESS);
	return (FAILURE);
}
