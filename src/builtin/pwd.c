/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduval <juduval@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:19 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/13 22:42:37 by juduval          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	make_pwd(t_data *data, t_env *env)
{
	char	pwd[MAX_PATH];

	(void)env;
	if (getcwd(pwd, MAX_PATH))
		return (ft_putendl_fd(pwd, data->fd_out), SUCCESS);
	return (FAILURE);
}
