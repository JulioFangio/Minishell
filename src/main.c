/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:53 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	ft_bzero(&data, sizeof(t_data));
	if (env[0] == NULL)
		return (FAILURE);
	reset_to_initial_fd(&data);
	set_env(&data, env);
	data.export = export_env(NULL);
	if (ac != 1)
		return (FAILURE);
	run_shell_loop(&data);
	// while (data.exit == 0)
	// {
	// 	//parsing + signal
	// 	if (data.token && data.exit == 0)
	// 		// launch_minishell(&data);
	// 	data.token = free_token(data.token);
	// }
	// free_and_close(&data);
	return (data.result);
}
