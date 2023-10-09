/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:03:23 by jaristil          #+#    #+#             */
/*   Updated: 2023/10/09 17:25:41 by jaristil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* "wc -l" not work but wc -l yes for the PATH in child_dir 
*/
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
	if (ac != 1)
		return (FAILURE);
	run_shell_loop(&data);
	//free_and_close_data(&data);
	return (data.result);
}
