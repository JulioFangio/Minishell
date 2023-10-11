/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/10 19:16:30 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// segfault if | error to do
// error for cd ls for exampl
int	main(int ac, char **av, char **env)
{
	t_data	data;

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
	free_and_close_data(&data, 1);
	return (data.result);
}
