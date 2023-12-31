/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:19 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 16:59:38 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	make_pwd(t_data *data, t_env *env)
{
	char	pwd[MAX_PATH];

	if (data->fd_out == -1)
		data->fd_out = 1;
	(void)env;
	if (getcwd(pwd, MAX_PATH))
		ft_putendl_fd(pwd, data->fd_out);
	if (data->fd_out)
		data->fd_out = -1;
	return (FAILURE);
}
