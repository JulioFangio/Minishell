/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/21 16:40:11 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data		data;

	(void)ac;
	(void)av;
	if (env[0] == NULL)
		return (FAILURE);
	ft_bzero(&data, sizeof(t_data));
	data.in = dup(STDIN);
	data.out = dup(STDOUT);
	reset_to_initial_fd(&data);
	set_env(&data, env);
	if (ac != 1)
		return (FAILURE);
	run_shell_loop(&data);
	free_and_close_data(&data, 404);
	return (data.result);
}
