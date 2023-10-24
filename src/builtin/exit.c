/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:48:05 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/24 20:47:11 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* result :
1 : general error
2 : invalid use of builtin
126 : cannot execute
127 : command not found
128 : invalid argument to exit (non positive integer)
128 + n : fatal error signal where n is signal number
255 : signal is not include between 0-255
*/
#include "../../includes/minishell.h"

int	str_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (FAILURE);
	while (str[i] == '+' || str[i] == '-')
		i += 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	make_exit(t_data *data, char **cmd)
{
	data->exit = 1;
	if (data->check == 0)
		ft_putendl_fd("exit", STDERR);
	if (cmd[1] && str_isnum(cmd[1]))
	{
		data->result = 128;
		ft_putstr_fd("exit:", STDERR);
		ft_putstr_fd(cmd[1], STDERR);
		ft_putendl_fd(ERR_INPUT_ARG, STDERR);
	}
	else if (cmd[1] && cmd[2])
	{
		data->result = 1;
		data->exit = 0;
		ft_putendl_fd(ERR_ARG, STDERR);
	}
	else if (cmd[1])
		data->result = ft_atoi(cmd[1]);
	secure_fds();
	return (data->result);
}
